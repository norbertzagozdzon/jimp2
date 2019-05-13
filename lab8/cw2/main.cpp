#include <iostream>

using namespace std;

class WrongPesel {
    char* err;
public:
    WrongPesel() {
        err = "Podano zly pesel...\n";
    }
    void blad() {
        cout<<err;
    };
};

class Pesel {
    string _pesel;
public:
    Pesel(string pesel) {
        try {
            validatePesel(pesel);
            cout<<"Dobry Pesel!!! : "<<pesel<<endl;
        }
        catch(WrongPesel &w) {
            w.blad();
        }
    }
    void validatePesel(string pesel) {
        if (pesel.length()==11) {
            int check = 9*(pesel[0]-'0')+7*(pesel[1]-'0')+3*(pesel[2]-'0')+(pesel[3]-'0')+9*(pesel[4]-'0')+7*(pesel[5]-'0')+3*(pesel[6]-'0')+(pesel[7]-'0')+9*(pesel[8]-'0')+7*(pesel[9]-'0');
            check%=10;
            if(check!=(pesel[10]-'0')) {
                throw WrongPesel();
            }
        }
    }
};

int main() {
    Pesel p1("9801108296");
    Pesel p2("44051401358");
}