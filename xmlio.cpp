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
        if(reader.readNextStartElement() && reader.name() == "root"){
            while(reader.readNextStartElement()) {

                const QXmlStreamAttributes attributo= reader.attributes();
                string nome= attributo.value("nome").toString().toStdString();
                string autore= attributo.value("autore").toString().toStdString();
                string descrizione= attributo.value("descrizione").toString().toStdString();
                string foto= attributo.value("foto").toString().toStdString();
                QString data= attributo.value("data").toString();
                MuseoItem* add=nullptr;
                if(reader.name()=="Documento")
                {
                    string categoria= attributo.value("categoria").toString().toStdString();
                    string testo= attributo.value("testo").toString().toStdString();

                    add=new DocumentItem(nome,autore,descrizione,foto,QDate::fromString(data,"dd.MM.yyyy"),DocumentItem::getEnum(categoria),testo);
                }else if(reader.name()=="Pittura")
                {
                    string categoria= attributo.value("categoria").toString().toStdString();
                    string soggetto= attributo.value("soggetto").toString().toStdString();
                    string movimento= attributo.value("movimento").toString().toStdString();

                    add=new PictureItem(nome,autore,descrizione,foto,QDate::fromString(data,"dd.MM.yyyy"),PictureItem::getEnum(categoria),soggetto,movimento);

                }else{
                    string categoria= attributo.value("categoria").toString().toStdString();
                    string soggetto= attributo.value("soggetto").toString().toStdString();
                    string materiale= attributo.value("materiale").toString().toStdString();

                    add=new StatueItem(nome,autore,descrizione,foto,QDate::fromString(data,"dd.MM.yyyy"),StatueItem::getEnum(categoria),soggetto,materiale);
                }
                q.push_back(add);
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
        writer.writeAttribute("foto",QString::fromStdString(it->getFoto()));
        writer.writeAttribute("data",(it->getData()).QDate::toString("dd.MM.yyyy"));
        if(tipo=="Statua"){
            const StatueItem* sit=static_cast<const StatueItem*>(it);
            writer.writeAttribute("materiale",QString::fromStdString(sit->getMateriale()));
            writer.writeAttribute("categoria",QString::fromStdString(sit->getCategoria()));
            writer.writeAttribute("soggetto",QString::fromStdString(sit->getSoggetto()));
        }else if(tipo=="Documento"){
            const DocumentItem* dit=static_cast<const DocumentItem*>(it);
            writer.writeAttribute("categoria",QString::fromStdString(dit->getCategoria()));
            writer.writeAttribute("soggetto",QString::fromStdString(dit->getTesto()));
        }else{
            const PictureItem* pit=static_cast<const PictureItem*>(it);
            writer.writeAttribute("materiale",QString::fromStdString(pit->getMovimento()));
            writer.writeAttribute("categoria",QString::fromStdString(pit->getCategoria()));
            writer.writeAttribute("soggetto",QString::fromStdString(pit->getSoggetto()));
        }
        cit++;
    }
    writer.writeEndElement();   // </root>
    writer.writeEndDocument();  // chiude eventuali tag lasciati aperti e aggiunge una riga vuota alla fine
    file.commit();
}

