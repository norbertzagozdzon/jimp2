#include<iostream>
#include<vector>
#include<regex>
#include<exception>

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::vector;
using std::regex;
using std::smatch;
using std::regex_match;
using std::invalid_argument;
using std::cin;

class StudyYear {
    friend class Student;
private:
    int studyYear;
public:
    explicit StudyYear() {
        studyYear=0;
    }
    explicit StudyYear(int studyYear) {
        this->studyYear = studyYear;
    }
    StudyYear& operator ++() {
        studyYear++;
        return *this;
    }
    StudyYear& operator ++(int) {
        return ++*this;
    }
    bool operator==(const StudyYear &s) {
        return this->studyYear==s.studyYear;
    }
    bool operator<(const StudyYear &s) {
        return this->studyYear<s.studyYear;
    }
    int getYear() {
        return studyYear;
    }
    friend ostream& operator <<(ostream &out, const StudyYear &s) {
        out<<s.studyYear;
        return out;
    }
    friend istream& operator >>(istream &in, StudyYear &s) {
        in>>s.studyYear;
        return in;
    }
};

class WrongStudentNameSurname :public invalid_argument{
    string err;
public:
    WrongStudentNameSurname() : invalid_argument("blad w imieniu lub nazwisku"){
        err = "blad w imieniu lub nazwisku";
    }
    void er() {
        cout<<err<<endl;
    }
};
class WrongStudentYear :public invalid_argument{
    string err;
public:
    WrongStudentYear() :invalid_argument("blad w wieku studenta"){
        err = "blad w wieku studenta";
    }
    void er() {
        cout<<err<<endl;
    }

};
class WrongProgram :public invalid_argument{
    string err;
public:
    WrongProgram() :invalid_argument("blad w kierunku"){
        err = "blad w kierunku";
    }
    void er() {
        cout<<err<<endl;
    }

};
class WrongStudent :public invalid_argument{
    string err;
public:
    WrongStudent() :invalid_argument("..."){
        err = "...";
    }
    void er() {
        cout<<err<<endl;
    }

};

class Student {
private:
    string id;
    string firstName;
    string lastName;
    string program;
    StudyYear *year;
public:
    explicit Student(const string &id, const string &firstName, const string &lastName, const string &program, StudyYear *year) {
        try {
            validateStudent(id,firstName,lastName,program,*year);
            this->id = id;
            this->firstName = firstName;
            this->lastName = lastName;
            this->program = program;
            this->year = year;
        }
        catch(WrongStudentNameSurname &e) {
            cout<<e.what()<<endl;
        }
        catch(WrongStudentYear &e) {
            cout<<e.what()<<endl;
        }
        catch(WrongProgram &e) {
            cout<<e.what()<<endl;
        }
    }
    ~Student() {
        cout<<"... wiec zostaje zniszczony..."<<endl;
    }
    bool operator==(Student &s) {
        return this->id==s.id && this->firstName==s.firstName && this->lastName==s.lastName && this->program==s.program && this->year->getYear()==s.year->getYear();
    }
    friend ostream& operator<<(ostream &out, Student &s) {
        out<<"Student {id: ,,"<<s.id<<"\", first_name: ,,"<<s.firstName<<"\", last_name: ,,"<<s.lastName<<"\", program: ,,"<<s.program<<"\", year: "<<s.year->getYear()<<" }";
        return out;
    }
    friend istream& operator>>(istream &in, Student &s) {
        in>>s.id;
        return in;
    }
    void setFirstName(string name) {
        firstName=name;
    }
    string getFirstName() {
        return firstName;
    }
    void validateStudent(const string &id, const string &firstName, const string &lastName, const string &program, StudyYear year) {
        regex wzor = regex("^[A-Z]{1}[a-z]{1,}$");
        smatch matches;
        if(!regex_match(firstName,matches,wzor) || !regex_match(lastName,matches,wzor)) {
            throw WrongStudentNameSurname();
        }
        else if(year.studyYear<10 || year.studyYear>100) {
            throw WrongStudentYear();
        }
        else if(program!="informatyka" && program!="ekonomia" && program!="matematyka" && program!="fizyka" && program!="filozofia") {
            throw WrongProgram();
        }
    }

};
class StudentRepository{
private:
    vector<Student*> studentRepository;
public:
    void addStudent(Student *student) {
        if (student->getFirstName()=="")
            throw WrongStudent();
        else
            studentRepository.push_back(student);
    }
    friend ostream& operator<<(ostream &out, StudentRepository &rep) {
        out<<"[ ";
        for (auto &s: rep.studentRepository) {
            cout<<*s<<", ";
        }
        out<<"]"<<endl;
        return out;
    }
    bool operator==(StudentRepository &rep) {
        for(int i=0;i<rep.studentRepository.size();i++) {
            if (this->studentRepository[i]==rep.studentRepository[i])
                continue;
            else
                return false;
        }
        return true;
    }
    Student& operator[](int iterator) {
        return *this->studentRepository[iterator];
    }
};

int main() {
    StudyYear rok = StudyYear(15);
    StudyYear rok1 = StudyYear(5);
    StudentRepository rep;
    Student marek = Student("303186","Romuel","Sarmahhn","filozofia",&rok);
    while(true) {
        string id,imie,nazwisko,kierunek;
        int rok;
       cout<<"podaj dane(id,imie,nazwisko,kierunek,wiek) : "<<endl;
       cin>>id>>imie>>nazwisko>>kierunek>>rok;
       StudyYear rokk = StudyYear(rok);
       Student x = Student(id,imie,nazwisko,kierunek,&rokk);
       try {
           rep.addStudent(&x);
       }
       catch (WrongStudent &e) {

       }
    }
    cout<<rep;
}
