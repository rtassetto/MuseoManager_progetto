#include "magazineitem.h"

MagazineItem::MagazineItem(std::string n, std::string a, std::string d, QDate dS, QDate dD, std::string p, categoriaM c):DocumentItem(n,a,d,dS,dD),primaPagina(p), cat(c)
{}

MagazineItem::MagazineItem(const MagazineItem & m):DocumentItem(m),primaPagina(m.primaPagina), cat(m.cat)
{}

std::string MagazineItem::getPrimaPagina() const
{
    return primaPagina;
}

std::string MagazineItem::getTipo() const
{
    return "Magazine";
}

std::string MagazineItem::getCategoriaM() const
{
    switch(cat)
    {
        case Giornale: return "giornale";
        case Quotidiano: return "quotidiano";
        case Rivista: return "rivista";
        case Almanacco: return "almanacco";
    }
}

categoriaM MagazineItem::getEnumM(const std::string & s)
{
    if(s=="giornale")
    {
        return categoriaM::Giornale;
    }else if(s=="quotidiano")
    {
        return categoriaM::Quotidiano;
    }else if(s=="rivista"){
        return categoriaM::Rivista;
    }else{
        return categoriaM::Almanacco;
    }
}

bool MagazineItem::operator==(const MagazineItem & m)
{
   return DocumentItem::operator ==(m) && cat==m.cat && primaPagina==m.primaPagina;
}

bool MagazineItem::operator!=(const MagazineItem & m)
{
    return DocumentItem::operator !=(m) || cat!=m.cat || primaPagina!=m.primaPagina;
}
