#include <iostream>
#include <list>

using std::cout;
using std::list;
using std::endl;
using std::cin;
using std::string;

class Martian{
public:
    static unsigned int numberOfMartian;
    Martian() {numberOfMartian++;}
    ~Martian() {numberOfMartian--;}
    void attackHard() {
        if(numberOfMartian>5)
            cout<<"ATTACKIN"<<endl;
        else
            cout<<"..."<<endl;
    }
};
unsigned int Martian::numberOfMartian = 0;



int main() {
    list<Martian*> m;
    string choice;
    while(true) {
        cout<<"Enter: 1) new Martian 0) delete Martian q) quit: ";
        cin>>choice;
        if(choice=="1") {
            m.push_back(new Martian());
        }
        else if (choice=="0") {
            if (Martian::numberOfMartian>0) {

                delete *m.begin();
                m.pop_front();
            }
            else
                cout<<"There is no Martian right here"<<endl;
		}
		else if (choice=="q") {
			break;
        }
        for (Martian* a: m) {
            a->attackHard();
        }
    }
}
