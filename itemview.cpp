#include "itemview.h"
#include <QPushButton>
#include <QDate>
#include<QDateEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>


ItemView::ItemView(QWidget *parent) : QWidget(parent)
{
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
    //setFixedSize();
    tipoLabel=new QLabel("Tipo dell'oggetto:",this);
    nomeLabel=new QLabel("Nome:",this);
    autoreLabel=new QLabel("Autore:",this);
    descLabel=new QLabel("Descrizione",this);
    dataLabel=new QLabel("Data ritrovamento:",this);


    //bookitem
    dataLibroLabel=new QLabel("Data pubblicazione del libro:",this);
    dataLibro=new QLineEdit(this);
    prefazione=new QLineEdit(this);
    prefazioneLabel =new QLabel("Prefazione del libro:",this);

    copertinaLabel =new QLabel("Foto della copertina",this);


    //letterItem

    dataLetteraLabel=new QLabel("Data della lettera",this);
    dataLettera=new QLineEdit(this);
    destinatarioLabel=new QLabel("Destinatario della lettera",this);
    destinatario=new QLineEdit(this);
    testoLabel=new QLabel("Testo della lettera:");
    testo=new QLineEdit(this);

    //magazineItem

    dataMagazineLabel=new QLabel("Data uscita del periodico",this);
    dataMagazine=new QLineEdit(this);

    primaPaginaLabel=new QLabel("Prima pagina del periodico:",this);



    catSLabel=new QLabel("Categoria statua:",this);
    catPLabel=new QLabel("Categoria pittura:",this);
    catMLabel=new QLabel("Tipo di periodico:",this);

    materialeLabel=new QLabel("Materiale dell'opera:",this);
    soggettoSLabel=new QLabel("Soggetto della statua:",this);
    soggettoPLabel=new QLabel("Soggetto del dipinto:",this);
    movimentoLabel=new QLabel("Movimento artistico:",this);


    museumType=new QLabel(this);
    nome=new QLineEdit(this);
    autore=new QLineEdit(this);
    desc=new QLineEdit(this);
    data=new QLineEdit(this);

    materiale=new QLineEdit(this);
    soggettoS=new QLineEdit(this);
    soggettoP=new QLineEdit(this);
    movimento=new QLineEdit(this);
    inserisci=new QPushButton("Inserisci",this);


    QVBoxLayout* mainLayout = new QVBoxLayout(this);


    //mainLayout->setGeometry(QRect(0,0,450,550));
    QHBoxLayout* tipoLayout=new QHBoxLayout();
    QVBoxLayout* attributiLayout = new QVBoxLayout();
    QHBoxLayout* nomeLayout = new QHBoxLayout();
    QHBoxLayout* autoreLayout = new QHBoxLayout();
    QHBoxLayout* descLayout = new QHBoxLayout();
    QHBoxLayout* dataLayout = new QHBoxLayout();

    QHBoxLayout* catMLayout = new QHBoxLayout();
    QHBoxLayout* catSLayout = new QHBoxLayout();
    QHBoxLayout* catPLayout = new QHBoxLayout();

    QHBoxLayout* dataLibroLayout = new QHBoxLayout();
    QHBoxLayout* prefazioneLayout = new QHBoxLayout();
    QHBoxLayout* copertinaLayout = new QHBoxLayout();

    QHBoxLayout* dataMagazineLayout = new QHBoxLayout();
    QHBoxLayout* primaPaginaLayout = new QHBoxLayout();

    QHBoxLayout* dataLetteraLayout = new QHBoxLayout();
    QHBoxLayout* testoLayout = new QHBoxLayout();
    QHBoxLayout* destinatarioLayout = new QHBoxLayout();

    QHBoxLayout* soggettoSLayout = new QHBoxLayout();
    QHBoxLayout* soggettoPLayout = new QHBoxLayout();
    QHBoxLayout* movimentoLayout = new QHBoxLayout();
    QHBoxLayout* materialeLayout = new QHBoxLayout();

    QHBoxLayout* buttonLayout=new QHBoxLayout();

    tipoLayout->addWidget(tipoLabel);
    tipoLayout->addWidget(museumType);
    nomeLayout->addWidget(nomeLabel);
    nomeLayout->addWidget(nome);
    autoreLayout->addWidget(autoreLabel);
    autoreLayout->addWidget(autore);
    descLayout->addWidget(descLabel);
    descLayout->addWidget(desc);
    dataLayout->addWidget(dataLabel);
    dataLayout->addWidget(data);


    catMLayout->addWidget(catMLabel);
    dataLibroLayout->addWidget(dataLibroLabel);
    dataLibroLayout->addWidget(dataLibro);
    prefazioneLayout->addWidget(prefazioneLabel);
    prefazioneLayout->addWidget(prefazione);
    copertinaLayout->addWidget(copertinaLabel);
    //copertinaLayout->addWidget(copertina);
    dataMagazineLayout->addWidget(dataMagazineLabel);
    dataMagazineLayout->addWidget(dataMagazine);
    primaPaginaLayout->addWidget(primaPaginaLabel);
    //primaPaginaLayout->addWidget(prefazione);
    dataLetteraLayout->addWidget(dataLetteraLabel);
    dataLetteraLayout->addWidget(dataLettera);
    destinatarioLayout->addWidget(destinatarioLabel);
    destinatarioLayout->addWidget(destinatario);


    catSLayout->addWidget(catSLabel);
    catPLayout->addWidget(catPLabel);
    testoLayout->addWidget(testoLabel);
    testoLayout->addWidget(testo);
    soggettoSLayout->addWidget(soggettoSLabel);
    soggettoSLayout->addWidget(soggettoS);
    soggettoPLayout->addWidget(soggettoPLabel);
    soggettoPLayout->addWidget(soggettoP);
    movimentoLayout->addWidget(movimentoLabel);
    movimentoLayout->addWidget(movimento);
    materialeLayout->addWidget(materialeLabel);
    materialeLayout->addWidget(materiale);

    buttonLayout->addWidget(inserisci);
    //buttonLayout->addWidget(annulla);

    attributiLayout->addLayout(nomeLayout);
    attributiLayout->addLayout(autoreLayout);
    attributiLayout->addLayout(descLayout);
    attributiLayout->addLayout(dataLayout);

    attributiLayout->addLayout(catMLayout);
    attributiLayout->addLayout(dataLibroLayout);
    attributiLayout->addLayout(prefazioneLayout);
    attributiLayout->addLayout(copertinaLayout);
    attributiLayout->addLayout(dataMagazineLayout);
    attributiLayout->addLayout(primaPaginaLayout);
    attributiLayout->addLayout(dataLetteraLayout);
    attributiLayout->addLayout(destinatarioLayout);


    attributiLayout->addLayout(catSLayout);
    attributiLayout->addLayout(catPLayout);
    attributiLayout->addLayout(testoLayout);
    attributiLayout->addLayout(soggettoSLayout);
    attributiLayout->addLayout(soggettoPLayout);
    attributiLayout->addLayout(movimentoLayout);
    attributiLayout->addLayout(materialeLayout);
    attributiLayout->addLayout(buttonLayout);

    mainLayout->addLayout(tipoLayout);
    mainLayout->addLayout(attributiLayout);
    /*mainLayout->addLayout(autoreLayout);
    mainLayout->addLayout(descLayout);
    mainLayout->addLayout(dataLayout);
    mainLayout->addLayout(catDLayout);
    mainLayout->addLayout(catSLayout);
    mainLayout->addLayout(catPLayout);
    mainLayout->addLayout(testoLayout);
    mainLayout->addLayout(soggettoSLayout);
    mainLayout->addLayout(soggettoPLayout);
    mainLayout->addLayout(movimentoLayout);
    mainLayout->addLayout(materialeLayout);*/


    //Magazine
    catMLabel->setVisible(false);
    catMBox->setVisible(false);
    dataMagazineLabel->setVisible(false);
    dataMagazine->setVisible(false);
    primaPaginaLabel->setVisible(false);
    //Libro
    dataLibroLabel->setVisible(false);
    dataLibro->setVisible(false);
    prefazioneLabel->setVisible(false);
    prefazione->setVisible(false);
    copertinaLabel->setVisible(false);
    //Lettera
    dataLetteraLabel->setVisible(false);
    dataLettera->setVisible(false);
    destinatarioLabel->setVisible(false);
    destinatario->setVisible(false);
    testoLabel->setVisible(false);
    testo->setVisible(false);
    //Dipinto
    catPLabel->setVisible(false);
    soggettoPLabel->setVisible(false);
    soggettoP->setVisible(false);
    movimentoLabel->setVisible(false);
    movimento->setVisible(false);


    connect(inserisci, SIGNAL(clicked()), this, SIGNAL(inserito()));
    connect(museumType,SIGNAL(currentTextChanged(QString)),this,SLOT(setView(QString)));

}

