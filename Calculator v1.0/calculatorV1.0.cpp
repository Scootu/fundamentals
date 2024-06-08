#include <iostream>
#include <iomanip>

using namespace std;
void fCheckNumb(double &iNum)
{
    cin >> iNum;
    while (cin.fail())
    {
        cout << "Invalid input try again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> iNum;
    }
}
void fCheckOperation(char &cO)
{
    cin >> cO;
    while (cin.fail() || (cO != '+' && cO != '-' && cO != '*' && cO != '/'))
    {
        cout << "Invalid input, repeat again" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cO;
    }
}
int main()
{
    cout << "CALCULATOR V 1.0" << endl;
    cout << "Enter the first number" << endl;
    double iNum1 ,iNum2= 0;
    fCheckNumb(iNum1);
    cout << "Enter the second number" << endl;
    fCheckNumb(iNum2);
    cout << "Enter your operation type character \n";
    char cO = '/';
    fCheckOperation(cO);
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
        if ((int)iNum2 == 0)
        {
            cout << "You can't divide by 0, Enter the second number again \n";
            fCheckNumb(iNum2);
            cout << "the result of division of " << iNum1 << " / " << iNum2 << " = " << iNum1 / iNum2 << endl;
        }
        else
        {
            cout << "the result of division of " << iNum1 << " / " << iNum2 << " = " << iNum1 / iNum2 << endl;
        }
        break;
    }
    cout << "End of calculation";

    return 0;
}
