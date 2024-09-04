#include <iostream>
#include <algorithm>
using namespace std;

struct Employee
{
    string name;
    int salary;
    int position;
};

union EmployeSalary {
      // only one type available
      int iVal;
      double dVal;
      //string szVal;       => Illegal in c++98, legal in C++0x
};
// Writing wrong function may case RTE
// When return true, means first object must come before second object
// If we called cmp(A, B) and returned true, NEVER have cmp(B, A) = true
// If A == B, then both cmp(A, B) and cmp(B, A) MUST give false

bool cmp(const Employee &first, const Employee &second) // comapre function
{    // The right comparision should be filed by field based on YOUR priority

     // if first field NOT equal, then it determines the answer
     if(first.salary != second.salary)
        // Let bigger salary be preferred
        return first.salary > second.salary;


     // Now same salary, name to name
     if(first.name != second.name)
        return first.name < second.name;

     // Now, the remaining is the position. DIRECTLY comare here.
     return first.position < second.position;
}
int sum(int n, int m)  {
    return n+m;
}

int mul(int n, int m) {
    return n*m;
}
// pointer to function that takes two integers
int (*functionPtr)(int,int);

int compute(int a, int b, int (*functionPtr)(int,int))
{
    return (*functionPtr)(a, b);
}

int main()
{
    cout << "Objects using pointers \n";
    Employee* pEmp = nullptr;
    pEmp = new Employee;

// access using arrow operator NOT dot operator

    pEmp->name = "mostafa";
    pEmp->salary = 150;


    delete pEmp;    // otherwise, similar to primitives

    Employee emps[5] =
    {
        {"baher",70,5}, {"zyad", 99, 10}, {"ali", 70, 2},
        {"baher", 70,5}, {"baher", 70, 3}
    };
    // cmp function: Let sort based on, bigger salary,
    // if tie smaller name, if tie smaller position

    sort(emps, emps+5,cmp);

    for (int i =0; i < 5; ++i)
    {
        Employee &emp = emps[i];
        cout << emp.salary<< " "<<emp.name<< " "<< emp.position<<"\n";
    }
    functionPtr = &sum; // address of function
    int val = (*functionPtr)(2, 5);

    val = compute(2, 5, mul);

    // array of pointers to function
    int (*p[2])  (int x, int y);
    p[0] = sum;
    p[1] = mul;
    val = (*p[0])(3, 7);

    EmployeSalary salary;

    salary.iVal = 50;
    cout << salary.iVal << "\n";   //Use ONLT intriguer version

    salary.dVal = 15.5;
    cout << salary.dVal << "\n";   //Use ONLT double version

     // You can remove = 6 and it will be initialized from 0.
       // Remaining values are +1 for previous
    enum color {RED =6, GREEN, BLUE};
    cout <<RED<<" "<<GREEN<< " "<<BLUE<<"\n"; // 6 7 8

    int val1 = RED ; // 6

    color whichColor;
    //whichColor = 7;     can't
    whichColor = BLUE;
    whichColor = color(8);  // same as BLUE

    enum varity {zero, another_zero =0, big =100, small = 50, what};
    cout<<what<<"\n";   // 51
    return 0 ;
}
