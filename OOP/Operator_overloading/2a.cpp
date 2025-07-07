#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
};
class MyPair : public Base
{
private:
    int first, second;

public:
    MyPair() {}
    MyPair(int first, int second) : first(first), second(second)
    {
    }
    void print()
    {
        cout << "(" << first << "," << second << ")\n";
    }
    int GetFirst() const
    {
        return first;
    }
    void SetFirst(int first)
    {
        this->first = first;
    }
    int GetSecond() const
    {
        return second;
    }
    void SetSecond(int second)
    {
        this->second = second;
    }
    int operator[](int pos) const
    {
        if (pos == 0)
            return first;
        return second;
    }

    int &operator[](int pos)
    {
        if (pos == 0)
            return first;
        return second;
    }
    MyPair(const MyPair &another) : first(0),second(0)
    {
        first = another.first; // copy constructor
        second = another.second;
    }

    MyPair &operator=(const MyPair &another)
    { // assignment operator
        if (this == &another)
            return *this;
        Base::operator=(another);

        // Do remain of your assignment
        first= another.first;
        second =  another.second;
        return *this;
    }

    friend istream &operator>>(istream &in, MyPair &other);
    friend ostream &operator<<(ostream &ou, const MyPair &other);
};
istream &operator>>(istream &in, MyPair &other)
{
    in >> other.first >> other.second;
    return in;
}
ostream &operator<<(ostream &ou, const MyPair &other)
{
    ou << other.first << " " << other.second << "\n";
    return ou;
}
MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}
int main()
{
    int v;
    cin >> v;

    string str;
    cin >> str;

    MyPair x;
    cin >> x;
    cout << x;
    return 0;
}