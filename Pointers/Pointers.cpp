#include <iostream>

using namespace std;

int main()
{
    int val3 = 15 ;
    int *ptr3 = &val3;
    cout << val3 <<endl;
    cout << &val3 << endl;
    cout << ptr3 << endl ;
    cout << *ptr3 << endl;
    cout << &ptr3 << endl;
    cout << "Pointers and arrays"<<endl;
    int arr[5] = {10,20,30,40,50};

// compiler creates an internal POINTER for and stores the array's starting address
    cout << arr << "\n";    // 0xc4765ff880
    cout << &arr[0] << "\n";  // 0xc4765ff880: get address of 1st value

// int *pArr = arr[0]; // Wrong, arr[0] is not address
    int *pArr = &arr[0];   // Point to 1st element.
    // We can do also: int *pArr = arr;

    cout << *pArr << "\n";    // 10
    cout << pArr << "\n";   //0xc4765ff880
    cout << &pArr << "\n";   // 0x4779bffb98


    for(int i =0 ; i < 5 ; ++i)
    {
        //All following SAME value
        cout << arr[i] << " ";  //normal array usage
        cout << pArr[i] << " ";  // use it as if an array
        cout <<*(arr+i) << " "; // Move i integers from arr, and get value
        cout <<*(pArr+i) << " "; // change address => dereference value
        // *(pArr+i) NOT  same as *pArr+i
        cout << "\n";
    }
    pArr++;
    cout << *pArr<< "\n"; // We can increment pointer => 20
//arr++;      // compile ERROR
    cout <<"Pointers Arithmatic"<<endl;
    int val1 = 5 ;
    int val2 = 6 ;
    int *ptr1 = &val1;
    int *ptr2 = &val2;
    cout << ptr1 - ptr2 << endl;   // 1
    // int arr[5] = {10,20,30,40,50};
    int *ptr = arr+2; //point to 3rd element, 30
    int val;

    cout << ptr - arr << "\n";   //we can subtract => 2

    val = *ptr++;   // use pointer value in val, then increment pointer address

    cout <<val<< " " << ptr - arr << endl ;

    ptr = arr+2;   // point to 3
    val = *++ptr;  // increment pointer address, then use pointer value in val

    cout << val << " " << ptr- arr <<endl; // 40 3

    ptr = arr+2 ;    // point to 3
    val = *ptr--;  // use pointer value in val, then decrement pointer address

    cout << val << " " << ptr - arr << endl ;  // 30 1

    ptr = arr + 2 ;

    val = *--ptr;
    cout << val << " " << ptr - arr <<endl ; // 20 1

    ptr = arr + 2 ;
    val = (*ptr)++;
// it's affect the arrays value , 10 20 31 40 50
    cout << val<< " " << ptr - arr << endl ; // 30 2
    int arr1[]= {1,2,3,4,5};
    ptr = arr1+2 ;
    *ptr = 8;
    ptr = arr1;
    while(ptr != arr1+5)
        cout <<*ptr++<<" "; // print and move to next
    cout << "Const and pointers"<<endl;

    val1 = 20 ;

    int *ptr5 = new int;
    *ptr5 = 10 ;   // Can change data, it is no constant
    ptr5 = &val1;  // Can change pointer, it is not constant

    const int* ptr7 = new int;
// *ptr7 = 20; // Can't do that. Constant data

    const int* ptr8 = &val1;
// *ptr8 = 20;    //Can't do that. Constant data

    ptr8 = ptr1 ; // Can change pointer, it is not constant

    int* const ptr4 = new int;
    *ptr4 = 20 ; // Can change data, it is no constant
// ptr4 = ptr1 ;  // can't do that .pointer is constant

    const int* const ptr9 = &val1;

// *ptr9 = 20 ; // Can't do that. Constant data
// ptr9 = ptr1; //Can't do that. Pointer is constant

    const char* name = "hello";  // later, string class
    cout << "Variable alias"<<endl;
    int value = 131363 ;

    cout << "Size :" << sizeof(value)<<"\n";
    cout << "Value : "<<value<<"\n";
    cout << "Address :" << &value<< "\n";  //0xa6851ff91c

    int cpy = value;
    int &ref = value;
    cout <<&ref<<"\n" ; // 0xa6851ff91c
// => Any NEW variable has its OWN address ... may points to other variables

    value += 10 ;

    cout  << cpy << "\n";      //131363
    cout << ref << "\n";       // 131373  this is very weird

    ref *= 10 ;
    cout << value << "\n";        //1313730
    /*
    int someVal = 10 ;

    long &valRef1 = someVal;    // Wrong. Same type needed

    short &valRef2  = someVal;

    int &a = someVal , &b = someVal , c = someVal;

    // & => Automatic dereference
    cout <<"Alias vs Pointer"<<endl;

    void fun1 (int &a) {}
    void fun2 (const int &a) {}
    void fun3 (int *a) {}

    int main() {
    int x = 10;
    int *y = new int;

    fun1(x);
    //fun1(y);  can't send pointer
    //fun1(5);  can't send constant
    fun2(x);
    //fun2(y);  can't send pointer
    fun2(5);

    fun3(&x);
    fun3(y);
    fun3(5);       //can't send constant
    */


    return 0 ;
}
