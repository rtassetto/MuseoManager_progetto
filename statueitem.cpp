#include "statueitem.h"

StatueItem::StatueItem(string n, string a, string d, string f, QDate dS, categoriaS c, string s, string m):MuseoItem(n,a,d,f,dS),cat(c),soggetto(s),materiale(m)
{

}

StatueItem::StatueItem(const StatueItem & s):MuseoItem(s),cat(s.cat),soggetto(s.soggetto),materiale(s.materiale)
{

}

std::string StatueItem::getCategoria() const
{
    switch(cat)
    {
        case Busto: return "busto";
        case Bassorilievo: return "bassorilievo";
        case Altorilievo: return "altorilievo";
        case Sculturaequestre: return "sculturaequestre";
    }
}


std::string StatueItem::getSoggetto() const
{
    return soggetto;
}

std::string StatueItem::getMateriale() const
{
    return materiale;
}

categoriaS StatueItem::getEnum(const std::string & s)
{
    if(s=="busto")
    {
        return categoriaS::Busto;
    }else if(s=="bassorilievo")
    {
        return categoriaS::Bassorilievo;
    }else if(s=="altorilievo"){
        return categoriaS::Altorilievo;
    }else{
        return categoriaS::Sculturaequestre;
    }
}

std::string StatueItem::getTipo() const
{
    return "Statua";
}

bool StatueItem::operator==(const StatueItem & s)
{
    return MuseoItem::operator ==(s) && cat==s.cat && soggetto==s.soggetto && materiale==s.materiale;
}

bool StatueItem::operator!=(const StatueItem & s)
{
    return MuseoItem::operator !=(s) || cat!=s.cat || soggetto!=s.soggetto || materiale!=s.materiale;
}
