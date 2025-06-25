#include <iostream>
#include <string>
using namespace std;

class DecoratedString : public string {
public:
    
    using string::string;

    // Decorate the string
    void decorate() {
        // Assign to the base string directly, not to *this
        string str = *this;
		str = "<<[[" + str + "]]>>";

        this->assign(str); // Use assign() method
    }

    // Custom comparison operator
    bool operator==(const string& other) const {
        return this->compare(other) == 0;
    }
}; 

int main() {
    DecoratedString str("I am learning CS");
    str.decorate();

    // Avoid ambiguity by using string for comparison
    cout << (str == string("<<[[I am learning CS]]>>")) << endl; // should print 1 (true)

    return 0;
}