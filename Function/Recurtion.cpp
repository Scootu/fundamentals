#include <iostream>

using namespace std;

void SayIamTopCoder(int cnt)
{
    if(cnt < 1)      //base case
        return;

    cout <<"I am TopCoder.\n"; // logic

    SayIamTopCoder(cnt - 1); // Sub-problem
}

void Traingle(int cnt)
{
    if(cnt <= 0)
        return;
    Traingle(cnt - 1);
    for(int i = 0 ;i<cnt ;i++){
        cout <<"*";
    }
    cout <<"\n";

}

int main(){
    SayIamTopCoder(5);
    Traingle(5);
    return 0 ;
}
