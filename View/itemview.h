#ifndef ITEMVIEW_H
#define ITEMVIEW_H
#include <QLabel>
#include <QTextEdit>
#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QPushButton>
#include <Model/Gerarchia/museoitem.h>
#include <Model/Gerarchia/statueitem.h>
#include <Model/Gerarchia/documentitem.h>
#include <Model/Gerarchia/pictureitem.h>
#include <Model/Gerarchia/bookitem.h>
#include <Model/Gerarchia/magazineitem.h>
#include <Model/Gerarchia/letteritem.h>
#include <QDateEdit>
#include <QModelIndex>
#include <QFileDialog>
#include <QMainWindow>

class ItemView : public QWidget
{
    Q_OBJECT
private:
    MuseoItem* m;
    const QModelIndex indexBegin;
    const QModelIndex indexEnd;
    QLabel* museumType;
    QLabel* tipoLabel;
    QLabel* nomeLabel;
    QLabel* autoreLabel;
    QLabel* descLabel;
    QLabel* dataLabel;
    QLineEdit* nome;
    QLineEdit* autore;
    QLineEdit* desc;
    QDateEdit* data;


    //statueItem
    QLabel* catSLabel;
    QLabel* catSBox;
    QLabel* materialeLabel;
    QLabel* soggettoSLabel;
    QLineEdit* materiale;
    QLineEdit* soggettoS;
    QLabel* fotoSLabel;
    QLabel* fotoSPath;
    QPushButton* fotoSButton;

    //pictureItem
    QLabel* catPLabel;
    QLabel* catPBox;
    QLabel* soggettoPLabel;
    QLabel* movimentoLabel;
    QLineEdit* soggettoP;
    QLineEdit* movimento;
    QLabel* fotoPLabel;
    QLabel* fotoPPath;
    QPushButton* fotoPButton;

    //bookItem
    QLabel* dataLibroLabel;
    QDateEdit* dataLibro;
    QLabel* prefazioneLabel;
    QLineEdit* prefazione;
    QLabel* copertinaLabel;
    QLabel* copertinaPath;
    QPushButton* copertinaButton;


    //magazineItem
    QLabel* primaPaginaLabel;
    QLabel* primaPaginaPath;
    QPushButton* primaPaginaButton;
    QLabel* dataMagazineLabel;
    QDateEdit* dataMagazine;
    QLabel* catMLabel;
    QLabel* catMBox;

    //letterItem
    QLabel* dataLetteraLabel;
    QDateEdit* dataLettera;
    QLabel* destinatarioLabel;
    QLineEdit* destinatario;
    QLabel* testoLabel;
    QLineEdit* testo;


    QPushButton* modifica;
    QPushButton* chiudi;
    QPushButton* modificaFoto;

public:
    explicit ItemView(MuseoItem*, const QModelIndex& ,const QModelIndex&, QWidget *parent = 0);

signals:
    void dataChanged(const QModelIndex&, const QModelIndex&);
private slots:
    void modify();
    void modifyFotoS();
    void modifyFotoP();
    void modifyPrimaPagina();
    void modifyCopertina();
};

#endif // ITEMVIEW_H
