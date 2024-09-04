#include <iostream>
#include <algorithm>
using namespace std;

void printArr(const int* list, int size) // const data or int* const list -> const pointer
{
    const int* ptr = new int;
    ptr = list; // invalid conversion from 'const int*' to 'int*' [-fpermissive]|
    while(ptr != list + size)
        cout <<*ptr++<<" ";
    cout << endl;
}

int main()
{
    int list[] = {4, 2, 3, 6, 5, 1};
    printArr(list,6);

    int* min = min_element(list, list + 6);
    int* max = max_element(list, list + 6);
    cout << "The min value is " << *min << " at index "<< (min - list) << endl;
    cout << "The max value is " << *max << " at index "<< (max - list) << endl;

    random_shuffle(list, list + 6);
    printArr(list, 6);

    sort(list, list + 6);
    printArr(list,6);

    int key = 4;
    int* p = find(list, list + 6, key);
    if (p != list + 6)
        cout << "The value " << *p << " is found at position "<< (p - list) << endl;
    else
    cout << "The value " << *p << " is not found" << endl;

    return 0 ;
}
