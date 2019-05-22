#ifndef PICTUREITEM_H
#define PICTUREITEM_H
#include <museoitem.h>
#include <string>
using std::string;

enum categoriaP{ritratto, paesaggio, naturamorta, allegoria, fotografia};
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
    categoriaP getCategoria()const;
    string getSoggetto()const;
    string getMovimento()const;
    string getTipo()const override;
    //operatori
    bool operator==(const PictureItem&);
    bool operator!=(const PictureItem&);
    //
};

#endif // PICTUREITEM_H
