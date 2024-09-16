#include <iostream>

using namespace std;

int main(int argc,char *argv[]){

    cout<<"Total received arguments are: "<<argc<<"\n";

    for (int i = 0 ; i< argc;++i)
        cout<<i<<"-th argument: "<<argv[i]<<"\n";


    return 0 ;
}
