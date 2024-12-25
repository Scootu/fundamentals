#include <iostream>

using namespace std;

class A
{
public:
    A() { std::cout << "A initialized\n"; }
    virtual ~A() { std::cout << "A destructed\n"; }
};

class B : virtual public A
{
public:
    B() { std::cout << "B initialized\n"; }
    virtual ~B() { std::cout << "B destructed\n"; }
};

class C : virtual public A
{
public:
    C() { std::cout << "C initialized\n"; }
    virtual ~C() { std::cout << "C destructed\n"; }
};

class D : public B, public C
{
public:
    D() { std::cout << "D initialized\n"; }
    virtual ~D() { std::cout << "D destructed\n"; }
};

int main()
{
    D d; // The output will show A initialized first
}
