#include <iostream>

using namespace std;

int main()
{
    int n;

    do
    {
        cout << "Enter your integer numbre : " << endl;
        cin >> n;
    } while (n < 0);
    cout << "Your numbers is : " << endl;
    while (n > 0)
    {

        int i = n;
        do
        {
            int r1 = i % 10;
            i = i / 10;

            int r2 = i % 10;
            i = i / 10;
            if (r1 < r2)
            {
                i = 1;
                break;
            }

        } while (i > 0);
        if (i == 0)
        {
            cout << n << endl;
        }
        n = n - 1;
    }
    return 0;
}