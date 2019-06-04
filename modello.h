#ifndef MODELLO_H
#define MODELLO_H
#include <qontainer.h>
#include <museoitem.h>
#include <xmlio.h>

class Modello
{
private:
    Qontainer<MuseoItem*> q;
    string path;
    bool isSaved;

public:
    //costruttore e distruttore
    Modello()=default;
    ~Modello()=default;

    //metodi
    Qontainer<MuseoItem*>::iteratore begin();
    Qontainer<MuseoItem*>::iteratore end();

    void load(const string&);
    void save(const string&) const;
    bool getSaved() const;
    void setSaved(bool);
    unsigned int getDataSize()const;
    unsigned int getDataCapacity()const;
    bool isDataEmpty()const;

    void push_end(MuseoItem *);
    void erase(unsigned int);
    void erase(unsigned int, unsigned int);
    void erase(MuseoItem*);
    MuseoItem* position(unsigned int);

    void clear();
    void print()const;
    void setNewPath(string );


//metodi container di risultati della ricerca

    Qontainer<MuseoItem*>:: iteratore_const resultBegin() const;
    Qontainer<MuseoItem*>:: iteratore_const reultEnd() const;
    unsigned int getResultSize() const;
    MuseoItem* resultPosition(unsigned int);
    void resetSearcResult()const;
    void eraseFound()const;
    void filterBy() const;

    /*void filterByName(string )const ;
    void filterBySex(string )const;
    void filterByPriceMin(double )const;
    void filterByPriceMag(double )const;
    void filterBySeason(string )const;
    void filterByType(string )const;*/

};

#endif // MODELLO_H
