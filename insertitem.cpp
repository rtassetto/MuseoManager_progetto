#include "insertitem.h"


InsertItem::InsertItem(QWidget *parent): QWidget(parent)/*,autoreLabel(new QLabel("Autore:",this)), descLabel(new QLabel("Descrizione",this)),dataLabel(new QLabel("Data ritrovamento:",this)),
    catDLabel(new QLabel("Categoria documento:",this)),catSLabel(new QLabel("Categoria statua:",this)),catPLabel(new QLabel("Categoria pittura:",this)),testoLabel(new QLabel("Testo del documento:",this)),
    materialeLabel(new QLabel("Materiale dell'opera:")),soggettoSLabel(new QLabel("Soggetto della statua:")),soggettoPLabel(new QLabel("Soggetto del dipinto:",this)),movimentoLabel(new QLabel("Movimento artistico:",this)),
    nome(new QLineEdit(this)),autore(new QLineEdit(this)), desc(new QLineEdit(this)), data(new QDateEdit(this)),catDBox(new QComboBox(this)), testo(new QLineEdit(this)),catSBox(new QComboBox(this)),
    materiale(new QLineEdit(this)),soggettoS(new QLineEdit(this)),catPBox(new QComboBox(this)),soggettoP(new QLineEdit(this)),movimento(new QLineEdit(this)),inserisci(new QPushButton("Inserisci",this)),annulla(new QPushButton("Annullla",this))
*/{
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    //setFixedSize();
    tipoLabel=new QLabel("Tipo dell'oggetto:",this);
    nomeLabel=new QLabel("Nome:",this);
    autoreLabel=new QLabel("Autore:",this);
    descLabel=new QLabel("Descrizione",this);
    dataLabel=new QLabel("Data ritrovamento:",this);


    //bookitem
    dataLibroLabel=new QLabel("Data pubblicazione del libro:",this);
    dataLibro=new QDateEdit(this);
    prefazione=new QLineEdit(this);
    prefazioneLabel =new QLabel("Prefazione del libro:",this);

    copertinaLabel =new QLabel("Foto della copertina",this);


    //letterItem

    dataLetteraLabel=new QLabel("Data della lettera",this);
    dataLettera=new QDateEdit(this);
    destinatarioLabel=new QLabel("Destinatario della lettera",this);
    destinatario=new QLineEdit(this);
    testoLabel=new QLabel("Testo della lettera:");
    testo=new QLineEdit(this);

    //magazineItem

    dataMagazineLabel=new QLabel("Data uscita del periodico",this);
    dataMagazine=new QDateEdit(this);
    catMBox=new QComboBox(this);

    primaPaginaLabel=new QLabel("Prima pagina del periodico:",this);



    catSLabel=new QLabel("Categoria statua:",this);
    catPLabel=new QLabel("Categoria pittura:",this);
    catMLabel=new QLabel("Tipo di periodico:",this);

    materialeLabel=new QLabel("Materiale dell'opera:",this);
    soggettoSLabel=new QLabel("Soggetto della statua:",this);
    soggettoPLabel=new QLabel("Soggetto del dipinto:",this);
    movimentoLabel=new QLabel("Movimento artistico:",this);





    museumType=new QComboBox(this);
    nome=new QLineEdit(this);
    autore=new QLineEdit(this);
    desc=new QLineEdit(this);
    data=new QDateEdit(this);

    catSBox=new QComboBox(this);
    materiale=new QLineEdit(this);
    soggettoS=new QLineEdit(this);
    catPBox=new QComboBox(this);
    soggettoP=new QLineEdit(this);
    movimento=new QLineEdit(this);
    inserisci=new QPushButton("Inserisci",this);


    catMBox->addItem("Giornale");
    catMBox->addItem("Quotidiano");
    catMBox->addItem("Rivista");
    catMBox->addItem("Almanacco");

    catSBox->addItem("Busto");
    catSBox->addItem("Bassorilievo");
    catSBox->addItem("Altorilievo");
    catSBox->addItem("Scultura equestre");

    catPBox->addItem("Ritratto");
    catPBox->addItem("Paesaggio");
    catPBox->addItem("Natura morta");
    catPBox->addItem("Fotografia");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    museumType->setFocus();
    museumType->addItem(QIcon(":/data/images/statueicon.png"),"Scultura");
    museumType->addItem(QIcon(":/data/images/painticon.png"),"Dipinto");
    museumType->addItem(QIcon(":/data/images/book.png"),"Libro");
    museumType->addItem(QIcon(":/data/images/magazine.png"),"Magazine");
    museumType->addItem(QIcon(":/data/images/letter.png"),"Lettera");

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
    catMLayout->addWidget(catMBox);
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
    catSLayout->addWidget(catSBox);
    catPLayout->addWidget(catPLabel);
    catPLayout->addWidget(catPBox);
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
    catPBox->setVisible(false);
    soggettoPLabel->setVisible(false);
    soggettoP->setVisible(false);
    movimentoLabel->setVisible(false);
    movimento->setVisible(false);


    connect(inserisci, SIGNAL(clicked()), this, SIGNAL(inserito()));
    //connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
    connect(museumType,SIGNAL(currentTextChanged(QString)),this,SLOT(setView(QString)));

}


std::string InsertItem::getNome() const
{
    return nome->text().toStdString();
}

std::string InsertItem::getAutore() const
{
    return autore->text().toStdString();
}

std::string InsertItem::getData() const
{
    return data->text().toStdString();
}

std::string InsertItem::getDescrizione() const
{
    return desc->text().toStdString();
}

std::string InsertItem::getDataMagazine() const
{
    return dataMagazine->text().toStdString();
}

std::string InsertItem::getDataLibro() const
{
    return dataLibro->text().toStdString();
}

std::string InsertItem::getDataLettera() const
{
    return dataLettera->text().toStdString();
}

std::string InsertItem::getPrefazione() const
{
    return prefazione->text().toStdString();
}

std::string InsertItem::getDestinatario() const
{
    return destinatario->text().toStdString();
}

std::string InsertItem::getCatM() const
{
    return catMBox->currentText().toStdString();
}

std::string InsertItem::getCatS() const
{
    return catSBox->currentText().toStdString();
}

std::string InsertItem::getCatP() const
{
    return catPBox->currentText().toStdString();
}

std::string InsertItem::getSoggettoS() const
{
    return soggettoS->text().toStdString();
}

std::string InsertItem::getSoggettoP() const
{
    return soggettoP->text().toStdString();
}

std::string InsertItem::getMovimento() const
{
    return movimento->text().toStdString();
}

std::string InsertItem::getMateriale() const
{
    return materiale->text().toStdString();
}

std::string InsertItem::getTesto() const
{
    return testo->text().toStdString();
}

void InsertItem::setView(QString s)
{
    //Statua
    catSLabel->setVisible(false);
    catSBox->setVisible(false);
    soggettoSLabel->setVisible(false);
    soggettoS->setVisible(false);
    materialeLabel->setVisible(false);
    materiale->setVisible(false);
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
}


