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
    catDLabel=new QLabel("Categoria documento:",this);
    catSLabel=new QLabel("Categoria statua:",this);
    catPLabel=new QLabel("Categoria pittura:",this);
    testoLabel=new QLabel("Testo del documento:",this);
    materialeLabel=new QLabel("Materiale dell'opera:",this);
    soggettoSLabel=new QLabel("Soggetto della statua:",this);
    soggettoPLabel=new QLabel("Soggetto del dipinto:",this);
    movimentoLabel=new QLabel("Movimento artistico:",this);
    museumType=new QComboBox(this);
    nome=new QLineEdit(this);
    autore=new QLineEdit(this);
    desc=new QLineEdit(this);
    data=new QDateEdit(this);
    catDBox=new QComboBox(this);
    testo=new QLineEdit(this);
    catSBox=new QComboBox(this);
    materiale=new QLineEdit(this);
    soggettoS=new QLineEdit(this);
    catPBox=new QComboBox(this);
    soggettoP=new QLineEdit(this);
    movimento=new QLineEdit(this);
    inserisci=new QPushButton("Inserisci",this);
    //annulla=new QPushButton("Annullla",this);


    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    museumType->setFocus();
    museumType->addItem(QIcon(":/data/images/docicon.png"),"Documento");
    museumType->addItem(QIcon(":/data/images/statueicon.png"),"Scultura");
    museumType->addItem(QIcon(":/data/images/painticon.png"),"Dipinto");

    //mainLayout->setGeometry(QRect(0,0,450,550));
    QHBoxLayout* tipoLayout=new QHBoxLayout();
    QVBoxLayout* attributiLayout = new QVBoxLayout();
    QHBoxLayout* nomeLayout = new QHBoxLayout();
    QHBoxLayout* autoreLayout = new QHBoxLayout();
    QHBoxLayout* descLayout = new QHBoxLayout();
    QHBoxLayout* dataLayout = new QHBoxLayout();
    QHBoxLayout* catDLayout = new QHBoxLayout();
    QHBoxLayout* catSLayout = new QHBoxLayout();
    QHBoxLayout* catPLayout = new QHBoxLayout();
    QHBoxLayout* testoLayout = new QHBoxLayout();
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
    catDLayout->addWidget(catDLabel);
    catDLayout->addWidget(catDBox);
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
    attributiLayout->addLayout(catDLayout);
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



    //catDLabel->setVisible(false);
    //catDBox->setVisible(false);
    //testoLabel->setVisible(false);
    //testo->setVisible(false);
    catSLabel->setVisible(false);
    catSBox->setVisible(false);
    catPLabel->setVisible(false);
    catPBox->setVisible(false);
    soggettoSLabel->setVisible(false);
    soggettoS->setVisible(false);
    soggettoPLabel->setVisible(false);
    soggettoP->setVisible(false);
    movimentoLabel->setVisible(false);
    movimento->setVisible(false);
    materialeLabel->setVisible(false);
    materiale->setVisible(false);


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

std::string InsertItem::getCatD() const
{
    return catDBox->currentText().toStdString();
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
    catDLabel->setVisible(false);
    catDBox->setVisible(false);
    catSLabel->setVisible(false);
    catSBox->setVisible(false);
    catPLabel->setVisible(false);
    catPBox->setVisible(false);
    testoLabel->setVisible(false);
    testo->setVisible(false);
    soggettoSLabel->setVisible(false);
    soggettoS->setVisible(false);
    soggettoPLabel->setVisible(false);
    soggettoP->setVisible(false);
    movimentoLabel->setVisible(false);
    movimento->setVisible(false);
    materialeLabel->setVisible(false);
    materiale->setVisible(false);

    if(s=="Documento"){
        catDLabel->setVisible(true);
        catDBox->setVisible(true);
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


