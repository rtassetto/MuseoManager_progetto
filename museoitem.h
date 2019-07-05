#ifndef MUSEOITEM_H
#define MUSEOITEM_H
#include <string>
#include <QDate>
using std::string;

class MuseoItem //classe base astratta
{
private:
    string nome;
    string autore;
    string descrizione;
    QDate dataScoperta;

public:
    //costruttori
    MuseoItem(string,string,string,QDate);
    MuseoItem(const MuseoItem&);
    //metodi get
    string getNome() const;
    string getAutore() const;
    string getDescrizione() const;
    QDate getData()const;
    //metodi set
    void setNome(const string&);
    void setAutore(const string&);
    void setDescrizione(const string&);
    void setData(const QDate&);

    //metodi virtuali
    virtual ~MuseoItem()=default;
    virtual string getTipo() const=0;
    //operatori
    bool operator==(const MuseoItem&);
    bool operator!=(const MuseoItem&);
};

#endif // MUSEOITEM_H
