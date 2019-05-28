
#include<iostream>
#include<array>
#include<map>
#include<vector>
class IterableIterator {

public:
    virtual IterableIterator &Next()= 0;
    virtual std::pair<int, std::string> Dereference()= 0;
    virtual bool NotEquals(IterableIterator &other)= 0;
    virtual ~IterableIterator() = default;
};

class ZipperIterator :public IterableIterator {
private:
    std::vector<int>::const_iterator leftCurrent;
    std::vector<int>::const_iterator leftBegin;
    std::vector<int>::const_iterator leftEnd;
    std::vector<std::string>::const_iterator rightCurrent;
    std::vector<std::string>::const_iterator rightBegin;
    std::vector<std::string>::const_iterator rightEnd;
public:
    explicit ZipperIterator(std::vector<int>::const_iterator left_begin,
                            std::vector<std::string>::const_iterator right_begin,
                            std::vector<int>::const_iterator left_end,
                            std::vector<std::string>::const_iterator right_end)
                            {
        this->leftCurrent=left_begin;
        this->leftBegin=left_begin;
        this->leftEnd=left_end;
        this->rightCurrent=right_begin;
        this->rightBegin=right_begin;
        this->rightEnd=right_end;
    }
    ZipperIterator &Next() override{
        if(leftCurrent!=leftEnd)
            leftCurrent++;
        if(rightCurrent!=rightEnd)
            rightCurrent++;
        return *this;
    };
    std::pair<int, std::string> Dereference() override {
        return {*leftCurrent,*rightCurrent};
    }
    bool NotEquals(IterableIterator &other) override {
        return (this->Dereference()!=other.Dereference());
    }
    void Iterate() {
        bool done[2] = {false,false};
        while(!done[0] || !done[1]) {
            if(!done[0])
                std::cout<<"lewy: "<<Dereference().first;
            if(!done[1])
                std::cout<<", prawy: "<<Dereference().second;
            std::cout<<std::endl;
            Next();
            if(leftCurrent==leftEnd) {
                done[0]=true;
            }
            if(rightCurrent==rightEnd) {
                done[1]=true;
            }
        }

    }
};


int main() {
    const std::vector<int> v1 ={1,2,3,4,5,6,7,8,9};
    const std::vector<std::string> v2 ={"a","b","c","d","e","f","g","h","i","g","d"};
    ZipperIterator z = ZipperIterator(v1.begin(),v2.begin(),v1.end(),v2.end());
    z.Iterate();

}