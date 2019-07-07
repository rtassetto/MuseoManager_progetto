#ifndef XMLIO_H
#define XMLIO_H
#include <Model/Gerarchia/qontainer.h>
#include <Model/Gerarchia/museoitem.h>
#include <Model/Gerarchia/statueitem.h>
#include <Model/Gerarchia/documentitem.h>
#include <Model/Gerarchia/pictureitem.h>
#include <Model/Gerarchia/bookitem.h>
#include <Model/Gerarchia/letteritem.h>
#include <Model/Gerarchia/magazineitem.h>

class XmlIO
{
private:
    string filename;
public:
    XmlIO(const string&);
    Qontainer<MuseoItem*> read() const;
    void write(const Qontainer<MuseoItem*>&) const;
};

#endif // XMLIO_H
