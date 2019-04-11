#include<iostream>
#include<string>
#include<math.h>
using std::cout;
using std::string;
using std::endl;

class Punkt {
        public:
                int x;
                int y;
                Punkt() {
                        x = 0;
                        y = 0;

                }
                Punkt(int x, int y) {
                        this->x = x;
                        this->y = y;

                }
};
double Distance(Punkt a,Punkt b) {
                        int xDistPow = (a.x-b.x)*(a.x-b.x);
                        int yDistPow = (a.y-b.y)*(a.y-b.y);
                        return sqrt(xDistPow+yDistPow);
}
class Square {
        private:
                Punkt a;
                Punkt b;
                Punkt c;
                Punkt d;
        public:
                void setPoints(Punkt a, Punkt b, Punkt c, Punkt d) {
                        if( Distance(a,b)== Distance(b,c) && Distance(b,c) == Distance(c,d) && Distance(c,d)==Distance(d,a) && Distance(d,a)==Distance(a,b) ) {
                                this->a = a;
                                this->b = b;
                                this->c = c;
                                this->d = d;
                        }
                        else {
                                cout<<"to nie jest kwadrat!"<<endl;
                                return;
                        }

                }
                double Circumference() {
                        return Distance(a,b)*4;
                }
                double Area() {
                        return Distance(a,b)*Distance(a,b);
                }
};

int main() {
        /*
        Punkt a = Punkt(3,2);
        Punkt b = Punkt(6,6);
        cout<<"Odleglosc miedzy punktami: "<<Distance(a,b)<<endl;
        */
        Square s = Square();
        s.setPoints(Punkt(0,0),Punkt(0,1),Punkt(1,1),Punkt(1,0));
        cout<<"Obw: "<<s.Circumference()<<endl;
        cout<<"Pole: "<<s.Area()<<endl;
}