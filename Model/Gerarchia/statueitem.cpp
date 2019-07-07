#include "statueitem.h"

StatueItem::StatueItem(string n, string a, string d, QDate dS, categoriaS c, string s, string m, string f):MuseoItem(n,a,d,dS),cat(c),soggetto(s),materiale(m),foto(f)
{

}

StatueItem::StatueItem(const StatueItem & s):MuseoItem(s),cat(s.cat),soggetto(s.soggetto),materiale(s.materiale),foto(s.foto)
{

}

std::string StatueItem::getCategoriaS() const
{
    switch(cat)
    {
        case Busto: return "busto";
        case Bassorilievo: return "bassorilievo";
        case Altorilievo: return "altorilievo";
        case Sculturaequestre: return "sculturaequestre";
    }
    throw std::exception();
}


std::string StatueItem::getSoggetto() const
{
    return soggetto;
}

std::string StatueItem::getMateriale() const
{
    return materiale;
}

std::string StatueItem::getFotoS() const
{
    return foto;
}

categoriaS StatueItem::getEnumS(const std::string & s)
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

void StatueItem::setSoggetto(const std::string & s)
{
    soggetto=s;
}

void StatueItem::setMateriale(const std::string & s)
{
    materiale=s;
}

void StatueItem::setFotoS(const std::string & s)
{
    foto=s;
}

std::string StatueItem::getTipo() const
{
    return "Statua";
}

bool StatueItem::operator==(const StatueItem & s)
{
    return MuseoItem::operator ==(s) && cat==s.cat && soggetto==s.soggetto && materiale==s.materiale && foto==s.foto;
}

bool StatueItem::operator!=(const StatueItem & s)
{
    return MuseoItem::operator !=(s) || cat!=s.cat || soggetto!=s.soggetto || materiale!=s.materiale || foto!=s.foto;
}
