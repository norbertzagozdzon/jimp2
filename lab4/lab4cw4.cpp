#include <iostream>
#include<string>
using std::cout;
using std::string;
using std::endl;

class Name {
public:
    explicit Name(const string &name, const string &surname): name_(name),secondName_(""),thirdName_(""), surname_(surname) {}
    explicit Name(const string &name,const string &secondName, const string &surname) : name_(name), secondName_(secondName),thirdName_(""), surname_(surname) {}
    explicit Name(const string &name, const string &secondName,const string &thirdName, const string &surname) : name_(name), secondName_(secondName),thirdName_(thirdName),surname_(surname) {}
    string FirstName() const {return name_;}
    string SecondName() const {return secondName_;}
    string ThirdName() const {return thirdName_;}
    string Surname() const {return surname_;}
    string ToFullInitials() const {
        string initialz = "";
        initialz+=name_[0];
        initialz+=". ";
        if (secondName_!="") {
            initialz+=secondName_[0];
            initialz+=". ";
        }
        if (thirdName_!="") {
            initialz+=thirdName_[0];
            initialz+=". ";
        }
        initialz+=surname_[0];
        initialz+=".";
        return initialz;

    }
    string ToFirstNamesInitials() const {
        string finals = "";
        finals+=name_[0];
        finals+=". ";
        if (secondName_!="") {
            finals+=secondName_[0];
            finals+=". ";
        }
        if (thirdName_!="") {
            finals+=thirdName_[0];
            finals+=". ";
        }
        finals+=surname_;
        return finals;

    }
    string ToSurnameNames() const {
        string finals = surname_+" "+name_+" ";
        if (secondName_!="") {
            finals+=secondName_+" ";
        }
        if (thirdName_!="") {
            finals+=thirdName_;
        }
        return finals;
    }
    string ToNamesSurname() const {
        string finals = name_+" ";
        if (secondName_!="") {
            finals+=secondName_+" ";
        }
        if (thirdName_!="") {
            finals+=thirdName_+" ";
        }
        finals+=surname_;
        return finals;
    }
    bool IsBeforeBySurname(const Name &other) const {
        int size;
        if (other.surname_.length()>surname_.length())
            size=surname_.length();
        else
            size=other.surname_.length();
        for(int i=0;i<size;i++) {
            if(other.surname_[i]>surname_[i])
                return true;
            else if (surname_[i]>other.surname_[i])
                return false;
        }
        return false;
    }
    bool IsBeforeByFirstName(const Name &other) const {
        int size;
        if (other.name_.length()>name_.length())
            size=name_.length();
        else
            size=other.name_.length();
        for(int i=0;i<size;i++) {
            if(other.name_[i]>name_[i])
                return true;
            else if (name_[i]>other.name_[i])
                return false;
        }
        return false;
    }
private:
    const string name_;
    const string surname_;
    const string secondName_;
    const string thirdName_;
};
int main() {
    Name n1 = Name("Thomas","Cucumber");
    Name n2 = Name("Thomas","Jorge","Cucumber");
    Name n3 = Name("Thomas","Jorge","Jelly","Cucumber");
    Name n4 = Name("Allah","Zorbing");
    cout<<n3.ToFullInitials()<<endl;
    cout<<n3.ToFirstNamesInitials()<<endl;
    cout<<n3.FirstName()<<endl;
    cout<<n3.SecondName()<<endl;
    cout<<n3.ThirdName()<<endl;
    cout<<n3.Surname()<<endl;
    if(n3.IsBeforeByFirstName(n4))
        cout<<"Imie "<<n3.FirstName()<<" jest pierwsze od imienia "<<n4.FirstName()<<"."<<endl;
    else
        cout<<"Imie "<<n3.FirstName()<<" nie jest pierwsze od imienia "<<n4.FirstName()<<"."<<endl;
    if(n3.IsBeforeBySurname(n4))
        cout<<"Nazwisko "<<n3.Surname()<<" jest pierwsze od nazwiska "<<n4.Surname()<<"."<<endl;
    else
        cout<<"Nazwisko "<<n3.Surname()<<" nie jest pierwsze od nazwiska "<<n4.Surname()<<"."<<endl;
}