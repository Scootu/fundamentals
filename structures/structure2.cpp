#include <iostream>

using namespace std;

struct Employee
{
    string name;
    int salary;

    Employee(int my_salary, string my_name)    // constructor
    {
        sayCreating();

        salary = my_salary;
        name = my_name;
        name_length = name.size();
    }

    void print();

    void SetSalary(int value)   // Method NOT Function
    {
        salary = value;
    }

    void AddSalary(int value);
    bool operator == (const Employee &b)
    {
        return name == b.name && salary == b.salary;
    }
    bool operator < (const Employee &b)
    {
        if (name != b.name)
            return name < b.name;
        return this-> salary < b.salary; // this pointer
    }


    ~Employee()    // Destructor
    {
        cout << "Destroying the object\n";
    }
private:
    int name_length;

    void sayCreating()
    {
        cout <<"Object creation\n";
    }
};

void Employee::AddSalary(int value)   //  We can define method outside too
{
    salary += value;
}

void Employee::print()
{
    cout << name << " has salary " << salary << " name length " <<name_length<<  "\n";
}

void print()
{
    cout << "Function to say hello \n";
}

int main()
{
    print();
    Employee emp(2000,"Ali");
    emp.print();

    emp.SetSalary(100);
    emp.print();

    emp.AddSalary(35);
    emp.print();


    return 0;
}
