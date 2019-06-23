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
    void save(const string&);
    bool getSaved() const;
    void setSaved(bool);
    unsigned int getDataSize()const;
    unsigned int getDataCapacity()const;
    bool isDataEmpty()const;

    static categoriaM getEnumM(const string&);
    static categoriaS getEnumS(const string&);
    static categoriaP getEnumP(const string&);

    void push_end(MuseoItem *);
    void erase(unsigned int);
    void erase(unsigned int, unsigned int);
    void erase(MuseoItem*);
    MuseoItem* position(unsigned int);



//metodi container di risultati della ricerca

    /*void filterByName(string )const ;
    void filterBySex(string )const;
    void filterByPriceMin(double )const;
    void filterByPriceMag(double )const;
    void filterBySeason(string )const;
    void filterByType(string )const;*/

};

#endif // MODELLO_H
