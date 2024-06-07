#include <iostream>

using namespace std;

int main(){
    //Fibonacci series
    for(int i = 0,a = 1, b =2,temp = 0;i < 10 && a < 60;++i,temp = a + b,a =b, b =temp)
        cout << a<< " ";
    cout <<"\n";

    return 0;

}
