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



//implementazione dei metodi

template <typename T>
Qontainer<T>::Qontainer(unsigned int s)
    :size(0), capacity(s),
    p( new T[s]){
}
template  <typename T>
Qontainer<T>::Qontainer( const T& t,unsigned int s):
    size(0), capacity(s),    p(new T[s]){

    for(int i=0; i<capacity; i++)
        p[i]=t;
}
template<typename T>
Qontainer<T>::Qontainer(const Qontainer<T>& a)//costruttore di copia
    : size(a.size),
      capacity(a.capacity),p(new T[a.capacity]){
    for(unsigned int i=0; i<size; i++)
        p[i]=a.p[i];
}
template<typename T>
Qontainer<T>::~Qontainer<T>(){
    if(p) delete[] p;
}

template <typename T>
Qontainer<T>& Qontainer<T>::operator=(const Qontainer<T>& t){
    if(this!= &t){
        delete[] p;
        size=t.size;
        capacity=t.capacity;
        p= new T[capacity];
        for(unsigned int i=0; i<size; i++)
            p[i]=t.p[i];
    }

    return *this;
}

template<typename T>
T& Qontainer<T>::operator[](unsigned int index){
    return p[index];
}

template<class T>
bool Qontainer<T>::operator==(const Qontainer<T> & t) const
{
    bool uguale=t.size== size && t.capacity== capacity;
    for (auto it= cbegin(), it2= t.cbegin(); it!=cend() && uguale; ++it, ++it2) {
        if(*it!=*it2)uguale=false;
    }
    return uguale;
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
    delete [] p;
    p= new T[2];
    capacity=2;
    size=0;
}
template <typename T>
bool Qontainer<T>::isEmpty()const {
    return size==0;
}
template <typename T>
T& Qontainer<T>::front(){
    return p[0];
}


template< typename T>
T& Qontainer<T>::back(){
    return p[size-1];
}
template  <typename T>
void Qontainer<T>::reserve(){
    //ricrea il buffer con la dimensione doppia rispetto a quella attuale.
    unsigned int newCapacity= capacity*2;
    T* newBuffer= new T[newCapacity];

    for(unsigned int i=0; i<size; i++){
        newBuffer[i]= p[i];
    }

    capacity= newCapacity;
    delete [] p;
    p=newBuffer;
}
template<typename T>
void Qontainer<T>::push_back(const T& t){
    if (!(size<capacity))
        reserve();
    p[size++]=t;

}

template<class T>
void Qontainer<T>::pop_back()
{
    size>0 ? --size:0;
}
template <typename T>
void Qontainer<T>::erase(unsigned int index){
    if(index>size-1) throw std::out_of_range("The index is out of range!");
    for(unsigned int i=index; i<size-1; i++ )
        p[i]= p[i+1];
    size--;

}

template <typename T>
void Qontainer<T>::erase(unsigned int start, unsigned int end){
    if(start<0 || end<0||start >size-1 || end>size-1 || start> end ) throw std::out_of_range("Indexes are out of bounds");

    unsigned int i=start, j=1;

    for(; i<size; i++, j++)
        p[i]=p[end+j];

    size-=(end-start)+1;
}
template<class T>
void  Qontainer<T>::erase(T which)
{
//    std::cerr<<"cerco indice"<<std::endl;
    unsigned int index=0U;
    for(auto it= begin() ; (*it)!= which && it!=end(); index++, ++it);

//    std::cerr<<"Indice: "<<index<<std::endl;
    return erase(index);
}
template <typename T>
T& Qontainer<T>::at(unsigned int index){
    if(index<0 || index > size-1){
        throw std::out_of_range("The index is out of bound");

    }
    return p[index];
}

//*******************************ITERATOR********************************
template <typename T>
typename Qontainer<T>::iterator Qontainer<T>::begin()const{
    return iterator(p);
}

template <typename T>
typename Qontainer<T>::iterator Qontainer<T>::end()const{
    return iterator(p+(size));
}
template <typename T>
typename Qontainer<T>::const_iterator Qontainer<T>::cbegin()const{
    return const_iterator(p);
}
template <typename T>
typename Qontainer<T>::const_iterator Qontainer<T>::cend()const{
    return const_iterator(p+(size));
}
template <typename T>
void Qontainer<T>::print_all() const {
    if(size==0) std::cout<<"Vector e' vuoto "<<std::endl;
    for( unsigned int i=0; i< size; i++)
        std::cout<<p[i]<<" ";
    std::cout<<std::endl;
}
//*********************************   iterator   ********************************
template<class T>
Qontainer<T>::iterator::iterator(T* t):punt(t){
}
template< typename T>
bool Qontainer<T>::iterator::operator!=(const iterator& ite) const {
    return punt!=ite.punt;
}
template <typename T>
bool Qontainer<T>::iterator::operator==(const iterator& ite)const{
    return punt==ite.punt;
}

template< typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator++() {
    if(punt) punt++;
    return *this;
}
template< typename T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator++(int) {
    iterator aux=*this;
    if(punt) punt++;
    return aux;
}
template  <typename T>
T& Qontainer<T>::iterator::operator*(){
    return *punt;
}

template  <typename T>
T* Qontainer<T>::iterator::operator->(){
    return punt;
}
template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator --(){

    if(punt) punt--;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator Qontainer<T>::iterator::operator --(int){
    iterator aux(punt);
    if(punt) punt--;
    return aux;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator +(unsigned int i){
    if(punt) punt+=i;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator -(unsigned int i){
    if(punt) punt-=i;
    return *this;
}
template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator -=(unsigned int i){
    if(punt) punt-=i;
    return *this;
}

template <typename T>
typename Qontainer<T>::iterator& Qontainer<T>::iterator::operator +=(unsigned int i){
    if(punt) punt+=i;
    return *this;
}














#endif // QONTAINER_H
