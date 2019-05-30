#include "Vector.h"
#include "Vector.cpp"
#include "Animal.h"
#include "Tax36.h"
#include "Tax37.h"
#include<iostream>

int main() {
    auto v = Vector<int>(2);
    int a = 5;
    v.setAt(1, a);

    Tax36 tax1;
    Tax37 tax2;
    tax1.Calculate();
    tax2.Calculate();

    Animal z;
    std::cin >> z;
    std::cout << z;
}