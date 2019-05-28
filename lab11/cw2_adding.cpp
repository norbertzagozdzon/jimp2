#include<iostream>
#include<complex>

template<class T>
T Add(const T& a, const T& b) {
    return a+b;
}

int main() {
    std::cout<<"Double: "<<std::endl;
    std::cout<<Add<double>(10.5,11.3)<<std::endl;;
    std::cout<<"Int"<<std::endl;
    std::cout<<Add<int>(5,10)<<std::endl;
    std::cout<<"Complex"<<std::endl;
    std::cout<<Add<std::complex<double>>({1.2,0},{2,1.4})<<std::endl;
}