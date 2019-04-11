#include<iostream>

using std::string;
using std::cout;
using std::endl;

class Dziecko{
friend class Rodzic;
public:
        void setSzkola(string szkola) {
                this->szkola = szkola;
        }
        string getSzkola() {
                return szkola;
        }

private:
        string imie;
        string nazwisko;
        string szkola;

};
class Rodzic{
public:
        Rodzic(Dziecko *dziecko) {
                this->dziecko=dziecko;

        }
        void przepiszDoInnejSzkoly(string nowaSzkola) {
                this->dziecko->szkola=nowaSzkola;
        }
        string getDzieckoSzkola() {
                return dziecko->szkola;
        }

private:
        string imie;
        string nazwisko;
        int wiek;
        Dziecko *dziecko;
};

int main() {
        Dziecko d;
        d.setSzkola("stara szkola");
        Rodzic p = Rodzic(&d);
        cout<<"Przed przepisaniem: "<<endl;
        cout<<d.getSzkola()<<endl;
        cout<<p.getDzieckoSzkola()<<endl;
        p.przepiszDoInnejSzkoly("nowa szkola");
        cout<<"Po przepisaniu: "<<endl;
        cout<<d.getSzkola()<<endl;
        cout<<p.getDzieckoSzkola()<<endl;
}