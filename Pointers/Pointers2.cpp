#include <iostream>

using namespace std;


int** create()
{
    int **ptr2d = new int*[3];
    for (int i =0; i< 3; ++i)
    {
        ptr2d[i] = new int[2];

        for (int j = 0; j < 2; ++j)
            ptr2d[i][j] = (i+1)*(j+1);
    }
    return ptr2d;
}
void print(int **arr)     // pass as parameter
{
    for (int i =0 ; i < 3; ++i)
    {
        for (int j = 0 ; j < 2; ++j)
            cout << arr[i][j]<<" ";
        cout<<"\n";
    }
}

void free(int **arr)
{
    for (int i =0 ; i< 3; ++i)
        delete[] arr[i];
    delete[] arr;
}
/*
int buggyPointers(int a, int b)
{
    int *ptr1 = new int[8], *ptr2 = new int[8], *ptr3 = new int[8];
    int *salary;    // bad practice => garbage
    int *grade = NULL;    // best practice

    if(a==0) return 1;   //Forget to release memory => Leak

    delete ptr1;   // WRONG, it should be delete[]
    ptr1 = NULL;       // best practice
//so even if we delete pointer the ptr still exist with it's data type
    int *ptr = ptr2;
    ++ptr;  //move to the next address
    delete []ptr;     // Wrong, delete from array start

    delete []ptr3;
    ptr3[2] = 5;    // WRONG, memory deleted!
    delete []ptr3;   //WRONG, double free problem

    delete grade;     //It is NULL, no problem/benefit
    *grade = 10;      // WRONG, it is not initialized!
    grade = new int;   // one element
    delete[] grade;   //WRONG, should be delete NOT delete[]
}
*/

int main()
{
    cout<<"New / Delete operators"<<endl;

    int num_employee;
    cin >>num_employee;

    int *employee_salaries = new int[num_employee];
    // Old style: int employee_salaries[1000];
// Use employee_salaries as if it is normal array
    for (int i =0; i <num_employee; ++i)
        cin >> employee_salaries[i];
//Use the array in some processing
    delete[] employee_salaries;

    float *pFloat = new float;

    *pFloat= 10.5;    // 0x293bc716f60 10.5
    cout <<pFloat<<" "<< *pFloat<<"\n";

    delete pFloat;
    cout <<"Array of pointers"<<endl;
    int arr2d[3][2];
    int *arr[3] = {0};  // array of 3 pointers - initialized to NULL
    int** ptr2d = {0};
    for(int i = 0 ; i < 3; ++i)
        arr[i] = new int[2];    // pointer to 2 elements

// Now use the arr as if 3x2 matrix
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
        {
            arr[i][j] = arr2d[i][j]  = i*2+j ;
            cout << arr[i][j]<<endl;
        }

    for (int i =0; i < 3; ++i)
        delete[] arr[i];

    cout <<"Pointer to pointer"<<endl;
    int** ptr2d1 = create(); // Array of pointers
    print(ptr2d1);
    free(ptr2d1);
    //Best practise
    int* task = NULL;
    task = new int;
    *task = 5;
    cout << *task << endl;
    delete task;
    //task = NULL;
    int* s_task = new int(10);
    cout << *s_task<<endl; // 10
    cout << *task<<endl;  // ? 10
    delete s_task;
    // so you need to do this
    s_task = NULL;
    task = NULL;

    return 0 ;
}
