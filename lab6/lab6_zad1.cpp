
#include<iostream>
using std::cout;

using namespace std;

class Complex {
        private:
                double re, im;
        public:
                Complex() {

                }
                Complex(double re, double im) {
                        this->re = re;
                        this->im = im;
                }
                Complex operator +(const Complex &c) {
                        return Complex(this->re+c.re,this->im+c.im);
                }
                Complex operator -(const Complex &c) {
                        return Complex(this->re-c.re,this->im-c.im);
                }
                Complex operator *(const Complex &c) {
                        return Complex((this->re)*(c.re)-(this->im)*(c.im),(this->re)*(c.im)+(this->im)*(c.re));
                }
                Complex operator /(const Complex &c) {
                        double m = c.re*c.re+c.im*c.im;
                        return Complex(((this->re)*(c.re))/m-((this->im)*(c.im))/m,((this->re)*(c.im))/m+((this->im)*(c.re))/m);
                }
                void readComplex() {
                        cout<<re<<" + "<<im<<"i"<<std::endl;
                }
                friend std::ostream& operator<<(std::ostream &out, const Complex &c) {
                        out<<c.re<<" + "<<c.im<<"i";
                        return out;
                }
                friend std::istream& operator>>(std::istream &in, Complex &c) {
                        in>>c.re;
                        in>>c.im;
                        return in;
                }
};

int main() {
        std::ostream os();
        Complex c1 = Complex(4,5);
        Complex c2 = Complex(3,5);
        Complex c4;
        cin>>c4;
        cout<<c4+c1;
}
