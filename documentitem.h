#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H
#include <museoitem.h>
using std::string;

class DocumentItem : public MuseoItem
{
private:
    QDate dataDocumento;
public:
    //costruttori
    DocumentItem(string , string , string , QDate , QDate );
    DocumentItem(const DocumentItem&);
    //metodi get
    QDate getDataDocumento() const;
    //operatori
    bool operator==(const DocumentItem&);
    bool operator!=(const DocumentItem&);
};

#endif // MUSEODOCUMENT_H
