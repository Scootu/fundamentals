#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class MyPair
{
private:
    int first, second;

public:
    MyPair(int first, int second) : first(first), second(second)
    {
    }
    virtual void print() const
    {
        cout << "(" << first << "," << second << ")\n";
    }
    virtual int GetFirst() const
    {
        return first;
    }
    virtual void SetFirst(int first)
    {
        this->first = first;
    }
    virtual int GetSecond() const
    {
        return second;
    }
    virtual void SetSecond(int second)
    {
        this->second = second;
    }
    virtual int operator[](int pos) const
    {
        if (pos == 0)
            return first;
        return second;
    }

    virtual int &operator[](int pos)
    {
        if (pos == 0)
            return first;
        return second;
    }
    virtual bool operator<(const MyPair &a) // 4 < 5 -> true
    {
        return tie(first, second) < tie(a.first, a.second);
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

class NamedPair : public MyPair
{
private:
    string name;

public:
    NamedPair(const string &name, const int &first, const int &second)
        : MyPair(first, second), name(name) {}

    void print() const override
    {
        cout << "(" << name << ": " << GetFirst() << "," << GetSecond() << ")\n";
    }

    bool operator<(const NamedPair &a) const 
    {
        return tie(name, GetFirst(), GetSecond()) < tie(a.name, a.GetFirst(), a.GetSecond());
    }
};

int main()
{
    vector<MyPair> vec;
    vec.push_back(MyPair(10, 20));
    vec.push_back(MyPair(10, 7));
    vec.push_back(MyPair(1, 200));

    sort(vec.begin(), vec.end());

    for (auto &pair : vec)
        pair.print();

    vector<NamedPair> vec1;
    vec1.push_back(NamedPair("A", 10, 20));
    vec1.push_back(NamedPair("B", 10, 7));
    vec1.push_back(NamedPair("B", 1, 200));

    sort(vec1.begin(), vec1.end());

    for (auto &pair : vec1)
        pair.print(); // Output: (A: 10,20) (B: 1,200) (B: 10,7)
    return 0;
}
