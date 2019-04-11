#ifndef LAB5_MATRIX_H
#define LAB5_MATRIX_H

#include <complex>
#include <tuple>

using std::complex;
using std::tuple;
using std::string;

complex<double> readComplex(string number); // czytanie liczby zespolonej
complex<double>** minorr(complex<double> **tab, int size, int x, int y);
complex<double> determinant(complex<double> **tab,int size); // funkcja do obliczania wyznacznika

class Matrix {
private:
    //pola
    complex<double> **matrix;
    int rows;
    int cols;
    // metody
    void allocateMatrix(); // alokacja pamieci dla macierzy
    tuple<int,int> bringSizeMatLab(const char* matLab); // pobranie wymiarow macierzy na podstawie const char*
    void fillMatrixMatLab(const char* matLab); // wypelnienie macierzy na podstawie danych z const char*
public:
    Matrix(); // set rows=1 cols=1 matrix[0][0]={0,0}
    Matrix(int rows,int cols);
    explicit Matrix(const char* matLab);
    int getRows();
    int getCols();
    void print(); // wypisanie macierzy
    complex<double> det(); // wyznacznik macierzy
    Matrix defaultMatrix(); // domyslna macierz 1 x 1 o wartosci {0,0}
    Matrix add(Matrix &m);
    Matrix sub(Matrix &m);
    Matrix mul(Matrix &m);
    Matrix div(Matrix &m);
    Matrix mulByNumber(complex<double> number);
    Matrix divByNumber(complex<double> number);
    Matrix pow(int pot);
    Matrix reverse(); // macierz odwrotna
    Matrix transpose(); // macierz transponowana
    Matrix matrixOfComplements(); // macierz dopelnien
};

#endif //LAB5_MATRIX_H
