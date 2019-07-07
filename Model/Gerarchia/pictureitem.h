#ifndef PICTUREITEM_H
#define PICTUREITEM_H
#include <Model/Gerarchia/museoitem.h>
#include <string>
using std::string;

enum categoriaP{Ritratto, Paesaggio, Naturamorta, Fotografia};
class PictureItem : public MuseoItem
{
private:
    categoriaP cat;
    string soggetto;
    string movimentoArtistico;
    string foto;
public:
    //costruttori
    PictureItem(string , string , string , QDate , categoriaP, string, string, string);
    PictureItem(const PictureItem&);
    //metodi get
    string getCategoriaP()const;
    string getSoggetto()const;
    string getMovimento()const;
    static categoriaP getEnumP(const string&);
    string getFotoP()const;
    //metodi set , categoria e tipo dell'oggetto non sono modificabili perche' rappresentano l'oggetto stesso, in quel caso si dovra' eliminarlo e inserirne uno nuovo
    void setSoggetto(const string&);
    void setMovimento(const string&);
    void setFotoP(const string&);



    string getTipo()const override;
    //operatori
    bool operator==(const PictureItem&);
    bool operator!=(const PictureItem&);
    //
};

#endif // PICTUREITEM_H
