//
// written by norbert zagozdzon
//
#include <iostream>
#include "matrix.h"

using std::cout;
using std::endl;

int main(int argc,char* argv[]) {
    Matrix m1("[1 2;3 4]");
    Matrix m2("[5 2; 3 1]");
    cout << "Macierz pierwsza: "<< endl;
    m1.print();
    cout << "Macierz druga: "<< endl;
    m2.print();
    cout << "Dodawanie" <<endl;
    (m1.add(m2)).print();
    cout << "Odejmowanie" <<endl;
    (m1.sub(m2)).print();
    cout << "Mnozenie" <<endl;
    (m1.mul(m2)).print();
    cout << "Dzielenie" <<endl;
    (m1.div(m2)).print();
    cout << "Potegowanie" <<endl;
    (m1.pow(2)).print();
    cout << "Potegowanie" <<endl;
    (m2.pow(2)).print();



}
