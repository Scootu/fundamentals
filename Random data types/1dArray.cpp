#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
/*
     * in :Array
     * out:2nd larger number in the arr
     *
     */
void print(int arr[],int size)
{
    for(int i = 0 ; i< size;i++){

        cout << arr[i] <<" ";
    }

    cout <<endl ;

}
int get2ndNum(int arr[],int size)
{
    assert(size >= 2); // If the size of the array is less than 2 the program will step
    int i1stNum = arr[0];
    int i2ndNum = arr[1];

    if(i2ndNum > i1stNum)
        swap(i2ndNum,i1stNum);

    for(int i = 2 ; i<size; ++i)
    {
        if(i1stNum < arr[i])
        {
            i2ndNum = i1stNum;
            i1stNum = arr[i];
        }
        else if(arr[i] > i2ndNum)
        {
            i2ndNum = arr[i]; // what is the point
        }
        else
        {
        }
    }

    return i2ndNum;

}
vector<int> slidingWindow(int arr[], int size, int k)
{
    int Max = INT_MIN;
    vector<int> arr2(k);  // Use a vector to store the result window

    for (int p = 0; p < k; ++p)
    {
        Max += arr[p];
    }
    int sum = Max ;
    for(int i = 1;i< size - k +1;i++){
        sum = sum - arr[i-1] + arr[i+k-1];
        if (Max < sum)
        {
            Max = sum;
            for (int p = i, j = 0; p < k + i; ++p, ++j)
            {
                arr2[j] = arr[p]; // Get the k elements of the array
            }
        }
    }

    return arr2;
}
void fSortArray(int arr[],int size)
{
     int fNum = arr[0];
     int temp = arr[1];
     if(fNum > temp){
        swap(arr[0],arr[1]);
     }
     for(int i = 2 ;i< size;++i){
        int temp = arr[i];
        for(int j = 0;j<i;++j){
            if(temp < arr[j]){
                swap(arr[i],arr[j]);
            }
        }
     }
    print(arr,size);
}
void TestSlidingWindows()
{
     int arr[1000] , arr2[3];
     vector<int> arr3(3);
     for(int i = 0 ;i< 1000;i++){
        arr[i] = rand() ; // [0-99]
     }
     sort(arr,arr+1000);
     for(int i =0 ;i<3;i++){
        arr2[i] = arr[1000 - 3 + i];
     }
     arr3 = slidingWindow(arr,1000,3);
     for(int i =0;i<3;i++){
        cout <<arr3[i]<<" ";
     }
     cout << endl;
     assert(arr2[0] == arr3[0]);

     cout <<"Perfect!"<<endl;

}
vector<int> sortedArrays(int arr1[],int size1,int arr2[],int size2)
{
    int idx1,idx2,res = 0 ;
    vector<int> result(size1 + size2);
    while(idx1 < size1 && idx2 < size2){
        if(arr1[idx1] < arr2[idx2]){
            result[res++] = arr1[idx1++];
        }else {
            result[res++] = arr2[idx2++];
        }
    }
    while(idx1 < size1){
        result[res++] = arr1[idx1++];
    }
    while(idx2 < size2){
        result[res++] = arr2[idx2++];
    }
    return result;
}
void TestingSortedArrays(){
    int arr1[1000] ;
    int arr2[1000] ;
    int arr3[2000];
    vector<int> arr4(2000);
    for(int i = 0;i< 1000;++i){
        arr1[i] = rand();
        arr2[i] = rand();
    }
    //Sorting arrays values
    sort(arr1,arr1+1000);
    sort(arr2,arr2+1000);
    //Copy arrays values in the new array
    for(int i =0 ; i< 1000;++i){
        arr3[i] = arr1[i];
    }
    for(int i = 1000,j=0;i<2000;++i,++j){
        arr3[i] = arr2[j];
    }
    sort(arr3,arr3+2000);
    arr4 = sortedArrays(arr1,1000,arr2,1000);
    //Check values
    bool passed = true;
    for(int i =0;i<2000;++i){
        passed = (arr4[i] == arr3[i]);
        if(!passed){
            cout <<arr4[i]<<" "<<arr3[i]<<" position: "<<i<<endl;
            assert(false);
            break;
        }
    }
    if(passed)
    cout << "Perfect Sorted Arrays function work"<<endl;
}
int main()
{
    char name[] = "Ali";
    cout <<"Enter your name"<<endl;
    cin >>name;
    cout <<name<<endl;
    int arr[] = {98,65,44,44,6,23,96,1002,6};
    cout <<"The second largest number is : "<<get2ndNum(arr,9)<<endl;

    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr2) / sizeof(arr2[0]);
    int k = 3;

    vector<int> result = slidingWindow(arr2, size, k);

    cout << "Max sum window: ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    TestSlidingWindows();
    int arr5[] ={ 7 , 5};
    fSortArray(arr,9);
    TestingSortedArrays();
    return 0 ;
}
