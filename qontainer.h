#ifndef QONTAINER_H
#define QONTAINER_H
#include <iostream>

//definizione contenitori, puntatore smart e relativi metodi

template <class T>
class Qontainer{
private:
    unsigned int size;
    unsigned int capacity;
    T* punt;
    void resize();
public:
    class iteratore{
        friend class Qontainer<T>;
    private:
        T* p;
        iteratore(T*);
    public:
        bool operator==(const iteratore&) const;
        bool operator!=(const iteratore&) const;
        T& operator*() const;
        T* operator->() const;

        iteratore& operator++();
        iteratore operator++(int);
        iteratore& operator--();
        iteratore operator--(int);

        iteratore& operator+(unsigned int);
        iteratore& operator-(unsigned int);
        iteratore& operator+=(unsigned int);
        iteratore& operator-=(unsigned int);

    };

    class iteratore_const{
        friend class Qontainer<T>;
    private:
        T* const_p;
        iteratore_const(T* const);
    public:
        bool operator==(const iteratore_const&) const;
        bool operator!=(const iteratore_const&) const;
        T& operator*() const;
        T* operator->() const;

        iteratore_const& operator++();
        iteratore_const operator++(int);
        iteratore_const& operator--();
        iteratore_const operator--(int);

        iteratore_const& operator+(unsigned int);
        iteratore_const& operator-(unsigned int);
        iteratore_const& operator+=(unsigned int);
        iteratore_const& operator-=(unsigned int);
    };
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
    void print() const ;

    //iteratori
    iteratore begin() const;
    iteratore end() const;
    iteratore_const c_begin() const;
    iteratore_const c_end() const;

};

// implementazione metodi iteratore

template<class T>
Qontainer<T>::iteratore::iteratore(T * t):p(t) {}

template<class T>
bool Qontainer<T>::iteratore::operator==(const Qontainer<T>::iteratore & i) const
{
    return i.p==p;

}

template<class T>
bool Qontainer<T>::iteratore::operator!=(const Qontainer<T>::iteratore & i) const
{
    return i.p!=p;
}

template<class T>
T &Qontainer<T>::iteratore::operator*() const
{
    return *p;
}

