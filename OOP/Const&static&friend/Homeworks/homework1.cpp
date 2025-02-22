#include <iostream>

using namespace std;

class A; // Forward declaration of A

class B
{
private:
    static int x; // Static member variable
    static A a;   // Static instance of class A
public:
    B(int y)
    {
        B::x = y;
    }

public:
    friend class A; // Friend class, allowing A to access private members

    static A &getA() { return a; } // Public getter for static A
};

class A
{
public:
    void print(B &b)
    {
        cout << B::x; // Accessing static member properly
    }
};

// Define static members outside the class
int B::x = 5;
A B::a;

int main()
{
    B b(10);            // Create instance of B
    B::getA().print(b); // Correct way to access static A and call print()
    return 0;
}
