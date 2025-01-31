#include <iostream>

using namespace std;


int main(){
    int i1 = 1 ,i2 = 1, r = 0;
    int N = 155 ;
    int c = 0 ; // why we start counting from 0 not from 1 ? i canno't understand if i switch this to 1 n1 will have odd number and n2 have the even numbers why this important ?
    int n1 =0, n2=0 ;
    while(N != 0){
        r = N % 2 ; 
        N = N / 2 ; 
        if(c % 2 == 0){
            n1 = r*i1 + n1;
            i1 = i1 *10;
        }else {
            n2 = r*i2 +n2;
            i2 = i2 * 10 ;
        }
        c = c +1 ;
    }
    cout << n1 <<" "<<n2 <<endl; // n1 for even number and n2 for odd number 
    return 0;
}