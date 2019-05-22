#ifndef STATUEITEM_H
#define STATUEITEM_H
#include <museoitem.h>
#include <string>
using std::string;

enum categoriaS{busto, bassorilievo, altorilievo, sculturaequestre};
class StatueItem : public MuseoItem
{
private:
    categoriaS cat;
    string soggetto;
    string materiale;
public:
    //costruttori
    StatueItem(string , string , string , string , QDate , categoriaS, string, string);
    StatueItem(const StatueItem&);
    //get
    categoriaS getCategoria()const;
    string getSoggetto()const;
    string getMateriale()const;
    string getTipo()const override;
    //operatori
    bool operator==(const StatueItem&);
    bool operator!=(const StatueItem&);
};

#endif // STATUEITEM_H
