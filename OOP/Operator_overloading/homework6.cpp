#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

class MyMap
{
private:
    vector<string> vect_strs;
    vector<int> vect_ints;

    int pos = 0;

public:
    int &operator[](const string &str)
    {
        for (int i = 0; i < (int)vect_strs.size(); ++i)
        {
            if (vect_strs[i] == str)
            {
                return vect_ints[i];
            }
        }
        vect_strs.push_back(str);
        vect_ints.push_back(0);
        return vect_ints.back();
    }

    vector<string> operator[](int value)
    {
        vector<string> result;
        for (int i = 0; i < (int)vect_ints.size(); ++i)
        {
            if (vect_ints[i] == value)
            {
                result.push_back(vect_strs[i]);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
    void Reset_iterator()
    {
        pos = 0;
    }
    void Clear(){
        vect_strs.clear();
        vect_ints.clear();
        pos = 0;
    }
    bool HasNext()
    {
        return pos < (int)vect_ints.size();
    };
    pair<string, int> GetNext()
    {
        assert(HasNext());
        auto p = make_pair(vect_strs[pos], vect_ints[pos]);
        pos++;
        return p;
    }
};
int main()
{
    MyMap map;
    map["mostafa"] = 20;
    map["mostafa"] = 40;
    map["sayed"] = 20;
    map["ali"] = 20;

    cout << map["mostafa"] << "\n"; // 40

    vector<string> v = map[20];
    for (auto s : v)
        cout << s << "\n"; // ali sayed

    map.Reset_iterator();
    while (map.HasNext())
    {
        auto p = map.GetNext();
        cout << p.first << " " << p.second << "\n";
    }
    map.Clear();
    return 0;
}