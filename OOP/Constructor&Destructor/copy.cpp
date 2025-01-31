#include <iostream>

using namespace std;

class MyNumber
{
private:
    int *val1;
    int val2;

public:
    MyNumber(int x = 3, int y = 5)
    {
        cout << "Normal constructor\n";
        val1 = new int; //
        *val1 = x;
        val2 = y;
    }
    MyNumber(const MyNumber &another)
    {
        cout << "Copy constructor\n";
        val1 = new int; // Allocate new address
        *val1 = *another.val1;
        val2 = another.val2;
    }
    ~MyNumber()
    {
        cout << "Val 1 deleted! \n";
        delete val1;
    }
    void PrintValueAndAddress()
    {
        cout << "Val1: " << *val1 << " " << val1 << "\n";
        cout << "Val2: " << val2 << " " << &val2 << "\n\n";
    }
};
void run(MyNumber a)
{
    MyNumber b(a); // why destructor work here ? 
    a.PrintValueAndAddress();
    b.PrintValueAndAddress();
    // Temperator constructor
}
int main()
{
    MyNumber a;
    run(a); //
    a.PrintValueAndAddress();
    return 0;
}