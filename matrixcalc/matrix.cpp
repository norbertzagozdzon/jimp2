#include "matrix.h"

#include<iostream>
#include<complex>
#include<tuple>
#include <sstream>

using std::complex;
using std::cout;
using std::endl;
using std::tuple;
using std::make_tuple;
using std::get;
using std::stringstream;

// funkcje
complex<double> readComplex(string number) {
    stringstream ss;
    string realIm;
    double real=0;
    double im=0;
    int i=0;
    while(number[i]!='i' && i<number.length()) {
        realIm+=number[i];
        i++;
    }
    i++;
    ss<<realIm;
    ss>>real;
    ss.clear();
    realIm.clear();
    while(i<number.length()) {
        realIm+=number[i];
        i++;
    }
    ss<<realIm;
    ss>>im;
    return {real,im};
}

complex<double>** minorr(complex<double> **tab, int size, int x, int y) {
    auto **result = new complex<double>*[size-1];
    for(int i=0;i<(size-1);i++) { //array memory allocatin'
        result[i]=new complex<double>[size-1];
    }
    int a,b;
    for (int i=0;i<(size-1);i++) {
        a=i;
        if (a>=x) a++;
        for (int j=0;j<(size-1);j++) {
            b=j;
            if(b>=y) b++;
            result[i][j]=tab[a][b];
        }
    }
    return result;
}

complex<double> determinant(complex<double> **tab, int size) {
    if(size==1) {
        return tab[0][0];
    }
    else {
        complex<double> one = -1;
        complex<double> result=0;
        for (int j=0;j<size;j++) {
            if (j%2==0) one=1;
            else one=-1;
            result+=tab[0][j]*one*determinant(minorr(tab, size, 0, j),size-1);
        }
        return result;
    }
}
string complexToString(const complex<double> &c) {
    string result;
    double re = c.real();
    double im = c.imag();
    if (re!=0) {
        stringstream temp;
        temp<<re;
        result+=temp.str();
    }
    if(im!=0) {
        stringstream temp;
        temp<<im;
        if(result!="") {
            result+="+";
        }
        result+=temp.str();
        result+="i";
    }
    if (re==0 and im==0) {
        result="0";
    }
    return result;
}

// metody prywatne
void Matrix::allocateMatrix() {
    matrix = new complex<double>*[rows];
    for (int i=0;i<rows;i++) {
        matrix[i]=new complex<double>[cols];
    }
}

tuple<int,int> Matrix::bringSizeMatLab(const char* matLab) {
    if (matLab[0]=='[') {
        int i=1;
        int x=0;
        int y=0;
        bool end = false;
        bool ifOkEnding=false;
        bool first = true;
        int yCounter=0;
        bool newNumber = false;
        while(matLab[i]) {
            if (end) {
                cout<<"ERROR: STH UNWANTED AFTER LAST BRACKET"<<endl;
                return make_tuple(0,0);
            }
            if(matLab[i]!=' ' && matLab[i]!=';' && matLab[i]!=']') {
                newNumber=true;
            }
            else {
                if(newNumber) {
                    yCounter++;
                    newNumber=false;
                }
                if(matLab[i]==';') {
                    if (first) {
                        first=false;
                    }
                    else {
                        if(y!=yCounter) {
                            cout<<"ERROR: WRONG MATLAB SYNTAX"<<endl;
                            return make_tuple(0,0);
                        }
                    }
                    y = yCounter;
                    yCounter=0;
                    x++;
                }
                else if(matLab[i]==']') {
                    if (first) {
                        first=false;
                    }
                    else {
                        if(y!=yCounter) {
                            cout<<"ERROR: WRONG MATLAB SYNTAX"<<endl;
                            return make_tuple(0,0);
                        }
                    }
                    y = yCounter;
                    yCounter=0;
                    x++;
                    ifOkEnding=true;
                    end = true;

                }
            }
            i++;
        }
        if(!ifOkEnding) {
            cout<<"ERROR: MISSING ENDING BRACKET"<<endl;
            return make_tuple(0,0);
        }
        else {
            return make_tuple(x,y);
        }
    }
    else {
        cout<<"ERROR: MISSING BRACKET AT THE BEGINNING"<<endl;
        return make_tuple(0,0);
    }
}

void Matrix::fillMatrixMatLab(const char *matLab) {
    complex<double> temp[rows*cols];
    int g=0;
    int i=1;
    string number;
    while(matLab[i]) {
        if(matLab[i]!=' ' && matLab[i]!=';' && matLab[i]!=']') {
            number+=matLab[i];
        }
        else {
            if (number.length()>0) {
                temp[g] = readComplex(number);
                g++;
                number.clear();
            }
        }
        i++;
    }
    g=0;
    for(i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            matrix[i][j]=temp[g];
            g++;
        }
    }
}
// metody publiczne
void Matrix::setError(bool error) {
    this->error = error;
}
bool Matrix::isError() {
    return error;
}
Matrix::Matrix() {
    error = false;
    rows = 1;
    cols = 1;
    allocateMatrix();
    matrix[0][0]={0,0};
}

Matrix::Matrix(int rows,int cols) {
    error = false;
    this->rows = rows;
    this->cols = cols;
    allocateMatrix();
}

