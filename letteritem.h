#ifndef LETTERITEM_H
#define LETTERITEM_H
#include <documentitem.h>

class LetterItem : public DocumentItem
{
private:
    string testo;
    string destinatario;
public:
    //costruttori
    LetterItem(string , string , string , QDate , QDate, string, string);
    LetterItem(const LetterItem&);
    //metodi get
    string getDestinatario()const;
    string getTesto()const;
    string getTipo()const override;
    //operatori
    bool operator==(const LetterItem&);
    bool operator!=(const LetterItem&);
};

#endif // LETTERITEM_H
