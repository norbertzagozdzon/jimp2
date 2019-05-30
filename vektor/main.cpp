#include "Vector.h"
#include "Vector.cpp"

int main() {
    auto v= Vector<int>(2);
    int a= 5;
    v.setAt(1,a);
};