#ifndef STATUEITEM_H
#define STATUEITEM_H
#include <Model/Gerarchia/museoitem.h>
#include <string>
using std::string;

enum categoriaS{Busto, Bassorilievo, Altorilievo, Sculturaequestre};
class StatueItem : public MuseoItem
{
private:
    categoriaS cat;
    string soggetto;
    string materiale;
    string foto;
public:
    //costruttori
    StatueItem(string , string , string ,QDate , categoriaS, string, string, string);
    StatueItem(const StatueItem&);
    //metodi get
    string getCategoriaS()const;
    string getSoggetto()const;
    string getMateriale()const;
    string getFotoS()const;
    static categoriaS getEnumS(const string&);
    //metodi set,
    void setSoggetto(const string&);
    void setMateriale(const string&);
    void setFotoS(const string&);
    string getTipo()const override;
    //operatori
    bool operator==(const StatueItem&);
    bool operator!=(const StatueItem&);
};

#endif // STATUEITEM_H
