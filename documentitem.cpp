#include "documentitem.h"

DocumentItem::DocumentItem(string n, string a, string d, QDate dS, QDate dD):MuseoItem(n,a,d,dS),dataDocumento(dD)
{

}

DocumentItem::DocumentItem(const DocumentItem &m):MuseoItem(m),dataDocumento(m.dataDocumento)
{

}


QDate DocumentItem::getDataDocumento() const
{
    return dataDocumento;
}


bool DocumentItem::operator==(const DocumentItem & m)
{
    return MuseoItem::operator ==(m) && dataDocumento==m.dataDocumento;
}

bool DocumentItem::operator!=(const DocumentItem & m)
{
    return MuseoItem::operator !=(m) || dataDocumento!=m.dataDocumento;
}
