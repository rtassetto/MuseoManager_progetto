#include "pictureitem.h"

PictureItem::PictureItem(string n, string a, string d, QDate dS, categoriaP c, std::string s, string m, string f):MuseoItem(n,a,d,dS),cat(c),soggetto(s),movimentoArtistico(m),foto(f)
{}

PictureItem::PictureItem(const PictureItem & p):MuseoItem(p),cat(p.cat),soggetto(p.soggetto),movimentoArtistico(p.movimentoArtistico),foto(p.foto)
{}

std::string PictureItem::getCategoriaP() const
{
    switch(cat)
    {
        case Ritratto: return "ritratto";
        case Paesaggio: return "paesaggio";
        case Naturamorta: return "naturamorta";
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

categoriaP PictureItem::getEnumP(const std::string & s)
{
    if(s=="ritratto")
    {
        return categoriaP::Ritratto;
    }else if(s=="paesaggio")
    {
        return categoriaP::Paesaggio;
    }else if(s=="naturamorta"){
        return categoriaP::Naturamorta;
    }else{
        return categoriaP::Fotografia;
    }
}

std::string PictureItem::getFotoP() const
{
    return foto;
}

void PictureItem::setSoggetto(const std::string & s)
{
    soggetto=s;
}

void PictureItem::setMovimento(const std::string & s)
{
    movimentoArtistico=s;
}

void PictureItem::setFotoP(const std::string & s)
{
    foto=s;
}


std::string PictureItem::getTipo() const
{
    return "Pittura";
}

bool PictureItem::operator==(const PictureItem & p)
{
     return MuseoItem::operator ==(p) && cat==p.cat && soggetto==p.soggetto && movimentoArtistico==p.movimentoArtistico && foto==p.foto;
}

bool PictureItem::operator!=(const PictureItem & p)
{
    return MuseoItem::operator !=(p) || cat!=p.cat || soggetto!=p.soggetto || movimentoArtistico!=p.movimentoArtistico || foto!=p.foto;
}
