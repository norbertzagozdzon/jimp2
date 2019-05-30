#include "InvalidIndexExpception.h"

template<class T>
class Vector {
private:
    int size;
    T *tab;
public:
    Vector(int initialSize);
    ~Vector();
    void setAt(int index,T&t);
};

template<class T>
Vector<T>::Vector(int initialSize) {
    this->size = initialSize;
    this->tab = new T[initialSize];
}

template<class T>
Vector<T>::~Vector() {}

template<class T>
void Vector<T>::setAt(int index, T &t) {
    if(index>=size) {
        throw InvalidIndexException();
    }
    else {
        this->tab[index] = t;
    }
}

int main() {
    Vector<int> v= Vector<int>(2);
    int a= 5;
    v.setAt(1,a);
};