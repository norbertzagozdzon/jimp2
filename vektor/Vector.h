#ifndef VEKTOR_VECTOR_H
#define VEKTOR_VECTOR_H

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

#endif //VEKTOR_VECTOR_H
