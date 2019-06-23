#include "modello.h"


Qontainer<MuseoItem*>::iteratore Modello::begin()
{
    return q.begin();
}

Qontainer<MuseoItem*>::iteratore Modello::end()
{
    return q.end();
}

void Modello::load(const string& file)
{
    XmlIO io(file);
    q = io.read();
}

void Modello::save(const string& file)
{
    XmlIO io(file);
    io.write(q);
    isSaved=true;
}

bool Modello::getSaved() const
{
    return isSaved;
}

void Modello::setSaved(bool b)
{
    isSaved=b;
}


unsigned int Modello::getDataSize() const
{
    return q.getSize();
}

unsigned int Modello::getDataCapacity() const
{
    return q.getCapacity();
}

bool Modello::isDataEmpty() const
{
    return q.isEmpty();
}

categoriaM Modello::getEnumM(const std::string & s)
{
    return MagazineItem::getEnumM(s);
}

categoriaS Modello::getEnumS(const std::string & s)
{
    return StatueItem::getEnumS(s);
}

categoriaP Modello::getEnumP(const std::string & s)
{
    return PictureItem::getEnumP(s);
}

void Modello::push_end(MuseoItem * m)
{
    isSaved=false;
    q.push_back(m);
}

void Modello::erase(unsigned int i)
{
    isSaved=false;
    q.erase(i);

}

void Modello::erase(unsigned int first, unsigned int last)
{
    isSaved=false;
    q.erase(first,last);

}

void Modello::erase(MuseoItem * m)
{
    isSaved=false;
    q.erase(m);

}

MuseoItem *Modello::position(unsigned int i)
{
    return q.position(i);
}








