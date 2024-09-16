#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <memory>
using namespace std;
//Variadic functions

// To resolve case when sum list eis empty
int sum()
{
    return 0;
}

// Function takes at least 1 parameter, and remaining list
// Recursive sum
template<typename T,typename ... Args>

T sum(T a, Args ... args)
{
    return a + sum(args...);
}

vector<int> compute()
{
    return {2, 5, 7};
};

//Dynamic memory management
//With shared pointers
void add1(shared_ptr<int> p)
{
    // internal count 2 .. one more looking at me
    *p += 1;
}    // internal count 1 .. go out scope
int main()
{
    vector<int> values = {2, 3,5, 7};
    vector<string> strings = {"Mostafa", "Saad"};
    pair<int, int> myPair = {20,27};

    map<int, string> numeral =
    {
        {0, "zero"},
        {1, "one"}
    };

    map<string, pair<int,int>> mp
    {
        {"ali", {10, 20}},
        {"hassan", {20, 27}}
    };
//Without range loop
    //map<string, pair<int,int>> mp;
    /*
    for(auto it =mp.begin(); it != mp.end(); ++it)
        cout<<it->first<<" "<<it->second.first<<"\n";

            vector<int> numbers = {2, 3, 5, 7};

    for(int i =0; i< numbers.size(); ++i)
        numbers[i] *=2;
    */
    for (auto val : mp)
        cout << val.first<< " "<<val.second.first<< endl;

    vector<int> numbers = {2, 3, 5, 7};

    for (auto& x: numbers)  // & update
        x*= 2;
    for(auto x : numbers)
        cout << x << " ";
    cout << endl;

// And more with your defined staff

    tuple <int,char> foo(10,'x');

    auto bar = make_tuple("test", 3.1,14, 'y');

    get<2>(bar) = 100;         //access element

    int myint;
    char mychar;

//unpack elements
    tie (myint, mychar) = foo;
// unpack (with ignore)
    tie (ignore,ignore, myint, mychar) = bar;

    mychar = get<3>(bar);

    get<0>(foo) = get<2>(bar);
    get<1>(foo) = mychar;

    cout<<"foo contains: ";
    cout<< get<0>(foo) << ' ';
    cout<< get<1>(foo) <<'\n';


    cout <<"sum 1 : "<< sum(5.3,7,2.3,2) << "\n";
    cout<< sum(3,4) << "\n";


// A will have copy content as compute,
// and then compute is freed...meaningless!

    vector<int> A = compute();

//Move take what in A to B. A now empty
    vector<int> B = move(A);

// C has what is compute...cmpute return is empty
    vector<int> C = move(compute());

    shared_ptr<int> p1(new int);
    *p1 = 10; // internal count 1

    add1(p1);

    cout<<*p1<<"\n";  // 11




    return 0; // internal count 0 .. go out scope
}
