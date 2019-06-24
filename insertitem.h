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
#include <QFileDialog>
#include <museoitem.h>

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
    QLabel* copertinaPath;
    QPushButton* copertinaButton;


    //letterItem

    QLabel* dataLetteraLabel;
    QDateEdit* dataLettera;
    QLabel* destinatarioLabel;
    QLineEdit* destinatario;
    QLabel* testoLabel;
    QLineEdit* testo;

    //magazineItem
    QLabel* primaPaginaLabel;
    QLabel* primaPaginaPath;
    QPushButton* primaPaginaButton;
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
    QLabel* fotoSLabel;
    QLabel* fotoSPath;
    QPushButton* fotoSButton;

    //pictureItem
    QLabel* catPLabel;
    QComboBox* catPBox;
    QLabel* soggettoPLabel;
    QLabel* movimentoLabel;
    QLineEdit* soggettoP;
    QLineEdit* movimento;
    QLabel* fotoPLabel;
    QLabel* fotoPPath;
    QPushButton* fotoPButton;

    QPushButton* inserisci;
    QPushButton* reset;


public:
    explicit InsertItem(QWidget *parent = nullptr);
    string getTipo()const;
    string getNome() const;
    string getAutore() const;
    QDate getData() const;
    string getDescrizione() const;

    QDate getDataMagazine()const;
    QDate getDataLibro()const;
    QDate getDataLettera()const;

    string getPrefazione()const;
    string getCopertina()const;
    string getDestinatario()const;

    string getCatM() const;
    string getCatS() const;
    string getCatP() const;

    string getSoggettoS() const;
    string getSoggettoP() const;
    string getMovimento() const;
    string getMateriale() const;
    string getTesto() const;
    string getFotoS() const;
    string getFotoP() const;
    string getPrimaPagina() const;
signals:
    void inserito();
public slots:
    void setView(QString);
    void addCopertina();
    void addPrimaPagina();
    void addFotoP();
    void addFotoS();
    void clearField();
};

#endif // INSERTITEM_H
