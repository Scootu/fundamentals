#include <bits/stdc++.h>
#include <string>
#include <stdexcept>
using namespace std;

// Custom Exception Class
class Invalid_Input : public exception
{
    string message;

public:
    Invalid_Input(const string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class MyVector
{
private:
    int *arr; //
    int len = 100;

public:
    MyVector(int len, int default_value = 0)
    {
        this->len = len;
        this->arr = new int[len];

        for (int i = 0; i < len; ++i)
        {
            this->arr[i] = default_value;
        }
    }
    MyVector(const MyVector &another)
    {
        this->len = another.len;
        this->arr = new int[len];
        for (int i = 0; i < len; ++i)
        {
            this->arr[i] = another.arr[i];
        }
    }
    ~MyVector()
    {
        delete[] this->arr;
        this->arr = nullptr;
    }
    int get(int pos)
    {
        if (pos < 0 || pos >= this->len)
            throw Invalid_Input("Access not allowed at position: " + to_string(pos));
        return this->arr[pos];
    }
    void printArrayContent()
    {
        for (int i = 0; i < len; ++i)
        {
            if (i % 10 == 0)
            {
                printf("\n");
            }
            printf("%d ", this->arr[i]);
        }
    }
};

int main()
{
    MyVector a(100, 5);
    MyVector b(a);
    a.~MyVector(); // Call destructor
    b.printArrayContent();
    int n, t;
    printf(" \nEnter pos to get value : \n");
    scanf("%d", &n);
    t = b.get(n);
    printf("The pos %d is : %d", n, t);

    /*
    cout << " a : \n ";
    a.printArrayContent(); // don't access data that previously deleted
    */
    return 0;
}