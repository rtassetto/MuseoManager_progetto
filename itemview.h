#ifndef ITEMVIEW_H
#define ITEMVIEW_H
#include <QLabel>
#include <QTextEdit>
#include <QWidget>
#include <QMainWindow>
#include <QLineEdit>
#include <QLineEdit>
#include <QPushButton>

#include <QMainWindow>

class ItemView : public QWidget
{
    Q_OBJECT
private:
    QLabel* museumType;
    QLabel* tipoLabel;
    QLabel* nomeLabel;
    QLabel* autoreLabel;
    QLabel* descLabel;
    QLabel* dataLabel;
    QLineEdit* nome;
    QLineEdit* autore;
    QLineEdit* desc;
    QLineEdit* data;

    //bookItem

    QLabel* dataLibroLabel;
    QLineEdit* dataLibro;
    QLabel* prefazioneLabel;
    QLineEdit* prefazione;
    QLabel* copertinaLabel;


    //letterItem

    QLabel* dataLetteraLabel;
    QLineEdit* dataLettera;
    QLabel* destinatarioLabel;
    QLineEdit* destinatario;
    QLabel* testoLabel;
    QLineEdit* testo;

    //magazineItem
    QLabel* primaPaginaLabel;
    QLabel* dataMagazineLabel;
    QLineEdit* dataMagazine;
    QLabel* catMLabel;
    QLineEdit* catMBox;


    //statueItem
    QLabel* catSLabel;
    QLabel* materialeLabel;
    QLabel* soggettoSLabel;
    QLineEdit* materiale;
    QLineEdit* soggettoS;

    //pictureItem
    QLabel* catPLabel;
    QLabel* soggettoPLabel;
    QLabel* movimentoLabel;
    QLineEdit* soggettoP;
    QLineEdit* movimento;

    QPushButton* inserisci;

public:
    explicit ItemView(QWidget *parent = 0);

signals:

public slots:
};

#endif // ITEMVIEW_H