template<class T>
T *Qontainer<T>::iteratore::operator->() const
{
    return p;
}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator++()
{
    if(p) p++;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore Qontainer<T>::iteratore::operator++(int)
{
    iteratore aux=p;
    if(p)p++;
    return aux;

}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator--()
{
    if(p) p--;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore Qontainer<T>::iteratore::operator--(int)
{
    iteratore aux=p;
    if(p)p--;
    return aux;
}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator+(unsigned int n)
{
    if(p) p+=n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator-(unsigned int n)
{
    if(p) p-=n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator+=(unsigned int n)
{
    if(p) p=p+n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore &Qontainer<T>::iteratore::operator-=(unsigned int n)
{
    if(p) p=p-n;
    return *this;
}


//implementazione metodi iteratore_const

template<class T>
Qontainer<T>::iteratore_const::iteratore_const(T * t):const_p(t) {}

template<class T>
bool Qontainer<T>::iteratore_const::operator==(const Qontainer<T>::iteratore_const & i) const
{
    return i.const_p==const_p;

}

template<class T>
bool Qontainer<T>::iteratore_const::operator!=(const Qontainer<T>::iteratore_const & i) const
{
    return i.const_p!=const_p;
}

template<class T>
T &Qontainer<T>::iteratore_const::operator*() const
{
    return *const_p;
}

template<class T>
T *Qontainer<T>::iteratore_const::operator->() const
{
    return const_p;
}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator++()
{
    if(const_p) const_p++;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore_const Qontainer<T>::iteratore_const::operator++(int)
{
    iteratore_const aux=const_p;
    if(const_p)const_p++;
    return aux;

}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator--()
{
    if(const_p) const_p--;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore_const Qontainer<T>::iteratore_const::operator--(int)
{
    iteratore_const aux=const_p;
    if(const_p)const_p--;
    return aux;
}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator+(unsigned int n)
{
    if(const_p) const_p+=n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator-(unsigned int n)
{
    if(const_p) const_p-=n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator+=(unsigned int n)
{
    if(const_p) const_p+=n;
    return *this;
}

template<typename T>
typename Qontainer<T>::iteratore_const &Qontainer<T>::iteratore_const::operator-=(unsigned int n)
{
    if(const_p) const_p-=n;
    return *this;
}

//implementazione metodi Qontainer

template <typename T>
Qontainer<T>::Qontainer(unsigned int s)
    :size(0), capacity(s),
    punt( new T[s]){
}
template  <typename T>
Qontainer<T>::Qontainer( const T& t,unsigned int s):
    size(0), capacity(s),    punt(new T[s]){

    for(int i=0; i<capacity; i++)
        punt[i]=t;
}
template<typename T>
Qontainer<T>::Qontainer(const Qontainer<T>& a)//costruttore di copia
    : size(a.size),
      capacity(a.capacity),punt(new T[a.capacity]){
    for(unsigned int i=0; i<size; i++)
        punt[i]=a.punt[i];
}
template<typename T>
Qontainer<T>::~Qontainer<T>(){
    if(punt) delete[] punt;
}

template <typename T>
Qontainer<T>& Qontainer<T>::operator=(const Qontainer<T>& t){
    if(this!= &t){
        delete[] punt;
        size=t.size;
        capacity=t.capacity;
        punt= new T[capacity];
        for(unsigned int i=0; i<size; i++)
            punt[i]=t.punt[i];
    }

    return *this;
}

template<typename T>
T& Qontainer<T>::operator[](unsigned int i){
    return punt[i];
}

template<class T>
bool Qontainer<T>::operator==(const Qontainer<T> & t) const
{
    bool equal= t.size==size && t.capacity==capacity;
    for (auto it=begin(), it2= t.begin(); it!=end() && equal; ++it, ++it2) {
        if(*it!=*it2)equal=false;
    }
    return equal;
}

template <typename T>
unsigned int Qontainer<T>::getSize()const{
    return size;
}

template <typename T>
unsigned int Qontainer<T>::getCapacity()const{
    return capacity;
}
template <typename T>
void Qontainer<T>::clear(){
    delete [] punt;
    punt= new T[2];
    capacity=2;
    size=0;
}
template <typename T>
bool Qontainer<T>::isEmpty()const {
    return size==0;
}
template <typename T>
T& Qontainer<T>::first()const{
    return punt[0];
}


template< typename T>
T& Qontainer<T>::last()const{
    return punt[size-1];
}
template  <typename T>
void Qontainer<T>::resize(){
    unsigned int newCapacity= capacity*2;
    T* newPunt= new T[newCapacity];

    for(unsigned int i=0; i<size; i++){
        newPunt[i]= punt[i];
    }

    capacity= newCapacity;
    delete [] punt;
    punt=newPunt;
}
template<typename T>
void Qontainer<T>::push_back(const T& t){ //aggiungo in coda
    if (!(size<capacity))resize();
    punt[size+1]=t;
}

template<class T>
void Qontainer<T>::pop_back() //tolgo in coda
{
    if(size) size--;
}
template <typename T>
void Qontainer<T>::erase(unsigned int index){
    if(index>size-1) throw std::out_of_range("Indice fuori dai limiti");
    for(unsigned int i=index; i<size-1; i++){
        punt[i]=punt[i+1];
    }
    size--;
}

template <typename T>
void Qontainer<T>::erase(unsigned int start, unsigned int end){
    if(start<0 || end<0||start >size-1 || end>size-1 || start> end ) throw std::out_of_range("Indici fuori dai limiti");

    for(unsigned int i=start, j=1; i<size; i++, j++){
        punt[i]=punt[end+j];
    }
    size-=(end-start)+1;
}

template<class T>
void  Qontainer<T>::erase(T t)
{
    unsigned int index=0;
    for(auto it= begin() ; (*it)!= t && it!=end(); index++, ++it);
    return erase(index);
}

template <typename T>
T& Qontainer<T>::position(unsigned int index){
    if(index<0 || index > size-1){
        throw std::out_of_range("Indice fuori dai limiti");
    }
    return punt[index];
}

template <typename T>
typename Qontainer<T>::iteratore Qontainer<T>::begin()const{
    return iteratore(punt);
}

template <typename T>
typename Qontainer<T>::iteratore Qontainer<T>::end()const{
    return iteratore(punt+(size));
}
template <typename T>
void Qontainer<T>::print() const {
    if(size==0) std::cout<<"Vector e' vuoto "<<std::endl;
    for(unsigned int i=0; i< size; i++){
        std::cout<<punt[i]<<" ";
    }
    std::cout<<std::endl;
}



#endif // QONTAINER_H



