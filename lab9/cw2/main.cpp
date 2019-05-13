#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<memory>


class Food {
protected:
    double bac;
    double cash;
public:
    explicit Food(double bac) {
        this->bac = bac;
    }
    virtual std::string name() = 0;
    virtual double getBac() =0;
    virtual double getCash()=0;

};

class Vodka : public Food {
public:
    std::string name() override {return "vodka";}
    Vodka():Food(1.20) {
    }

    double getBac() override {
        return bac;
    }

    double getCash() override {
        return 29.99;
    }
};

class Jupik : public Food {
public:
    std::string name() override {return "jupik";}
    Jupik():Food(0) {
    }

    double getBac() override {
        return bac;
    }
    double getCash() override {
        return 2.99;
    }

private:
};

class Kebab : public Food {
public:
    std::string name() override {return "kebab";}
    Kebab():Food(0) {
    }

    double getBac() override {
        return bac;
    }
    double getCash() override {
        return 11.00;
    }
private:
};

class Sandwich : public Food {
public:
    std::string name() override {return "sandwich";}
    Sandwich():Food(0) {
    }
    double getBac() override {
        return bac;
    }
    double getCash() override {
        return 3.50;
    }
private:
};
class Beer : public Food {
public:
    std::string name() override {return "beer";}
    Beer():Food(0.22) {
    }
    double getBac() override {
        return bac;
    }
    double getCash() override {
        return 2.50;
    }
private:
};
class Backpack {
public:

    Backpack() : products(0), bac(0), cash(0),isSorted(false) {}

    void fillBackpack() {
        while (!isFull()) {
            addProduct();
        }
    }

    void showBackpack() {
        std::cout << "Zawartosc Plecaka: " << std::endl << "_______" << std::endl;
        for (Food &a: backpack) {
            std::cout << a.name() << std::endl;
        }
        std::cout << "_______" << std::endl<< "Promile w plecaku: " << bac << std::endl<< "Wydatek: " << cash << "zl" << std::endl<<"Posortowane?: ";
        if(isSorted) {
            std::cout<<"Tak";
        }
        else {
            std::cout<<"Nie";
        }
        std::cout<<std::endl;
    }

    void sortProducts() {
        int pre = -1;
        int post = -1;
        std::vector<int> beerVec;
        std::vector<int> vodkaVec;
        std::vector<int> foodVec;
        std::vector<int> jupikVec;
        int g = 0;
        int prods = 7;
        std::vector<std::reference_wrapper<Food>> temp = std::ref(backpack);
        backpack.clear();
        for (Food &f:temp) {
            if (f.name() == "sandwich" || f.name() == "kebab") {
                if (pre==(-1)) {
                    pre = g;
                    prods -= 1;
                }
                else {
                    if(post == (-1)) {
                        post = g;
                        prods -= 1;
                    }
                    else {
                        foodVec.emplace_back(g);
                    }
                }
            }
            else if (f.name() == "beer") {
                beerVec.emplace_back(g);
            }
            else if (f.name() == "vodka") {
                vodkaVec.emplace_back(g);
            }
            else if (f.name() == "jupik") {
                jupikVec.emplace_back(g);
            }
            g++;
        }

        if (pre != (-1)) {
            backpack.emplace_back(temp[pre]);
        }
        while(!beerVec.empty()) {
            backpack.emplace_back(temp[beerVec.back()]);
            beerVec.pop_back();
        }
        while(!vodkaVec.empty()) {
            if(!jupikVec.empty()) {
                backpack.emplace_back(temp[jupikVec.back()]);
                jupikVec.pop_back();
            }
            backpack.emplace_back(temp[vodkaVec.back()]);
            vodkaVec.pop_back();
            if(!foodVec.empty()) {
                backpack.emplace_back(temp[foodVec.back()]);
                foodVec.pop_back();
            }
        }
        while(!jupikVec.empty()) {
            backpack.emplace_back(temp[jupikVec.back()]);
            jupikVec.pop_back();
        }
        while(!foodVec.empty()) {
            backpack.emplace_back(temp[foodVec.back()]);
            foodVec.pop_back();
        }
        if(post!=(-1)) {
            backpack.emplace_back(temp[post]);
        }
        isSorted=true;
    }
    void addProduct() {
        int which;
        while(true) {
            which = rand() % 5 + 1;
            if (which==1 && bac>2.5) { continue;}
            else if(which==5 && bac>3.2) { continue;}
            if(products<5) {
                break;
            }
            else{
                if(bac<2.5) {
                    while(which!=1) {
                        which=rand()%5+1;
                    }
                }
                break;
            }
        }

        switch (which) {
            case 1: {
                backpack.emplace_back(std::ref(v));
                break;
            }
            case 2: {
                backpack.emplace_back(std::ref(j));
                break;
            }
            case 3: {
                backpack.emplace_back(std::ref(k));
                break;
            }
            case 4: {
                backpack.emplace_back(std::ref(s));
                break;
            }
            case 5: {
                backpack.emplace_back(std::ref(b));
                break;
            }
            default:
                break;
        }
        bac+=backpack.back().get().getBac();
        cash+=backpack.back().get().getCash();
        products++;
    }

private:
    int products;
    bool isSorted;
    double bac;
    double cash;
    std::vector<std::reference_wrapper<Food>> backpack;
    Vodka v;
    Beer b;
    Sandwich s;
    Jupik j;
    Kebab k;

    bool isFull() {return products>=7;}
};

int main() {
    srand(time(nullptr));
    Backpack plecak;
    plecak.fillBackpack();
    plecak.sortProducts();
    plecak.showBackpack();

}