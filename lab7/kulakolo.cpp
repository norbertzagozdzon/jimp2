//
// Created by lenox on 16.04.19.
//
#include <iostream>

using std::cout;

class Circle {
protected:
    double x,y,r;
public:
    Circle() {}
    Circle(double x, double y, double r) {
        this->x = x;
        this->y = y;
        this->r = r;
    }
    double area() {
        return 3.14*r*r;
    }
};
class Sphere : public Circle{
    double z;
public:
    explicit Sphere(double x,double y,double z, double r) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->r = r;
        cout<<area();
    }
    double area() {
        return 4*3.14*r*r;
    }
};

int main() {
    Sphere(0,0,0,10);

}