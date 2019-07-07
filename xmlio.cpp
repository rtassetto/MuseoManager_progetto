#include "xmlio.h"
#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>

XmlIO::XmlIO(const std::string & s):filename(s){}

Qontainer<MuseoItem *> XmlIO::read() const
{
    Qontainer<MuseoItem *> q;
        QFile file(QString::fromStdString(filename));
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox box(QMessageBox::Warning, "Errore di apertura", "Non è stato possibile aprire il file", QMessageBox::Ok);
            return q;
        }
        QXmlStreamReader reader(&file); // QIODevice*
        if(reader.readNextStartElement()){
            if(reader.name() == "root"){
                while(reader.readNextStartElement()) {

                    const QXmlStreamAttributes attributo= reader.attributes();
                    string nome= attributo.value("nome").toString().toStdString();
                    string autore= attributo.value("autore").toString().toStdString();
                    string descrizione= attributo.value("descrizione").toString().toStdString();
                    QString data= attributo.value("dataScoperta").toString();
                    MuseoItem* add=nullptr;
                    if(reader.name()=="Libro")
                    {
                        QString dataDocumento=attributo.value("dataDocumento").toString();
                        string prefazione= attributo.value("prefazione").toString().toStdString();
                        string copertina= attributo.value("copertina").toString().toStdString();


                        add=new BookItem(nome,autore,descrizione,QDate::fromString(data,"dd.MM.yyyy"),QDate::fromString(dataDocumento,"dd.MM.yyyy"),prefazione,copertina);
                    }else if(reader.name()=="Magazine")
                    {
                        QString dataDocumento=attributo.value("dataDocumento").toString();
                        string primaPagina= attributo.value("primaPagina").toString().toStdString();
                        string categoria= attributo.value("categoria").toString().toStdString();

                        add=new MagazineItem(nome,autore,descrizione,QDate::fromString(data,"dd.MM.yyyy"),QDate::fromString(dataDocumento,"dd.MM.yyyy"),primaPagina,MagazineItem::getEnumM(categoria));
                    }else if(reader.name()=="Lettera")
                    {
                        QString dataDocumento=attributo.value("dataDocumento").toString();
                        string destinatario= attributo.value("destinatario").toString().toStdString();
                        string testo= attributo.value("testo").toString().toStdString();

                        add=new LetterItem(nome,autore,descrizione,QDate::fromString(data,"dd.MM.yyyy"),QDate::fromString(dataDocumento,"dd.MM.yyyy"),destinatario,testo);
                    }else if(reader.name()=="Pittura")
                    {
                        string categoria= attributo.value("categoria").toString().toStdString();
                        string soggetto= attributo.value("soggetto").toString().toStdString();
                        string movimento= attributo.value("movimento").toString().toStdString();
                        string foto= attributo.value("foto").toString().toStdString();

                        add=new PictureItem(nome,autore,descrizione,QDate::fromString(data,"dd.MM.yyyy"),PictureItem::getEnumP(categoria),soggetto,movimento,foto);

                    }else{
                        string categoria= attributo.value("categoria").toString().toStdString();
                        string soggetto= attributo.value("soggetto").toString().toStdString();
                        string materiale= attributo.value("materiale").toString().toStdString();
                        string foto= attributo.value("foto").toString().toStdString();

                        add=new StatueItem(nome,autore,descrizione,QDate::fromString(data,"dd.MM.yyyy"),StatueItem::getEnumS(categoria),soggetto,materiale,foto);
                    }
                    if(add!=nullptr){
                        q.push_back(add);
                    }
                    else throw std::exception();

                    if(!reader.isEndDocument())
                        reader.skipCurrentElement();
                }
            }
        }
    file.close();
    return q;
}

void XmlIO::write(const Qontainer<MuseoItem *> & q) const
{
    QSaveFile file(QString::fromStdString(filename));
    if(!file.open(QIODevice::WriteOnly)) {
        throw std::exception();
    }
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true); // Per leggibilità del file XML
    writer.writeStartDocument();    // Scrive le intestazioni XML
    writer.writeStartElement("root");
    auto cit = q.begin();
    while(cit!= q.end()) {
        const MuseoItem* it=*cit;
        const QString tipo=QString::fromStdString(it->getTipo());
        writer.writeEmptyElement(tipo);
        writer.writeAttribute("nome",QString::fromStdString(it->getNome()));
        writer.writeAttribute("autore",QString::fromStdString(it->getAutore()));
        writer.writeAttribute("descrizione",QString::fromStdString(it->getDescrizione()));
        writer.writeAttribute("data",(it->getData()).QDate::toString("dd.MM.yyyy"));
        if(tipo=="Statua"){
            const StatueItem* sit=static_cast<const StatueItem*>(it);
            writer.writeAttribute("categoria",QString::fromStdString(sit->getCategoriaS()));
            writer.writeAttribute("soggetto",QString::fromStdString(sit->getSoggetto()));
            writer.writeAttribute("materiale",QString::fromStdString(sit->getMateriale()));
            writer.writeAttribute("foto",QString::fromStdString(sit->getFotoS()));
        }else if(tipo=="Libro"){
            const BookItem* lit=static_cast<const BookItem*>(it);
            writer.writeAttribute("data",(lit->getDataDocumento()).QDate::toString("dd.MM.yyyy"));
            writer.writeAttribute("prefazione",QString::fromStdString(lit->getPrefazione()));
            writer.writeAttribute("copertina",QString::fromStdString(lit->getCopertina()));

        }else if(tipo=="Magazine"){
            const MagazineItem* mit=static_cast<const MagazineItem*>(it);
            writer.writeAttribute("data",(mit->getDataDocumento()).QDate::toString("dd.MM.yyyy"));
            writer.writeAttribute("primaPagina",QString::fromStdString(mit->getPrimaPagina()));
            writer.writeAttribute("categoria",QString::fromStdString(mit->getCategoriaM()));

        }else if(tipo=="Lettera"){
            const LetterItem* lit=static_cast<const LetterItem*>(it);
            writer.writeAttribute("data",(lit->getDataDocumento()).QDate::toString("dd.MM.yyyy"));
            writer.writeAttribute("destinatario",QString::fromStdString(lit->getDestinatario()));
            writer.writeAttribute("testo",QString::fromStdString(lit->getTesto()));

        }else{
            const PictureItem* pit=static_cast<const PictureItem*>(it);
            writer.writeAttribute("categoria",QString::fromStdString(pit->getCategoriaP()));
            writer.writeAttribute("soggetto",QString::fromStdString(pit->getSoggetto()));
            writer.writeAttribute("movimento",QString::fromStdString(pit->getMovimento()));
            writer.writeAttribute("foto",QString::fromStdString(pit->getFotoP()));
        }
        cit++;
    }
    writer.writeEndElement();   // </root>
    writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine
    file.commit();
}

