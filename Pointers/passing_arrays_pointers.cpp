#include <iostream>

using namespace std;
// test 1, 2, 3 are actually SAME for compiler
void test1(int arr[]) {}  // pointer to an element
void test2(int arr[5]) {} // pointer to an element
void test3(int *ptr) {}  // pointer to an element

void test4(int (&arr)[5]) {} // reference to an array. Force array of size 5

int main()
{
    cout << "Passing arrays / pointers \n";
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    test1(arr);
    test2(arr);
    test3(arr);

    int x = 10;
    test2(&x);
    //test4(&x);
    //test4(ptr);
    test4(arr);

    int arr2[3] = {1, 2, 3};
    //test4(arr2);
    /*
    cout << passing arrays and pointers <<endl;
    void test1(int arr[][10]){}   // pointer to an array
    void test3(int (*ptr)[10]){}
    void test4(int (&arr)[10][30]{}  // reference to an array
     // Force array of size 30 x 10
    we can use **ptr2d to create this without adding the second dimention
    to access arr[2][3] 2 *10 + 3
    void test2(int** ptr2d){}

    */
    const int SIZE = 10 ;
    int arr1[SIZE]; // Good - Fixed size

    int n = 20;
//    int arr2[n];   // Variable size - NOT standard - DON'T use

// Don't cast between primitives..unless you know what you really do
    short shortVal1 = 1;
    int *pIntPtr1 = (int*)&shortVal1;
    *pIntPtr1 = 2147483647;
    cout <<*pIntPtr1<<"\n"; // my crash now

// Don't get part of the memory!
// This is true for little endian but not big endian!
    int value = 770; // 11 00000010
    char secondByte = *(((char *)&value) + 1 ); // right way using bits (later)
    cout <<(int)secondByte<<"\n";  // 3 on Intel x86 processor (little endian)

// Don't use C style case -No compiler time checking
// Use static case
   int *pIntPtr2 = static_cast<int*>(&shortVal1);   //Compiler error

    return 0;
}
