#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    cout << "CALCULATOR V 1.0" << endl;
    cout << "Enter the first number" << endl;
    int iNum1 = 0;
    cin >> iNum1;
    while (cin.fail())
    {
        cout << "Invalid input try again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> iNum1;
    }
    cout << "Enter the second number" << endl;
    int iNum2 = 0;
    cin >> iNum2;
    while (cin.fail())
    {
        cout << "Invalid input try again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> iNum2;
    }
    cout << "Enter your operation type character \n";
    char cO = '1';
    cin >> cO;
    while (cin.fail() || (cO != '+' && cO != '-' && cO != '*' && cO != '/'))
    {
        cout << "Invalid input, repeat again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cO;
    }
    switch (cO)
    {
    case '+':
        cout << "the result of addition of " << iNum1 << " + " << iNum2 << " = " << iNum1 + iNum2 << endl;
        break;
    case '-':
        cout << "the result of subtraction of " << iNum1 << " - " << iNum2 << " = " << iNum1 - iNum2 << endl;
        break;
    case '*':
        cout << "the result of multiplication of " << iNum1 << " * " << iNum2 << " = " << iNum1 * iNum2 << endl;
        break;
    case '/':
        if (iNum2 == 0)
        {
            cout << "You can't divide by 0, Enter the second number again \n";
            cin >> iNum2;
            while (cin.fail())
            {
                cout << "Invalid input try again" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> iNum2;
            }
            cout << "the result of division of " << iNum1 << " / " << iNum2 << " = " << (float)iNum1 / iNum2 << endl;
        }
        else
        {
            cout << "the result of division of " << iNum1 << " / " << iNum2 << " = " << (float)iNum1 / iNum2 << endl;
        }
        break;
    }
    cout << "End of calculation";

    return 0;
}
