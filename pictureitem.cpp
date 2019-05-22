#include "pictureitem.h"

PictureItem::PictureItem(string n, string a, string d, string f, QDate dS, categoriaP c, string s, string m):MuseoItem(n,a,d,f,dS),cat(c),soggetto(s),movimentoArtistico(m)
{}

PictureItem::PictureItem(const PictureItem & p):MuseoItem(p),cat(p.cat),soggetto(p.soggetto),movimentoArtistico(p.movimentoArtistico)
{}

categoriaP PictureItem::getCategoria() const
{
    return cat;
}

std::string PictureItem::getSoggetto() const
{
    return soggetto;
}

std::string PictureItem::getMovimento() const
{
    return movimentoArtistico;
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
