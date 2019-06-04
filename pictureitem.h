#ifndef PICTUREITEM_H
#define PICTUREITEM_H
#include <museoitem.h>
#include <string>
using std::string;

enum categoriaP{Ritratto, Paesaggio, Naturamorta, Allegoria, Fotografia};
class PictureItem : public MuseoItem
{
private:
    categoriaP cat;
    string soggetto;
    string movimentoArtistico;
public:
    //costruttori
    PictureItem(string , string , string , string , QDate , categoriaP, string, string);
    PictureItem(const PictureItem&);
    //get
    string getCategoria()const;
    string getSoggetto()const;
    string getMovimento()const;
    static categoriaP getEnum(const string&);
    string getTipo()const override;
    //operatori
    bool operator==(const PictureItem&);
    bool operator!=(const PictureItem&);
    //
};

#endif // PICTUREITEM_H
