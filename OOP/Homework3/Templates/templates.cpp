#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::swap;
// One function works for all data types. This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

// A template function to implement bubble sort.
// We can use this for any data type that supports
// comparison operator < and swap works for it.
template <class T> void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

template <typename T> class Array {
private:
    T* ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
    delete [] ptr;
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

int main(){
    cout << myMax(7,8)<<"\n";
    cout << myMax(7.5,8.9)<<"\n";
    cout << myMax('g','c')<<"\n";
    //
    int a[5] = { 10, 50, 30, 40, 20 }; // size of a is array type * total element number
    int n = sizeof(a) / sizeof(int);
    
    // calls template function
    bubbleSort<int>(a, n);
    cout << " Sorted array : ";
    /*
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
    */
    Array<int> b(a,5);
    b.print();

    return 0;
}