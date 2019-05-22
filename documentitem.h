#ifndef DOCUMENTITEM_H
#define DOCUMENTITEM_H
#include <museoitem.h>
using std::string;


enum categoriaD{Rivista, Libro, Lettera};
class DocumentItem : public MuseoItem
{
private:
    categoriaD cat;
    string testo;

public:
    //costruttori
    DocumentItem(string , string , string , string , QDate , categoriaD , string );
    DocumentItem(const DocumentItem&);
    //metodi get
    categoriaD getCategoria()const;
    string getTesto() const;
    string getTipo() const override;
    //operatori
    bool operator==(const DocumentItem&);
    bool operator!=(const DocumentItem&);
};

#endif // MUSEODOCUMENT_H