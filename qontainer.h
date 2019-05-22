#ifndef QONTAINER_H
#define QONTAINER_H

//definizione contenitori, puntatore smart e relativi metodi

template <class T>
class Qontainer{
private:
    unsigned int size;
    unsigned int capacity;
    T* punt;
    void resize();
public:
    class smartP{
        friend class Qontainer<T>;
    private:
        T* p;
        smartP(T*);
    public:
        bool operator==(const smartP&) const;
        bool operator!=(const smartP&) const;
        T& operator*();
        T* operator->();

        smartP& operator++();
        smartP operator++(unsigned int);
        smartP& operator--();
        smartP operator--(unsigned int);

        smartP& operator+(unsigned int);
        smartP& operator-(unsigned int);
        smartP& operator+=(unsigned int);
        smartP& operator-=(unsigned int);

    }
    //costruttori, assegnazione e distruttore
    Qontainer(unsigned int=2);
    Qontainer(const T&, unsigned int=2);
    Qontainer(const Qontainer<T>&);
    ~Qontainer();
    Qontainer<T>& operator=(const Qontainer<T>&);


    //metodi
    T& operator[](unsigned int);
    bool operator==(const Qontainer<T>&)const;

    unsigned int getSize()const;
    unsigned int getCapacity()const;
    void clear();
    bool isEmpty()const;
    T& first()const;
    T& last()const;
    void push_back(const T&);
    void pop_back();
    void erase(T);
    void erase(unsigned int=0);
    void erase(unsigned int,unsigned int);
    T& position(unsigned int);

    //iteratori
    smartP begin() const;
    smartP end()const;

};


















#endif // QONTAINER_H
