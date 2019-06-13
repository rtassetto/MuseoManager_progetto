#ifndef INSERTITEM_H
#define INSERTITEM_H

#include <QMainWindow>
#include<QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QApplication>
#include <QDesktopWidget>

using std::string;

class InsertItem : public QWidget
{
    Q_OBJECT
private:
    QComboBox* museumType;
    QLabel* tipoLabel;
    QLabel* nomeLabel;
    QLabel* autoreLabel;
    QLabel* descLabel;
    QLabel* dataLabel;
    QLineEdit* nome;
    QLineEdit* autore;
    QLineEdit* desc;
    QDateEdit* data;

    //bookItem

    QLabel* dataLibroLabel;
    QDateEdit* dataLibro;
    QLabel* prefazioneLabel;
    QLineEdit* prefazione;
    QLabel* copertinaLabel;


    //letterItem

    QLabel* dataLetteraLabel;
    QDateEdit* dataLettera;
    QLabel* destinatarioLabel;
    QLineEdit* destinatario;
    QLabel* testoLabel;
    QLineEdit* testo;

    //magazineItem
    QLabel* primaPaginaLabel;
    QLabel* dataMagazineLabel;
    QDateEdit* dataMagazine;
    QLabel* catMLabel;
    QComboBox* catMBox;


    //statueItem
    QLabel* catSLabel;
    QComboBox* catSBox;
    QLabel* materialeLabel;
    QLabel* soggettoSLabel;
    QLineEdit* materiale;
    QLineEdit* soggettoS;

    //pictureItem
    QLabel* catPLabel;
    QComboBox* catPBox;
    QLabel* soggettoPLabel;
    QLabel* movimentoLabel;
    QLineEdit* soggettoP;
    QLineEdit* movimento;

    QPushButton* inserisci;


public:
    explicit InsertItem(QWidget *parent = 0);
    string getTipo()const;
    string getNome() const;
    string getAutore() const;
    string getData() const;
    string getDescrizione() const;

    string getDataMagazine()const;
    string getDataLibro()const;
    string getDataLettera()const;

    string getPrefazione()const;
    string getDestinatario()const;

    string getCatM() const;
    string getCatS() const;
    string getCatP() const;

    string getSoggettoS() const;
    string getSoggettoP() const;
    string getMovimento() const;
    string getMateriale() const;
    string getTesto() const;
signals:
    void inserito();
public slots:
    void setView(QString);
};

#endif // INSERTITEM_H
