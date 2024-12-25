#include <iostream>

using namespace std;

int i = 0; // global variable to track the levels

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle() : Rectangle(0.0, 0.0) {
        // Delegating constructor
    }

    Rectangle(double width, double height) : width(width), height(height) {
        // Parameterized constructor
    }

    Rectangle(double width) : width(width), height(0) {
        // Constructor with one parameter
    }

    ~Rectangle(){
        printf("Out of scope, Level %d \n", i);
    }
};

void scooplv3() {
    Rectangle r2;  // Object created in scooplv3
    i++;           // Increment level before printing
    printf("Level %d\n", i);
}

void scooplv2() {
    Rectangle r2;  // Object created in scooplv2
    i++;           // Increment level before printing
    printf("Level %d\n", i);
}

void scooplv1() {
    Rectangle r1;  // Object created in scooplv1
    i++;           // Increment level before printing
    printf("Level %d\n", i);
}

int main() {
    Rectangle r0; // Object created in main
    cout << "Level 0 \n";   
    scooplv1();
    scooplv2();
    scooplv3();

    // Once all functions finish, destructors are called when each scope ends.
    return 0;
}
