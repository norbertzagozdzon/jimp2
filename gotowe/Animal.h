#ifndef ANIMALZ_ANIMAL_H
#define ANIMALZ_ANIMAL_H

#include <iostream>

class Animal {
private:
    std::string Species;
    std::string Name;
    int Age;
public:
    int operator++() {
        Age++;
        return Age;
    }
    bool operator==(const Animal& other) {
        return this->Species==other.Species && this->Name==other.Name && this->Age==other.Age;
    }
    friend std::istream& operator>>(std::istream& in,Animal& animal) {
        in>>animal.Species>>animal.Name>>animal.Age;
        return in;
    }
    friend std::ostream& operator<<(std::ostream& out,const Animal& animal) {
        out<<"Gatunek: "<<animal.Species<<std::endl<<"Nazwa: "<<animal.Name<<std::endl<<"Wiek: "<<animal.Age<<std::endl;
        return out;
    }
};

#endif //ANIMALZ_ANIMAL_H
