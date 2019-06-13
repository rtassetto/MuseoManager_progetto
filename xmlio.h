#ifndef XMLIO_H
#define XMLIO_H
#include <qontainer.h>
#include <museoitem.h>
#include<statueitem.h>
#include<documentitem.h>
#include<pictureitem.h>
#include<bookitem.h>
#include<letteritem.h>
#include<magazineitem.h>

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
