#ifndef PICTUREITEM_H
#define PICTUREITEM_H
#include <museoitem.h>
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
    //get
    string getCategoriaP()const;
    string getSoggetto()const;
    string getMovimento()const;
    static categoriaP getEnumP(const string&);
    string getFotoP()const;
    string getTipo()const override;
    //operatori
    bool operator==(const PictureItem&);
    bool operator!=(const PictureItem&);
    //
};

#endif // PICTUREITEM_H
