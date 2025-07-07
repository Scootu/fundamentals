#include <iostream>
#include <vector>
using namespace std;

class MyPair
{
private:
    int first, second;

public:
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
};

MyPair operator+(const MyPair &c1, const MyPair &c2)
{
    return MyPair(c1.GetFirst() + c2.GetFirst(),
                  c1.GetSecond() + c2.GetSecond());
}
MyPair operator+(int x, const MyPair &c1)
{
    return MyPair(c1.GetFirst() + x, c1.GetSecond() + x);
}

int main()
{
    MyPair x(1, 2);
    MyPair y(10, 20);

    // MyPair z = x.Add(y);
    MyPair z = x + y;
    MyPair u = 3 + z;
    z.print(); // (11,22)
    u.print(); // (14,25)
    MyPair x1(10, 20);

    cout << x1[0] << " " << x1[1] << "\n";
    return 0;
}
