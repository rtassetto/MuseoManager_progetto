#include "museoitem.h"

MuseoItem::MuseoItem(string n, string a, string d, QDate dS):nome(n), autore(a), descrizione(d), dataScoperta(dS)
{}

MuseoItem::MuseoItem(const MuseoItem & m):nome(m.nome), autore(m.autore), descrizione(m.descrizione), dataScoperta(m.dataScoperta)
{}

string MuseoItem::getNome() const
{
    return nome;
}

string MuseoItem::getAutore() const
{
    return autore;
}

void MuseoItem::setNome(const std::string &s)
{
    nome=s;
}

void MuseoItem::setAutore(const std::string &s)
{
    autore=s;
}

string MuseoItem::getDescrizione() const
{
    return descrizione;
}

QDate MuseoItem::getData() const
{
    return dataScoperta;
}

bool MuseoItem::operator==(const MuseoItem & m)
{
    return nome==m.nome && autore==m.autore && descrizione==m.descrizione && dataScoperta==m.dataScoperta;
}

bool MuseoItem::operator!=(const MuseoItem & m)
{
    return nome!=m.nome || autore!=m.autore || descrizione!=m.descrizione || dataScoperta!=m.dataScoperta;
}

