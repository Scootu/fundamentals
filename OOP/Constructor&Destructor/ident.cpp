#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;

class A {
public:
    A() = default; // default constructor

    A(const A& rhs) {
        cout << "Copy was made"<< endl;
    }
};

class B {
public:
    A data;
    int foo;

    B(A data, int foo) : data(data), foo(foo) {
    }
};

int main() {
    A data;

    B foo(data, 10);

    return 0;
}