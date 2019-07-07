#include "itemview.h"
#include <QPushButton>
#include <QDate>
#include<QDateEdit>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>


ItemView::ItemView(MuseoItem *mItem, const QModelIndex & i, const QModelIndex & f, QWidget *parent) : QWidget(parent), m(mItem),indexBegin(i),indexEnd(f)
{
    //move(QApplication::desktop()->screen()->rect().center() - rect().center());
    //setFixedSize();
    setFixedSize(QSize(400,500));
    tipoLabel=new QLabel("Tipo dell'oggetto:",this);
    nomeLabel=new QLabel("Nome:",this);
    autoreLabel=new QLabel("Autore:",this);
    descLabel=new QLabel("Descrizione:",this);
    dataLabel=new QLabel("Data ritrovamento:",this);
    museumType=new QLabel(QString::fromStdString(m->getTipo()),this);
    nome=new QLineEdit(QString::fromStdString(m->getNome()));
    autore=new QLineEdit(QString::fromStdString(m->getAutore()));
    desc=new QLineEdit(QString::fromStdString(m->getDescrizione()));
    data=new QDateEdit((m->getData()));
    data->setDisplayFormat(QString("dd.MM.yyyy"));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QVBoxLayout* attributiLayout = new QVBoxLayout();
    QHBoxLayout* tipoLayout=new QHBoxLayout();
    QHBoxLayout* nomeLayout = new QHBoxLayout();
    QHBoxLayout* autoreLayout = new QHBoxLayout();
    QHBoxLayout* descLayout = new QHBoxLayout();
    QHBoxLayout* dataLayout = new QHBoxLayout();

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
    attributiLayout->addLayout(nomeLayout);
    attributiLayout->addLayout(autoreLayout);
    attributiLayout->addLayout(descLayout);
    attributiLayout->addLayout(dataLayout);


    if(m->getTipo()=="Statua"){
        catSLabel=new QLabel("Categoria statua:",this);
        materialeLabel=new QLabel("Materiale dell'opera:",this);
        soggettoSLabel=new QLabel("Soggetto della statua:",this);
        fotoSLabel=new QLabel("Foto della statua:",this);

        if(static_cast<StatueItem*>(m)->getFotoS()!=""){
            fotoSLabel->setPixmap(QPixmap(QString::fromStdString(static_cast<StatueItem*>(m)->getFotoS())));
            fotoSLabel->pixmap()->scaled(fotoSLabel->size(), Qt::KeepAspectRatio);
            fotoSLabel->setScaledContents(true);
        }

        fotoSPath=new QLabel(QString::fromStdString(static_cast<StatueItem*>(m)->getFotoS()),this);
        fotoSPath->hide();
        fotoSButton=new QPushButton("Modifica immagine:",this);
        catSBox=new QLabel(QString::fromStdString(static_cast<StatueItem*>(m)->getCategoriaS()),this);
        materiale=new QLineEdit(QString::fromStdString(static_cast<StatueItem*>(m)->getMateriale()),this);
        soggettoS=new QLineEdit(QString::fromStdString(static_cast<StatueItem*>(m)->getSoggetto()),this);

        QHBoxLayout* catSLayout = new QHBoxLayout();
        QHBoxLayout* soggettoSLayout = new QHBoxLayout();
        QHBoxLayout* fotoSLayout = new QHBoxLayout();
        QHBoxLayout* materialeLayout = new QHBoxLayout();

        fotoSLayout->addWidget(fotoSLabel);
        fotoSLayout->addWidget(fotoSButton);
        catSLayout->addWidget(catSLabel);
        catSLayout->addWidget(catSBox);
        soggettoSLayout->addWidget(soggettoSLabel);
        soggettoSLayout->addWidget(soggettoS);
        materialeLayout->addWidget(materialeLabel);
        materialeLayout->addWidget(materiale);
        attributiLayout->addLayout(catSLayout);
        attributiLayout->addLayout(soggettoSLayout);
        attributiLayout->addLayout(materialeLayout);
        attributiLayout->addLayout(fotoSLayout);

        connect(fotoSButton,SIGNAL(clicked()),this,SLOT(modifyFotoS()));

    }else if(m->getTipo()=="Pittura"){
        catPLabel=new QLabel("Categoria pittura:",this);
        movimentoLabel=new QLabel("Materiale dell'opera:",this);
        soggettoPLabel=new QLabel("Soggetto della pittura:",this);
        fotoPLabel=new QLabel("Foto della pittura:",this);

        if(static_cast<PictureItem*>(m)->getFotoP()!=""){
            fotoPLabel->setPixmap(QPixmap(QString::fromStdString(static_cast<PictureItem*>(m)->getFotoP())));
            fotoPLabel->pixmap()->scaled(fotoPLabel->size(), Qt::KeepAspectRatio);
            fotoPLabel->setScaledContents(true);
        }

        fotoPPath=new QLabel(QString::fromStdString(static_cast<PictureItem*>(m)->getFotoP()),this);
        fotoPPath->hide();
        fotoPButton=new QPushButton("Modifica immagine:",this);
        catPBox=new QLabel(QString::fromStdString(static_cast<PictureItem*>(m)->getCategoriaP()),this);
        movimento=new QLineEdit(QString::fromStdString(static_cast<PictureItem*>(m)->getMovimento()),this);
        soggettoP=new QLineEdit(QString::fromStdString(static_cast<PictureItem*>(m)->getSoggetto()),this);

        QHBoxLayout* catPLayout = new QHBoxLayout();
        QHBoxLayout* soggettoPLayout = new QHBoxLayout();
        QHBoxLayout* fotoPLayout = new QHBoxLayout();
        QHBoxLayout* movimentoLayout = new QHBoxLayout();

        fotoPLayout->addWidget(fotoPLabel);
        fotoPLayout->addWidget(fotoPButton);
        catPLayout->addWidget(catPLabel);
        catPLayout->addWidget(catPBox);
        soggettoPLayout->addWidget(soggettoPLabel);
        soggettoPLayout->addWidget(soggettoP);
        movimentoLayout->addWidget(movimentoLabel);
        movimentoLayout->addWidget(movimento);
        attributiLayout->addLayout(catPLayout);
        attributiLayout->addLayout(soggettoPLayout);
        attributiLayout->addLayout(movimentoLayout);
        attributiLayout->addLayout(fotoPLayout);

        connect(fotoPButton,SIGNAL(clicked()),this,SLOT(modifyFotoP()));

    }else if(m->getTipo()=="Libro"){
        dataLibroLabel=new QLabel("Data pubblicazione del libro:",this);
        prefazioneLabel =new QLabel("Prefazione del libro:",this);
        copertinaLabel =new QLabel("Foto della copertina:",this);

        if(static_cast<BookItem*>(m)->getCopertina()!=""){
            copertinaLabel->setPixmap(QPixmap(QString::fromStdString(static_cast<BookItem*>(m)->getCopertina())));
            copertinaLabel->pixmap()->scaled(copertinaLabel->size(), Qt::KeepAspectRatio);
            copertinaLabel->setScaledContents(true);
        }
        dataLibro=new QDateEdit(static_cast<BookItem*>(m)->getDataDocumento(),this);
        dataLibro->setDisplayFormat(QString("dd.MM.yyyy"));
        prefazione=new QLineEdit(QString::fromStdString(static_cast<BookItem*>(m)->getPrefazione()),this);
        copertinaButton=new QPushButton("Modifica immagine",this);
        copertinaPath=new QLabel(QString::fromStdString(static_cast<BookItem*>(m)->getCopertina()),this);
        copertinaPath->hide();


        QHBoxLayout* dataLibroLayout = new QHBoxLayout();
        QHBoxLayout* prefazioneLayout = new QHBoxLayout();
        QHBoxLayout* copertinaLayout = new QHBoxLayout();

        dataLibroLayout->addWidget(dataLibroLabel);
        dataLibroLayout->addWidget(dataLibro);
        prefazioneLayout->addWidget(prefazioneLabel);
        prefazioneLayout->addWidget(prefazione);
        copertinaLayout->addWidget(copertinaLabel);
        copertinaLayout->addWidget(copertinaButton);

        attributiLayout->addLayout(dataLibroLayout);
        attributiLayout->addLayout(prefazioneLayout);
        attributiLayout->addLayout(copertinaLayout);

        connect(copertinaButton,SIGNAL(clicked()),this,SLOT(modifyCopertina()));


    }else if(m->getTipo()=="Magazine"){

        catMLabel=new QLabel("Tipo di periodico:",this);
        dataMagazineLabel=new QLabel("Data uscita del periodico",this);
        primaPaginaLabel=new QLabel("Foto prima pagina:",this);

        if(static_cast<MagazineItem*>(m)->getPrimaPagina()!=""){
            primaPaginaLabel->setPixmap(QPixmap(QString::fromStdString(static_cast<MagazineItem*>(m)->getPrimaPagina())));
            primaPaginaLabel->pixmap()->scaled(primaPaginaLabel->size(), Qt::KeepAspectRatio);
            primaPaginaLabel->setScaledContents(true);
        }

        catMBox=new QLabel(QString::fromStdString(static_cast<MagazineItem*>(m)->getCategoriaM()),this);
        dataMagazine=new QDateEdit(static_cast<MagazineItem*>(m)->getDataDocumento(),this);
        dataMagazine->setDisplayFormat(QString("dd.MM.yyyy"));
        primaPaginaPath=new QLabel(QString::fromStdString(static_cast<MagazineItem*>(m)->getPrimaPagina()),this);
        primaPaginaPath->hide();
        primaPaginaButton=new QPushButton("Modifica immagine",this);


        QHBoxLayout* catMLayout = new QHBoxLayout();
        QHBoxLayout* dataMagazineLayout = new QHBoxLayout();
        QHBoxLayout* primaPaginaLayout = new QHBoxLayout();

        catMLayout->addWidget(catMLabel);
        catMLayout->addWidget(catMBox);
        dataMagazineLayout->addWidget(dataMagazineLabel);
        dataMagazineLayout->addWidget(dataMagazine);
        primaPaginaLayout->addWidget(primaPaginaLabel);
        primaPaginaLayout->addWidget(primaPaginaButton);

        attributiLayout->addLayout(catMLayout);
        attributiLayout->addLayout(dataMagazineLayout);
        attributiLayout->addLayout(primaPaginaLayout);

        connect(primaPaginaButton,SIGNAL(clicked()),this,SLOT(modifyPrimaPagina()));

    }else{//letter item

        dataLetteraLabel=new QLabel("Data della lettera",this);
        destinatarioLabel=new QLabel("Destinatario della lettera",this);
        testoLabel=new QLabel("Testo della lettera:");

        dataLettera=new QDateEdit(static_cast<MagazineItem*>(m)->getDataDocumento(),this);
        dataLettera->setDisplayFormat(QString("dd.MM.yyyy"));
        destinatario=new QLineEdit(QString::fromStdString(static_cast<LetterItem*>(m)->getDestinatario()),this);
        testo=new QLineEdit(QString::fromStdString(static_cast<LetterItem*>(m)->getTesto()),this);

        QHBoxLayout* dataLetteraLayout = new QHBoxLayout();
        QHBoxLayout* testoLayout = new QHBoxLayout();
        QHBoxLayout* destinatarioLayout = new QHBoxLayout();

        dataLetteraLayout->addWidget(dataLetteraLabel);
        dataLetteraLayout->addWidget(dataLettera);
        destinatarioLayout->addWidget(destinatarioLabel);
        destinatarioLayout->addWidget(destinatario);
        testoLayout->addWidget(testoLabel);
        testoLayout->addWidget(testo);

        attributiLayout->addLayout(dataLetteraLayout);
        attributiLayout->addLayout(destinatarioLayout);
        attributiLayout->addLayout(testoLayout);

    }

    QHBoxLayout* buttonLayout=new QHBoxLayout();
    modifica=new QPushButton("Salva modifiche",this);
    chiudi=new QPushButton("Chiudi",this);
    buttonLayout->addWidget(modifica);
    buttonLayout->addWidget(chiudi);
    attributiLayout->addLayout(buttonLayout);

    mainLayout->addLayout(tipoLayout);
    mainLayout->addLayout(attributiLayout);



    connect(chiudi,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(modify()));

}

