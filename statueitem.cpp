#include "statueitem.h"

StatueItem::StatueItem(string n, string a, string d, string f, QDate dS, categoriaS c, string s, string m):MuseoItem(n,a,d,f,dS),cat(c),soggetto(s),materiale(m)
{

}

StatueItem::StatueItem(const StatueItem & s):MuseoItem(s),cat(s.cat),soggetto(s.soggetto),materiale(s.materiale)
{

}

categoriaS StatueItem::getCategoria() const
{
    return cat;
}

std::string StatueItem::getSoggetto() const
{
    return soggetto;
}

std::string StatueItem::getMateriale() const
{
    return materiale;
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
