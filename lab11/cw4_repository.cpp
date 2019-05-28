#include<vector>
#include <iostream>

template<class T>
class Repository {
protected:
    unsigned int nextId;
public:
    Repository(): nextId(0){}
    virtual unsigned int size()= 0;
    virtual T operator[](unsigned int)=0;
    virtual unsigned int NextId() = 0;
    virtual int FindBy(std::string Query) =0;
};
class Building {
private:
    unsigned int id;
    std::string name;
public:
    std::string getName() const {return name;}
    void setName(std::string name) {
        this->name=name;
    }
    void setId(unsigned int id) {
        this->id = id;
    }
    unsigned int getId() {return id;}
    friend std::ostream & operator<<(std::ostream &out,const Building &b) {
        return out<<b.getName();
    }

};
class BuildingRep: public Repository<Building> {
private:
    std::vector<Building> rep;
public:

    BuildingRep(const std::vector<Building>& b) {
        rep = b;
        for (int i=0;i<rep.size();i++) {
            rep[i].setId(NextId());
        }
    }
    unsigned int size() override {return rep.size();}
    Building operator[](unsigned int index) override  {
        return rep[index];
    }
    unsigned int NextId() override {
        return ++nextId;
    }
    int FindBy(std::string Query) override {
        for(int i=0;i<size();i++) {
           if(rep[i].getName()==Query) return rep[i].getId();
        }
        return -1;

    }

};

int main() {
    Building b1;
    b1.setName("siema");
    std::vector<Building> brep;
    brep.push_back(b1);
    //td::cout<<brep[0];
    auto buildings = BuildingRep(brep);
    std::cout<<buildings[0];
    std::cout<<buildings.FindBy("siema");
}