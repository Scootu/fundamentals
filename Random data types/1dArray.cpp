#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;
/*
     * in :Array
     * out:2nd larger number in the arr
     *
     */
int get2ndNum(int arr[],int size)
{
    assert(size >= 2); // If the size of the array is less than 2 the program will step
    int i1stNum = arr[0];
    int i2ndNum = arr[1];

    if(i2ndNum > i1stNum)
        swap(i2ndNum,i1stNum);

    for(int i = 2 ;i<size;++i){
        if(i1stNum < arr[i]){
            i2ndNum = i1stNum;
            i1stNum = arr[i];
        }else if(arr[i] > i2ndNum){
            i2ndNum = arr[i]; // what is the point
        }else {
        }
    }

    return i2ndNum;

}
int main(){
    char name[] = "Ali";
    cout <<"Enter your name"<<endl;
    cin >>name;
    cout <<name<<endl;
    int arr[] = {98,65,44,23,96,1002,6};
    cout <<"The second largest number is : "<<get2ndNum(arr,7)<<endl;
    return 0 ;
}
