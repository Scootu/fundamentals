#include <iostream>
#include <string>

using namespace std;


class Boolean {
private:
  bool is_true;

public:
   Boolean(bool is_true) : is_true(is_true) { }
   bool operator &&(const Boolean &other) const {
        return this->is_true && other.is_true;
   }

};

bool T() {cout << "T\n"; return true;}
bool F() {cout << "F\n"; return false;}

Boolean TC() { cout << "TC\n"; return Boolean(true);}
Boolean FC() { cout << "FC\n"; return Boolean(false);}


int main() {
    F() && T(); // false && true -> false call F() short circuting behavior
    FC() && TC(); //  non short circuting behavior 
}