#include <stdlib.h>
#include <iostream>

using namespace std;

int factorial(int n)
{
     if(n <=1)
        return 1;

     return n * factorial(n-1);
}

int main(int argsCount, char *arguments[]) {

    if(argsCount !=2)
    {
         cerr<<"Usage: n - Integer to compute its factorial\n";
         return 1;
    }
    int n = atoi(arguments[1]); //convert char* to int

    cout<<n<<"! = "<<factorial(n)<<"\n";

    return 0;
}
