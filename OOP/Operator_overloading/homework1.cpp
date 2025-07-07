#include <iostream>
#include <vector>
using namespace std;

vector<int> operator+(const vector<int>& a, const vector<int>& b)
{
    const vector<int>& longer = (a.size() >= b.size()) ? a : b;
    const vector<int>& shorter = (a.size() < b.size()) ? a : b;

    vector<int> result = longer;

    for (size_t i = 0; i < shorter.size(); ++i)
    {
        result[i] += shorter[i];
    }

    return result;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {10, 20};

    vector<int> c = a + b;

    for (int val : c)
        cout << val << " "; // Output: 11 22 3 4

    return 0;
}
