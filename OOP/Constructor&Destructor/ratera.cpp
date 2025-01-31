#include <iostream>
#include <stdlib.h>
using namespace std;

int sumT(int *T, int a, int b, int n)
{
    if (n == -1)
    {
        return 0;
    }

    if (T[n - 1] >= a && T[n - 1] <= b)
    {
        return T[n - 1] + sumT(T, a, b, n - 1);
    }
    else
    {
        return sumT(T, a, b, n - 1);
    }
}
int main()
{
    int n;
    cout << "Enter your number of elements n \n";
    cin >> n;
    int *T = new int[n];
    for (int i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        cin >> T[i];
    }
    int a, b, sum;
    sum = 0;
    do
    {
        cout << "Enter a :\n";
        cin >> a;
        cout << "Enter b :\n";
        cin >> b;
    } while (a > b);
    sum = sumT(T, a, b, n);
    printf("The total sum of your array in the interval [%d - %d] is %d", a, b, sum);
    return 0;
}