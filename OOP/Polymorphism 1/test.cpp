#include <iostream>
using namespace std;

class Person {
    public:
    virtual void print() {cout << "Person \n";};
    virtual ~Person() {cout << "~Person\n";};
};

class Student: public Person {
    public:
    void print() { cout << "Student\n";};
    ~Student(){cout << "~Student\n";};
};

int main(){

    Person* stud_ptr3 = new Student();
    stud_ptr3->print();
    stud_ptr3->Person::print();

    delete stud_ptr3;
}
