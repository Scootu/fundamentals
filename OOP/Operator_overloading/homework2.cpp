#include <string>
#include <iostream>

using namespace std;

string operator*(const string& a,int x){
    string result;
    for(int i = 0; i < x;i++){
        result += a ;
    } 
    return result;
}
int main()
{
    string a = "bad";
    string b = "I am " + a * 3 + ", right?";
    cout << b; // I am badbadbad, right?
}
