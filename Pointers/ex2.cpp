#include <iostream>

using namespace std;
/*
int* solve_wrong()
{
    int arr[] = {1, 2, 3, 4};
    int *ptr = arr;

    // do some staff

    // can't return arr...it will be freed in stack
    return ptr;
}

int* solve_right()
{
    int *ptr = new int[4];

    // do some staff

    return ptr; // caller responsible to free
}
*/
void printArr(int* ptr,int* arr1,int size1){
  while(ptr != arr1+size1)
        cout <<*ptr++<<" "; // print and move to next
  cout << endl;
}
int* getPosNums1(int* arr, int arrSize,int& outPosArrSize);
void getPosNums2(int* arr, int arrSize,int*& outPosArr, int& outPosArrSize);
int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums4(int* arr, int arrSize,int** outPosArrPtr, int* outPosArrSizePtr);

int main(){
    int *ptr = new int;
    int arr[] = {-1,2,-3,4,5,-9,8};
    int size1 = 7;
    ptr = getPosNums1(arr,7,size1);
    //ptr++;

    cout <<*(ptr+0) << " size : "<< size1<<endl;

    printArr(ptr,ptr,size1);

    int outPossize1 = 0  ;
    int *outPosArr1 = nullptr; // Dynamic allocation memory

    getPosNums2(arr,7,outPosArr1,outPossize1);
    int *ptr1 = outPosArr1; // You don't need to free memory hear with this pointer
    printArr(ptr1,ptr1,outPossize1);
    int* ptr3 = new int;
    int* outPosArrSizePtr = new int;
    ptr3 = getPosNums3(arr,7,outPosArrSizePtr);
    printArr(ptr3,ptr3,*outPosArrSizePtr);

    int* outPosArr4 = nullptr;
    getPosNums4(arr,7,&outPosArr4,outPosArrSizePtr);
    int* ptr4 = outPosArr4;
    printArr(ptr4,ptr4,*outPosArrSizePtr);

    delete ptr;

    delete ptr3;
    delete ptr4;

    delete outPosArr1;
    delete outPosArr4;
    delete outPosArrSizePtr;
    return 0 ;
}
int* getPosNums1(int* arr,int arrSize,int& outPosArrSize)
{
    int* ptr = new int;
    int* fPtr = ptr;
    for(int i = 0 ; i < arrSize;++i){
        if(arr[i] > 0){
             *ptr = arr[i];
              ptr++; // move to the next pointer
        }
    }
    outPosArrSize = (ptr - fPtr) ;
    return fPtr;
}
void getPosNums2(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
{
    // First, calculate how many positive numbers there are
    int count = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            ++count;
        }
    }

    // Allocate memory for positive numbers
    delete[] outPosArr; // Free previous memory if necessary
    outPosArr = new int[count];
    outPosArrSize = count;

    // Fill the array with positive numbers
    int index = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] > 0) {
            outPosArr[index++] = arr[i];
        }
    }
}

int* getPosNums3(int* arr, int arrSize, int* outPosArrSizePtr){
     int* ptr = new int;
     int* fPtr = ptr;
     for(int i =0; i < arrSize;++i){
        if(arr[i] > 0){
            *ptr = arr[i];
            ptr++;
        }
     }
     int val = (ptr - fPtr);
     *outPosArrSizePtr = val;
     return fPtr;
}
/*
void getPosNums4(int* arr, int arrSize,int** outPosArrPtr, int* outPosArrSizePtr){
     int* ptr = new int;
     int* fptr = ptr;
     int index = 0 ;
     for(int i = 0 ; i < arrSize;++i){
        if(arr[i] > 0){
            outPosArrPtr[index++] = const_cast<int*>(&arr[i]);
        }
     }
     *outPosArrSizePtr = (ptr - fptr);
}
*/
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr,int* outPosArrSizePtr){
    int* newArr = new int[arrSize];
    int newIndx = 0;
    for (int i = 0; i < arrSize; i++){
        if (arr[i] > 0){
            newArr[newIndx] = arr[i];
            newIndx++;
        }
    }
    *outPosArrPtr = newArr;
    *outPosArrSizePtr = newIndx;
}
