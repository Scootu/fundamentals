#include <iostream>

using namespace std;

int rBinary(int n){
    if(n == 0) return 0;
    return n%2 + rBinary(n/2) * 10 ; 
}
int Binary(int n){
    int i= 1 , r = 0 , s = 0 ;
    while (n != 0)
    {
        r = n % 2 ; 
        n = n / 2 ; 
        s = s + r * i ; 
        i = i * 10;
    }
    return s ;
    
}
int main(){ 
    cout <<Binary(55)<<endl;
    cout<<rBinary(55)<<endl;
    return 0;
}