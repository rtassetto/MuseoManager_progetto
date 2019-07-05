#ifndef BOOKITEM_H
#define BOOKITEM_H
#include <documentitem.h>

class BookItem : public DocumentItem
{
private:
    string prefazione;
    string copertina;
public:
    //costruttori
    BookItem(string , string , string , QDate , QDate, string, string);
    BookItem(const BookItem&);
    //metodi get
    string getPrefazione()const;
    string getCopertina()const;
    //metodi set
    void setPrefazione(const string&);
    void setCopertina(const string&);
    string getTipo()const override;
    //operatori
    bool operator==(const BookItem&);
    bool operator!=(const BookItem&);


};

#endif // BOOKITEM_H