void ItemView::modify()
{
    m->setNome(nome->text().toStdString());
    m->setAutore(autore->text().toStdString());
    m->setDescrizione(desc->text().toStdString());
    m->setData(data->date());

    if(m->getTipo()=="Statua"){
        static_cast<StatueItem*>(m)->setMateriale(materiale->text().toStdString());
        static_cast<StatueItem*>(m)->setSoggetto(soggettoS->text().toStdString());
        static_cast<StatueItem*>(m)->setFotoS(fotoSPath->text().toStdString());
    }else if(m->getTipo()=="Pittura"){
        static_cast<PictureItem*>(m)->setMovimento(movimento->text().toStdString());
        static_cast<PictureItem*>(m)->setSoggetto(soggettoP->text().toStdString());
        static_cast<PictureItem*>(m)->setFotoP(fotoPPath->text().toStdString());
    }else if(m->getTipo()=="Libro"){
        static_cast<BookItem*>(m)->setDataDocumento(dataLibro->date());
        static_cast<BookItem*>(m)->setPrefazione(prefazione->text().toStdString());
        static_cast<BookItem*>(m)->setCopertina(copertinaPath->text().toStdString());
    }else if(m->getTipo()=="Magazine"){
        static_cast<MagazineItem*>(m)->setDataDocumento(dataMagazine->date());
        static_cast<MagazineItem*>(m)->setPrimaPagina(primaPaginaPath->text().toStdString());
    }else{
        static_cast<LetterItem*>(m)->setDataDocumento(dataLettera->date());
        static_cast<LetterItem*>(m)->setDestinatario(destinatario->text().toStdString());
        static_cast<LetterItem*>(m)->setTesto(testo->text().toStdString());
    }
    emit(dataChanged(indexBegin,indexEnd));
}

