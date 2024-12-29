#include <iostream>
#include <memory>
using namespace std;

class A {
private:
    int *x;
public:
    A() {
        cout << "A constructor\n";
        x = new int;
        *x = 10;
    }

    ~A() {
        cout << "A destructor\n";
        delete x;
    }
};

int main() {
    auto a = make_unique<A>(); // Automatically manages memory smart pointer 
    return 0; // No need for delete, memory is automatically freed
}
