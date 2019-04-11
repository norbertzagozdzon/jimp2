#include<iostream>
#include<vector>

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::vector;

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

class Student {
    private:
        string id;
        string firstName;
        string lastName;
        string program;
        StudyYear *year;
    public:
        explicit Student(const string &id, const string &firstName, const string &lastName, const string &program, StudyYear *year) {
            this->id = id;
            this->firstName = firstName;
            this->lastName = lastName;
            this->program = program;
            this->year = year;
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

};
class StudentRepository{
    private:
        vector<Student*> studentRepository;
    public:
        void addStudent(Student *student) {
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
    StudyYear rok = StudyYear(2);
    StudyYear rok1 = StudyYear(5);
    Student marek = Student("303186","Romuel","Sarmahhn","java",&rok);
    Student tomek = Student("5348287","Tomasz","Algad","python",&rok1);
    StudentRepository rep;
    rep.addStudent(&marek);
    rep.addStudent(&tomek);
    cout<<rep;
    marek.setFirstName("Rammzah");
    cout<<rep[0];
}
