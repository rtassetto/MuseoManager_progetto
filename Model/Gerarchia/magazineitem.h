#ifndef MAGAZINEITEM_H
#define MAGAZINEITEM_H
#include <Model/Gerarchia/documentitem.h>

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
    string getCategoriaM()const;
    static categoriaM getEnumM(const string&);
    //metodi set
    void setPrimaPagina(const string&);

    string getTipo()const override;
    //operatori
    bool operator==(const MagazineItem&);
    bool operator!=(const MagazineItem&);

};

#endif // MAGAZINEITEM_H
