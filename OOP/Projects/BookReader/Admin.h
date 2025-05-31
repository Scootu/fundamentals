#ifndef ADMIN
#define ADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include "Helper.cpp"
using namespace std;
class Admin
{
private:
    int admin_id;
    string admin_name;
    string password;
    string name;
    string email;

    vector<int> books_ids_from_admin;

public:
    Admin() : admin_id(-1), admin_name(""), password(""), name(""), email("") {}
    Admin(const string &line)
    {
        vector<string> substrs = SplitString(line, ",", true);
        if (substrs.size() != 6)
        {
            throw invalid_argument("Invalid admin data format");
        }

        admin_id = ToInt(substrs[0]);
        admin_name = substrs[1];
        password = substrs[2];
        name = substrs[3];
        email = substrs[4];
        books_ids_from_admin = SplitBooksids(substrs[5]);
    }
    // Gettters
    int GetAdminId() const
    {
        return admin_id;
    }
    string GetAdminName() const
    {
        return admin_name;
    }
    string GetName() const
    {
        return name;
    }
    string GetEmail() const
    {
        return email;
    }
    string GetPassword() const
    {
        return password;
    }
    vector<int> GetBooksIdsFromAdmin() const
    {
        return books_ids_from_admin;
    }
    // Setters
    void SetAdminId(const int &id)
    {
        admin_id = id;
    }
    void SetAdminName(const string &name)
    {
        admin_name = name;
    }
    void SetName(const string &name_)
    {
        name = name_;
    }
    void SetEmail(const string &email_)
    {
        email = email_;
    }
    void SetPassword(const string &password_)
    {
        password = password_;
    }
    void Print() const;
    void ReadAdmin(const string &admin_name, int id)
    {
        SetAdminName(admin_name);
        SetAdminId(id);

        string str;

        cout << "Enter password: ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name: ";
        cin >> str;
        SetName(str);
    }
};

#endif