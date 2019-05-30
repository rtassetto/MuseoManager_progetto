#include "museoitem.h"

MuseoItem::MuseoItem(string n, string a, string d, string f, QDate dS):nome(n), autore(a), descrizione(d), foto(f), dataScoperta(dS)
{}

MuseoItem::MuseoItem(const MuseoItem & m):nome(m.nome), autore(m.autore), descrizione(m.descrizione), foto(m.foto), dataScoperta(m.dataScoperta)
{}

string MuseoItem::getNome() const
{
    return nome;
}

string MuseoItem::getAutore() const
{
    return autore;
}

string MuseoItem::getDescrizione() const
{
    return descrizione;
}

string MuseoItem::getFoto() const
{
    return foto;
}

QDate MuseoItem::getData() const
{
    return dataScoperta;
}

bool MuseoItem::operator==(const MuseoItem & m)
{
    return nome==m.nome && autore==m.autore && descrizione==m.descrizione && foto==m.foto && dataScoperta==m.dataScoperta;
}

bool MuseoItem::operator!=(const MuseoItem & m)
{
    return nome!=m.nome || autore!=m.autore || descrizione!=m.descrizione || foto!=m.foto || dataScoperta!=m.dataScoperta;
}

