#ifndef MAGAZINEITEM_H
#define MAGAZINEITEM_H
#include <documentitem.h>

enum categoriaM{Giornale,Quotidiano, Rivista, Almanacco};
class MagazineItem : public DocumentItem
{
private:
    string primaPagina;
    categoriaM cat;
public:
    //costruttori
    MagazineItem(string , string , string , QDate , QDate, string, categoriaM);
    MagazineItem(const MagazineItem&);
    //metodi get
    string getPrimaPagina()const;
    string getTipo()const override;
    string getCategoriaM()const;
    static categoriaM getEnumM(const string&);
    //operatori
    bool operator==(const MagazineItem&);
    bool operator!=(const MagazineItem&);

};

#endif // MAGAZINEITEM_H
