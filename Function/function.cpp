#include <iostream>

using namespace std;

template <class type1, class type2>
type1 f(type1 a,type2 b){
    return a * b ;
}
// Template function definition
template <class type1, class type2>
auto f1(type1 a, type2 b) -> decltype(a * b) {
    return a * b;
}
//Recursive function
int factoriel(int n){
    if(n == 1)
        return 1;
    return n * factoriel(n-1);
}

int main(){
    int x = 5;
    double y = 3.9;
    auto result = f1(x, y);
    cout << "Result: " << result << endl; //it's return the larger type of them
    cout <<factoriel(3)<<endl; // 6
    return 0 ;
}
