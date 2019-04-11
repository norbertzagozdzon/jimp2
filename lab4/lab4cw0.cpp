#include<iostream>
#include<string>

using std::cout;
using std::string;
using std::endl;

class Fraction {
private:
    int counter;
    int denominator;

public:
    void setFraction(int counter, int denominator) {
        if (denominator==0) {
            cout<<"mianownik musi byc rozny od 0"<<endl;
            return;
        }
        else {
            this->counter = counter;
            this->denominator = denominator;
        }
    }
    void getFraction() {
        cout<<counter<<"/"<<denominator<<endl;
    }
};

int main() {
    Fraction f = Fraction();
    f.setFraction(8,3);
    f.getFraction();

}