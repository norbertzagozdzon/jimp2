#include "Vector.h"
#include "InvalidIndexExpception.h"


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
