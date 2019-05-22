#include "documentitem.h"

DocumentItem::DocumentItem(string n, string a, string d, string f, QDate dS, categoriaD c, string t):MuseoItem(n,a,d,f,dS),cat(c),testo(t)
{

}

DocumentItem::DocumentItem(const DocumentItem &m):MuseoItem(m),cat(m.cat), testo(m.testo)
{

}

categoriaD DocumentItem::getCategoria() const
{
    return cat;
}

std::string DocumentItem::getTesto() const
{
    return testo;
}

std::string DocumentItem::getTipo() const
{
    return "Documento";

}

bool DocumentItem::operator==(const DocumentItem & m)
{
    return MuseoItem::operator ==(m) && cat==m.cat && testo==m.testo;
}

bool DocumentItem::operator!=(const DocumentItem & m)
{
    return MuseoItem::operator !=(m) || cat!=m.cat || testo!=m.testo;
}
