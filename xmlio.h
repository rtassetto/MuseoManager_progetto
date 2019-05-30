#ifndef XMLIO_H
#define XMLIO_H
#include <qontainer.h>
#include <museoitem.h>

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
