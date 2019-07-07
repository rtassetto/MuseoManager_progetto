#include "letteritem.h"

LetterItem::LetterItem(std::string n, std::string a , std::string d, QDate dS, QDate dD, std::string dest, std::string t):DocumentItem(n,a,d,dS,dD),destinatario(dest),testo(t)
{}

LetterItem::LetterItem(const LetterItem & l):DocumentItem(l),destinatario(l.destinatario),testo(l.testo)
{}

std::string LetterItem::getDestinatario() const
{
    return destinatario;
}

std::string LetterItem::getTesto() const
{
    return testo;
}

void LetterItem::setDestinatario(const std::string & s)
{
    destinatario=s;
}

void LetterItem::setTesto(const std::string & s)
{
    testo=s;
}

std::string LetterItem::getTipo() const
{
    return "Lettera";
}

bool LetterItem::operator==(const LetterItem & l)
{
    return DocumentItem::operator ==(l) && destinatario==l.destinatario && testo==l.testo;
}

bool LetterItem::operator!=(const LetterItem & l)
{
    return DocumentItem::operator !=(l) || destinatario!=l.destinatario || testo!=l.testo;
}
