#include "bookitem.h"

BookItem::BookItem(std::string n, std::string a, std::string d, QDate dS, QDate dD, std::string p, std::string c):DocumentItem(n,a,d,dS,dD),prefazione(p),copertina(c)
{}

BookItem::BookItem(const BookItem & b):DocumentItem(b),prefazione(b.prefazione),copertina(b.copertina)
{}

std::string BookItem::getPrefazione() const
{
    return prefazione;
}

std::string BookItem::getCopertina() const
{
    return copertina;
}

void BookItem::setPrefazione(const std::string & s)
{
    prefazione=s;
}

void BookItem::setCopertina(const std::string & s)
{
    copertina=s;
}

std::string BookItem::getTipo() const
{
    return "Libro";
}

bool BookItem::operator==(const BookItem & b)
{
    return DocumentItem::operator ==(b) && prefazione==b.prefazione && copertina==b.copertina;
}

bool BookItem::operator!=(const BookItem & b)
{
    return DocumentItem::operator !=(b) || prefazione!=b.prefazione || copertina!=b.copertina;
}
