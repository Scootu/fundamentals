#include <iostream>

class A {
    public:
    virtual ~A() {};
};

class B : public A {};
class C : public A {};
class D {};

void static_cast_test(){
    //Complite time check/cast
    A* a_from_b = new B();
    // No problem. Valid conversion 
    B* b = static_cast<B*>(a_from_b);
    std::cout<< b << "\n";
    //Wrong conversion, but u get pointer 
    C* c = static_cast<C*>(a_from_b);

    //Compilation error can be caught for such clear case
    //D* d = static_cast<D*>(a_from_b);
}
void dynamic_cast_test(){
    // Run time conversion using RTTI
    A* a_from_b = new B();

    // No problem. Valid converison 
    B* b = dynamic_cast<B*>(a_from_b);
    std::cout << b << "\n";
    
    // Wrong conversion, pointer = nullptr
    C* c = dynamic_cast<C*>(a_from_b);
    // Wrong conversion, pointer = nullptr
    D* d = dynamic_cast<D*>(a_from_b);
    std::cout << d<<"\n";
}