/*
std::string ItemView::getNome() const
{
    return nome->text().toStdString();
}

std::string ItemView::getAutore() const
{
    return autore->text().toStdString();
}

std::string ItemView::getData() const
{
    return data->text().toStdString();
}

std::string ItemView::getDescrizione() const
{
    return desc->text().toStdString();
}

std::string ItemView::getDataMagazine() const
{
    return dataMagazine->text().toStdString();
}

std::string ItemView::getDataLibro() const
{
    return dataLibro->text().toStdString();
}

std::string ItemView::getDataLettera() const
{
    return dataLettera->text().toStdString();
}

std::string ItemView::getPrefazione() const
{
    return prefazione->text().toStdString();
}

std::string ItemView::getDestinatario() const
{
    return destinatario->text().toStdString();
}

std::string ItemView::getCatM() const
{
    return catMBox->currentText().toStdString();
}

std::string ItemView::getCatS() const
{
    return catSBox->currentText().toStdString();
}

std::string ItemView::getCatP() const
{
    return catPBox->currentText().toStdString();
}

std::string ItemView::getSoggettoS() const
{
    return soggettoS->text().toStdString();
}

std::string ItemView::getSoggettoP() const
{
    return soggettoP->text().toStdString();
}

std::string ItemView::getMovimento() const
{
    return movimento->text().toStdString();
}

std::string ItemView::getMateriale() const
{
    return materiale->text().toStdString();
}

std::string ItemView::getTesto() const
{
    return testo->text().toStdString();
}

void ItemView::setView(QString s)
{
    //Statua
    catSLabel->setVisible(false);
    soggettoSLabel->setVisible(false);
    soggettoS->setVisible(false);
    materialeLabel->setVisible(false);
    materiale->setVisible(false);
    //Magazine
    catMLabel->setVisible(false);
    dataMagazineLabel->setVisible(false);
    dataMagazine->setVisible(false);
    primaPaginaLabel->setVisible(false);
    //Libro
    dataLibroLabel->setVisible(false);
    dataLibro->setVisible(false);
    prefazioneLabel->setVisible(false);
    prefazione->setVisible(false);
    copertinaLabel->setVisible(false);
    //Lettera
    dataLetteraLabel->setVisible(false);
    dataLettera->setVisible(false);
    destinatarioLabel->setVisible(false);
    destinatario->setVisible(false);
    testoLabel->setVisible(false);
    testo->setVisible(false);
    //Dipinto
    catPLabel->setVisible(false);
    catPBox->setVisible(false);
    soggettoPLabel->setVisible(false);
    soggettoP->setVisible(false);
    movimentoLabel->setVisible(false);
    movimento->setVisible(false);

    if(s=="Libro"){
        dataLibroLabel->setVisible(true);
        dataLibro->setVisible(true);
        prefazioneLabel->setVisible(true);
        prefazione->setVisible(true);
        copertinaLabel->setVisible(true);
    }else if(s=="Magazine"){
        catMLabel->setVisible(true);
        catMBox->setVisible(true);
        dataMagazineLabel->setVisible(true);
        dataMagazine->setVisible(true);
        primaPaginaLabel->setVisible(true);
    }else if(s=="Lettera"){
        dataLetteraLabel->setVisible(true);
        dataLettera->setVisible(true);
        destinatarioLabel->setVisible(true);
        destinatario->setVisible(true);
        testoLabel->setVisible(true);
        testo->setVisible(true);
    }else if(s=="Scultura"){
        catSLabel->setVisible(true);
        catSBox->setVisible(true);
        soggettoSLabel->setVisible(true);
        soggettoS->setVisible(true);
        materialeLabel->setVisible(true);
        materiale->setVisible(true);
    }else if(s=="Dipinto"){
        catPLabel->setVisible(true);
        catPBox->setVisible(true);
        soggettoPLabel->setVisible(true);
        soggettoP->setVisible(true);
        movimentoLabel->setVisible(true);
        movimento->setVisible(true);
    }


    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
    //campi item
    QPushButton* exit= new QPushButton("Chiudi",this);

    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(exit,SIGNAL(clicked()),this,SLOT(close()));
}*/
