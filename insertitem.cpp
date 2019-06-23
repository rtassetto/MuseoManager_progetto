#include "insertitem.h"
#include <QGroupBox>

InsertItem::InsertItem(QWidget *parent): QWidget(parent)/*,autoreLabel(new QLabel("Autore:",this)), descLabel(new QLabel("Descrizione",this)),dataLabel(new QLabel("Data ritrovamento:",this)),
    catDLabel(new QLabel("Categoria documento:",this)),catSLabel(new QLabel("Categoria statua:",this)),catPLabel(new QLabel("Categoria pittura:",this)),testoLabel(new QLabel("Testo del documento:",this)),
    materialeLabel(new QLabel("Materiale dell'opera:")),soggettoSLabel(new QLabel("Soggetto della statua:")),soggettoPLabel(new QLabel("Soggetto del dipinto:",this)),movimentoLabel(new QLabel("Movimento artistico:",this)),
    nome(new QLineEdit(this)),autore(new QLineEdit(this)), desc(new QLineEdit(this)), data(new QDateEdit(this)),catDBox(new QComboBox(this)), testo(new QLineEdit(this)),catSBox(new QComboBox(this)),
    materiale(new QLineEdit(this)),soggettoS(new QLineEdit(this)),catPBox(new QComboBox(this)),soggettoP(new QLineEdit(this)),movimento(new QLineEdit(this)),inserisci(new QPushButton("Inserisci",this)),annulla(new QPushButton("Annullla",this))
*/{
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
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
    copertinaButton=new QPushButton("Aggiungi immagine",this);
    copertinaPath=new QLabel(this);


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
    primaPaginaPath=new QLabel(this);
    primaPaginaButton=new QPushButton("Aggiungi immagine",this);



    catSLabel=new QLabel("Categoria statua:",this);
    catPLabel=new QLabel("Categoria pittura:",this);
    catMLabel=new QLabel("Tipo di periodico:",this);

    materialeLabel=new QLabel("Materiale dell'opera:",this);
    soggettoSLabel=new QLabel("Soggetto della statua:",this);
    soggettoPLabel=new QLabel("Soggetto del dipinto:",this);
    movimentoLabel=new QLabel("Movimento artistico:",this);

    fotoSLabel=new QLabel("Foto dell'opera:",this);
    fotoSPath=new QLabel(this);
    fotoSButton=new QPushButton("Aggiungi immagine",this);
    fotoPLabel=new QLabel("Foto dell'opera:",this);
    fotoPPath=new QLabel(this);
    fotoPButton=new QPushButton("Aggiungi immagine",this);



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
    reset=new QPushButton("Reset",this);

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

    //QGroupBox* group=new QGroupBox("Inserisci un nuovo oggetto",this);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    museumType->setFocus();
    museumType->addItem(QIcon(":/data/images/statueicon.png"),"Scultura");
    museumType->addItem(QIcon(":/data/images/painticon.png"),"Dipinto");
    museumType->addItem(QIcon(":/data/images/book.png"),"Libro");
    museumType->addItem(QIcon(":/data/images/magazine.png"),"Magazine");
    museumType->addItem(QIcon(":/data/images/letter.png"),"Lettera");


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
    QHBoxLayout* fotoPLayout = new QHBoxLayout();
    QHBoxLayout* fotoSLayout = new QHBoxLayout();
    QHBoxLayout* movimentoLayout = new QHBoxLayout();
    QHBoxLayout* materialeLayout = new QHBoxLayout();

    QVBoxLayout* copertinaPathLayout=new QVBoxLayout();
    QVBoxLayout* primaPaginaPathLayout=new QVBoxLayout();
    QVBoxLayout* fotoSPathLayout=new QVBoxLayout();
    QVBoxLayout* fotoPPathLayout=new QVBoxLayout();

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


    fotoSLayout->addWidget(fotoSLabel);
    fotoSLayout->addLayout(fotoSPathLayout);
    fotoSPathLayout->addWidget(fotoSButton);
    fotoSPathLayout->addWidget(fotoSPath);

    fotoPLayout->addWidget(fotoPLabel);
    fotoPLayout->addLayout(fotoPPathLayout);
    fotoPPathLayout->addWidget(fotoPButton);
    fotoPPathLayout->addWidget(fotoPPath);

    catMLayout->addWidget(catMLabel);
    catMLayout->addWidget(catMBox);
    dataLibroLayout->addWidget(dataLibroLabel);
    dataLibroLayout->addWidget(dataLibro);
    prefazioneLayout->addWidget(prefazioneLabel);
    prefazioneLayout->addWidget(prefazione);

    copertinaLayout->addWidget(copertinaLabel);
    copertinaLayout->addLayout(copertinaPathLayout);
    copertinaPathLayout->addWidget(copertinaButton);
    copertinaPathLayout->addWidget(copertinaPath);
    dataMagazineLayout->addWidget(dataMagazineLabel);
    dataMagazineLayout->addWidget(dataMagazine);

    primaPaginaLayout->addWidget(primaPaginaLabel);
    primaPaginaLayout->addLayout(primaPaginaPathLayout);
    primaPaginaPathLayout->addWidget(primaPaginaButton);
    primaPaginaPathLayout->addWidget(primaPaginaPath);
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
    buttonLayout->addWidget(reset);

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
    attributiLayout->addLayout(fotoPLayout);
    attributiLayout->addLayout(fotoSLayout);
    attributiLayout->addLayout(buttonLayout);

    mainLayout->addLayout(tipoLayout);
    mainLayout->addLayout(attributiLayout);
    //group->setLayout(mainLayout);
    /*mainLayout->addLayout(autoreLayout);
    mainLayout->addLayout(descLayout);
    mainLayout->addLayout(dataLayout);
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
    primaPaginaButton->setVisible(false);
    primaPaginaPath->setVisible(false);
    //Libro
    dataLibroLabel->setVisible(false);
    dataLibro->setVisible(false);
    prefazioneLabel->setVisible(false);
    prefazione->setVisible(false);
    copertinaLabel->setVisible(false);
    copertinaButton->setVisible(false);
    copertinaPath->setVisible(false);
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
    fotoPButton->setVisible(false);
    fotoPLabel->setVisible(false);
    fotoPPath->setVisible(false);


    connect(inserisci, SIGNAL(clicked(bool)), this, SIGNAL(inserito()));
    connect(reset,SIGNAL(clicked(bool)),this,SLOT(clearField()));
    connect(museumType,SIGNAL(currentTextChanged(QString)),this,SLOT(setView(QString)));
    connect(copertinaButton,SIGNAL(clicked()),this,SLOT(addCopertina()));
    connect(primaPaginaButton,SIGNAL(clicked()),this,SLOT(addPrimaPagina()));
    connect(fotoPButton,SIGNAL(clicked()),this,SLOT(addFotoP()));
    connect(fotoSButton,SIGNAL(clicked()),this,SLOT(addFotoS()));

}

std::string InsertItem::getTipo() const
{
    return museumType->currentText().toStdString();
}

void InsertItem::clearField(){
    museumType->setCurrentIndex(0);
    nome->setText("");
    autore->setText("");
    desc->setText("");
    //data->setDate(QDate(0,1,1));
    fotoSLabel->clear();
    fotoSLabel->setText("Foto dell'opera");
    fotoPLabel->clear();
    fotoPLabel->setText("Foto dell'opera");
    fotoSPath->clear();
    fotoPPath->clear();
    catSBox->setCurrentIndex(0);
    materiale->setText("");
    soggettoS->setText("");
    catPBox->setCurrentIndex(0);
    soggettoP->setText("");
    movimento->setText("");
}

void InsertItem::addCopertina(){
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    copertinaLabel->setPixmap(QPixmap(file));
    copertinaLabel->setScaledContents(true);
    copertinaPath->setText(file);
}
void InsertItem::addPrimaPagina(){
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    primaPaginaLabel->setPixmap(QPixmap(file));
    primaPaginaLabel->setScaledContents(true);
    primaPaginaPath->setText(file);
}
void InsertItem::addFotoP(){
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    fotoPLabel->setPixmap(QPixmap(file));
    fotoPLabel->setScaledContents(true);
    fotoPPath->setText(file);
}

void InsertItem::addFotoS(){
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    fotoSLabel->setPixmap(QPixmap(file));
    fotoSLabel->setScaledContents(true);
    fotoSPath->setText(file);
}



std::string InsertItem::getNome() const
{
    return nome->text().toStdString();
}

std::string InsertItem::getAutore() const
{
    return autore->text().toStdString();
}

QDate InsertItem::getData() const
{
    return data->date();
}

std::string InsertItem::getDescrizione() const
{
    return desc->text().toStdString();
}

QDate InsertItem::getDataMagazine() const
{
    return dataMagazine->date();
}

QDate InsertItem::getDataLibro() const
{
    return dataLibro->date();
}

QDate InsertItem::getDataLettera() const
{
    return dataLettera->date();
}

std::string InsertItem::getPrefazione() const
{
    return prefazione->text().toStdString();
}

std::string InsertItem::getCopertina() const
{
    return copertinaPath->text().toStdString();
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

std::string InsertItem::getFotoS() const
{
    return fotoSPath->text().toStdString();
}

std::string InsertItem::getFotoP() const
{
    return fotoPLabel->text().toStdString();
}

std::string InsertItem::getPrimaPagina() const
{
    return primaPaginaLabel->text().toStdString();
}

void InsertItem::setView(QString s)
{
    //Scultura
    catSLabel->setVisible(false);
    catSBox->setVisible(false);
    soggettoSLabel->setVisible(false);
    soggettoS->setVisible(false);
    materialeLabel->setVisible(false);
    materiale->setVisible(false);
    fotoSLabel->setVisible(false);
    fotoSPath->setVisible(false);
    fotoSButton->setVisible(false);
    //Magazine
    catMLabel->setVisible(false);
    catMBox->setVisible(false);
    dataMagazineLabel->setVisible(false);
    dataMagazine->setVisible(false);
    primaPaginaLabel->setVisible(false);
    primaPaginaButton->setVisible(false);
    primaPaginaPath->setVisible(false);
    //Libro
    dataLibroLabel->setVisible(false);
    dataLibro->setVisible(false);
    prefazioneLabel->setVisible(false);
    prefazione->setVisible(false);
    copertinaLabel->setVisible(false);
    copertinaButton->setVisible(false);
    copertinaPath->setVisible(false);
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
    fotoPButton->setVisible(false);
    fotoPLabel->setVisible(false);
    fotoPPath->setVisible(false);

    if(s=="Libro"){
        dataLibroLabel->setVisible(true);
        dataLibro->setVisible(true);
        prefazioneLabel->setVisible(true);
        prefazione->setVisible(true);
        copertinaLabel->setVisible(true);
        copertinaButton->setVisible(true);
        copertinaPath->setVisible(true);
    }else if(s=="Magazine"){
        catMLabel->setVisible(true);
        catMBox->setVisible(true);
        dataMagazineLabel->setVisible(true);
        dataMagazine->setVisible(true);
        primaPaginaLabel->setVisible(true);
        primaPaginaButton->setVisible(true);
        primaPaginaPath->setVisible(true);
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
        fotoSLabel->setVisible(true);
        fotoSPath->setVisible(true);
        fotoSButton->setVisible(true);
    }else if(s=="Dipinto"){
        catPLabel->setVisible(true);
        catPBox->setVisible(true);
        soggettoPLabel->setVisible(true);
        soggettoP->setVisible(true);
        movimentoLabel->setVisible(true);
        movimento->setVisible(true);
        fotoPButton->setVisible(true);
        fotoPLabel->setVisible(true);
        fotoPPath->setVisible(true);
    }
}


