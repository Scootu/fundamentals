#include <iostream>
#include <stdlib.h>
using namespace std;

struct list
{
    int info;
    list *next;
};

void print(list *list1)
{

    while (list1 != nullptr)
    { // Check if the list is not empty
        cout << list1->info << " ";
        list1 = list1->next;
    }
}
void printR(list *list1)
{
    if (list1 == nullptr)
        return;

    cout << list1->info << " ";

    printR(list1->next);
}

void printReverse(list *l)
{
    if (l == nullptr)
        return;

    printReverse(l->next);
    cout << l->info << " ";
}
int main()
{
    // fill list
    int n;

    printf("Enter your number of elements : \n");
    cin >> n;
    printf("Fill your array element by element \n");

    list *list1 = nullptr; // Initialize list1 to nullptr
    list *p = nullptr;

    for (int i = 0; i < n; i++)
    {
        list *newl = new list; // allocate new element
        printf("%d : ", i + 1);

        cin >> newl->info;
        newl->next = nullptr;

        if (list1 == nullptr)
        { // First element
            list1 = newl;
            p = newl;
        }
        else
        {
            p->next = newl; // Link the previous node to the current one
            p = newl;       // Move pointer p to the current node
        }
    }

    printR(list1); // Print the list
    cout<< "\n" ; 
    cout<< "Print in reverse order \n";
    printReverse(list1);
    return 0;
}