Matrix::Matrix(const char* matLab) {
    error = false;
    tuple<int,int> tempSize = bringSizeMatLab(matLab);
    rows = get<0>(tempSize);
    cols= get<1>(tempSize);
    if(rows>0 && cols>0) {
        allocateMatrix();
        fillMatrixMatLab(matLab);
    }
    else {
        cout<<"ERROR: STH WENT WRONG"<<endl;
        rows = 1;
        cols = 1;
        error = true;
        matrix=defaultMatrix().matrix;
    }
}

int Matrix::getRows() {return rows;}

int Matrix::getCols() {return cols;}

string Matrix::print() {
    string result;
    if (rows>0 && cols>0) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result+=complexToString(matrix[i][j]);
                result+="   ";
            }
            result+="\n";
        }
    }
    return result;
}

complex<double> Matrix::det() {
    if(rows==cols) {
        return determinant(matrix,rows);
    }
    else {
        cout<<"ERROR; MATRIX AINT SQUARE"<<endl;
        return -1;
    }
}

Matrix Matrix::defaultMatrix() {
    Matrix defaultM = Matrix(1,1);
    defaultM.error=true;
    defaultM.matrix[0][0]=complex<double>(0,0);
    return defaultM;
}

Matrix Matrix::add(Matrix &m) {
    if (m.rows==rows && m.cols==cols) {
        Matrix result = Matrix(m.rows,m.cols);
        for (int i=0;i<m.rows;i++) {
            for(int j=0;j<m.cols;j++) {
                result.matrix[i][j]=matrix[i][j]+m.matrix[i][j];
            }
        }
        return result;
    }
    else {
        cout<<"ERROR: MATRICES SIZE AIN'T THE SAME"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::sub(Matrix &m) {
    if (m.rows==rows && m.cols==cols) {
        Matrix result = Matrix(m.rows,m.cols);
        for (int i=0;i<m.rows;i++) {
            for(int j=0;j<m.cols;j++) {
                result.matrix[i][j]=matrix[i][j]-m.matrix[i][j];
            }
        }
        return result;
    }
    else {
        cout<<"ERROR: MATRICES SIZE AIN'T THE SAME"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::mul(Matrix &m) {
    if(cols==m.rows) {
        Matrix result = Matrix(rows,m.cols);
        for (int i=0;i<rows;i++) {
            for (int j=0;j<m.cols;j++) {
                result.matrix[i][j]=0;
                for(int k=0;k<cols;k++) {
                    result.matrix[i][j]+=matrix[i][k]*m.matrix[k][j];
                }
            }
        }
        return result;
    }
    else {
        cout<<"ERROR: MATRICES HAVE INCORRECT SIZE TO MULTIPLY"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::div(Matrix &m) {
    if (m.rows==m.cols) {
        m = m.reverse();
        return mul(m);
    }
    else {
        cout<<"CANT DIV BY NON-SQUARE MATRIX"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::mulByNumber(complex<double> number) {
    Matrix result = Matrix(rows,cols);
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            result.matrix[i][j]=matrix[i][j]*number;
        }
    }
    return result;
}

Matrix Matrix::divByNumber(complex<double> number) {
    Matrix result = Matrix(rows,cols);
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
            result.matrix[i][j]=matrix[i][j]/number;
        }
    }
    return result;
}

Matrix Matrix::pow(int pot) {
    if (rows==cols) {
        Matrix thisMatrix;
        thisMatrix.matrix = this->matrix;
        thisMatrix.rows= this->rows;
        thisMatrix.cols = this->cols;
        Matrix result = Matrix(rows,cols);
        for (int i=0;i<rows;i++) {
            for (int j=0;j<cols;j++) {
                if(i==j) {
                    result.matrix[i][j]=1;
                }
                else {
                    result.matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<pot;i++) {
            result = result.mul(thisMatrix);
        }
        return result;
    }
    else {
        cout<<"CANT POW NON-SQUARE MATRIX"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::reverse() {
    if(rows==cols) {
        complex<double> determinant = det();
        if (determinant.real()==0 && determinant.imag()==0) {
            cout<<"ERROR: DETERMINANT=0 SO YOU CANT REVERSE MATRIX"<<endl;
            return defaultMatrix();
        }
        else {
            return transpose().matrixOfComplements().divByNumber(det());
        }
    }
    else {
        cout<<"ERROR: CANT REVERSE NON-SQUARE MATRIX"<<endl;
        return defaultMatrix();
    }
}

Matrix Matrix::transpose() {
    Matrix result= Matrix(cols,rows);
    for (int i=0;i<cols;i++) {
        for (int j=0;j<rows;j++) {
            result.matrix[i][j]=matrix[j][i];
        }
    }
    return result;
}

Matrix Matrix::matrixOfComplements() {
    if (rows==cols) {
        Matrix result = Matrix(rows,cols);
        complex<double> one = -1;
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++) {
                if ((i+1+j+1)%2==0) one=1;
                else one=-1;
                result.matrix[i][j]=one*determinant(minorr(matrix, rows, i, j),rows-1);
            }
        }
        return result;
    }
    else {
        cout<<"ERROR: CANT MAKE MATRIX OF COMPLEMENTS OF NON-SQUARE MATRIX"<<endl;
        return defaultMatrix();
    }
}
string Matrix::getNumberByIndex(int row, int col) {
    return complexToString(matrix[row][col]);
}
