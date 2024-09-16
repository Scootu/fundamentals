#include <iostream>
#include <iomanip>
#include <limits>
#include "resourse.h"


using namespace std;

void StartingSys(int* choice)
{
    cout << "Please make a choice:" << "\n";
    cout << "     "  << "1 - Login" << "\n";
    cout << "     "  << "2 - Sign up" << "\n";
    cout << "     "  << "3 - Shutdown system" << "\n";
    cout << "     "  << "Enter Choice: ";
    cin>>*choice;
}

bool checkUserFun(const string& userName, const string& password, Person*& user);
void loginFun()
{
    string userName, password;
    Person* user;
    bool isValid = false;

    do
    {
        cout << "Please enter user name and password:\n";
        cout << "User Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, userName);
        cout << "Password: ";
        cin>>password;
        // Check if the username and password are valid
        isValid = checkUserFun(userName, password,user);

        if (!isValid)
        {
            cout << "Invalid username or password. Please try again.\n";
        }
        else
        {
            handlePerson(user);
        }

    }
    while (!isValid);    // Continue until valid credentials are provided
}


bool checkUserFun(const string& userName,const string& password, Person*& user) // *& modify the pointer address it self
{
    auto it = studentDataCenter.begin();
    for (; it != studentDataCenter.end(); ++it)
    {
        // Use the iterator to access the current Student
        if (it->fullName == userName)
        {
            if (it->password == password)
            {
                user = &(*it); // Assign the address of the found Student
                return true;
            }
        }
    }
    auto it2 = doctorsDataCenter.begin();
    for (; it2 != doctorsDataCenter.end(); ++it2)
    {
        // Use the iterator to access the current Student
        if (it2->fullName == userName)
        {
            if (it2->password == password)
            {
                user = &(*it2); // Assign the address of the found Student
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    user = nullptr;
    return false;
}
int main()
{
    bool logOut = false;
    do
    {
        int userChoice;
        StartingSys(&userChoice);
        switch(userChoice)
        {
        case 1:
            loginFun();
            break;
        case 2:
            cout<<"2"<<endl;
            break;
        case 3:
            logOut = true;
            break;
        default:
            cout<<"Non of the choices!"<<endl;
            StartingSys(&userChoice);
            break;
        }
    }
    while(!logOut);

    return 0;
}
