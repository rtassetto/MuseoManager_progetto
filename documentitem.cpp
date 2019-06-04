#include "documentitem.h"

DocumentItem::DocumentItem(string n, string a, string d, string f, QDate dS, categoriaD c, string t):MuseoItem(n,a,d,f,dS),cat(c),testo(t)
{

}

DocumentItem::DocumentItem(const DocumentItem &m):MuseoItem(m),cat(m.cat), testo(m.testo)
{

}

std::string DocumentItem::getCategoria() const
{
    switch(cat)
    {
        case Rivista: return "rivista";
        case Lettera: return "lettera";
        case Libro: return "libro";
    }
}

std::string DocumentItem::getTesto() const
{
    return testo;
}

categoriaD DocumentItem::getEnum(const string& s)
{
    if(s=="rivista")
    {
        return categoriaD::Rivista;
    }else if(s=="lettera")
    {
        return categoriaD::Lettera;
    }else{
        return categoriaD::Libro;
    }
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
