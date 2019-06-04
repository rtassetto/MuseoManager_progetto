#include "pictureitem.h"

PictureItem::PictureItem(string n, string a, string d, string f, QDate dS, categoriaP c, string s, string m):MuseoItem(n,a,d,f,dS),cat(c),soggetto(s),movimentoArtistico(m)
{}

PictureItem::PictureItem(const PictureItem & p):MuseoItem(p),cat(p.cat),soggetto(p.soggetto),movimentoArtistico(p.movimentoArtistico)
{}

std::string PictureItem::getCategoria() const
{
    switch(cat)
    {
        case Ritratto: return "ritratto";
        case Paesaggio: return "paesaggio";
        case Naturamorta: return "naturamorta";
        case Allegoria: return "allegoria";
        case Fotografia: return "fotografia";
    }
}

std::string PictureItem::getSoggetto() const
{
    return soggetto;
}

std::string PictureItem::getMovimento() const
{
    return movimentoArtistico;
}

categoriaP PictureItem::getEnum(const std::string & s)
{
    if(s=="ritratto")
    {
        return categoriaP::Ritratto;
    }else if(s=="paesaggio")
    {
        return categoriaP::Paesaggio;
    }else if(s=="naturamorta"){
        return categoriaP::Naturamorta;
    }else if(s=="allegoria"){
        return categoriaP::Allegoria;
    }else{
        return categoriaP::Fotografia;
    }
}

std::string PictureItem::getTipo() const
{
    return "Pittura";
}

bool PictureItem::operator==(const PictureItem & p)
{
     return MuseoItem::operator ==(p) && cat==p.cat && soggetto==p.soggetto && movimentoArtistico==p.movimentoArtistico;
}

bool PictureItem::operator!=(const PictureItem & p)
{
    return MuseoItem::operator !=(p) || cat!=p.cat || soggetto!=p.soggetto || movimentoArtistico!=p.movimentoArtistico;
}