void ItemView::modifyFotoS()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    fotoSLabel->setPixmap(QPixmap(file));
    fotoSLabel->pixmap()->scaled(fotoSLabel->size(), Qt::KeepAspectRatio);
    fotoSLabel->setScaledContents(true);
    fotoSPath->setText(file);
}

void ItemView::modifyFotoP()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    fotoPLabel->setPixmap(QPixmap(file));
    fotoPLabel->pixmap()->scaled(fotoPLabel->size(), Qt::KeepAspectRatio);
    fotoPLabel->setScaledContents(true);
    fotoPPath->setText(file);
}

void ItemView::modifyPrimaPagina()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    primaPaginaLabel->setPixmap(QPixmap(file));
    primaPaginaLabel->pixmap()->scaled(primaPaginaLabel->size(), Qt::KeepAspectRatio);
    primaPaginaLabel->setScaledContents(true);
    primaPaginaPath->setText(file);
}

void ItemView::modifyCopertina()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Inserisci immagine"),"../MuseoManager/data/images", tr("Image Files (*.png *.jpg *.bmp)"));
    copertinaLabel->setPixmap(QPixmap(file));
    copertinaLabel->pixmap()->scaled(copertinaLabel->size(), Qt::KeepAspectRatio);
    copertinaLabel->setScaledContents(true);
    copertinaPath->setText(file);

}



