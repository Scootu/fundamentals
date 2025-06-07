#ifndef ADMIN_H
#define ADMIN_H
#include <iostream>
#include <string>
#include <vector>
#include "Helper.h"
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
    //map<int, vector<Book>> adminId_booksObject_map;

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

    void ResetBooksIdsFromAdmin(const vector<int>& books_from){
         books_ids_from_admin.clear();

         for(const auto& book_id:books_from){
            books_ids_from_admin.push_back(book_id);
         }
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
    const vector<int>& GetBooksIdsFromAdmin() const
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
        SetName(admin_name);
        SetAdminId(id);

        string str;

        cout << "Enter password: ";
        cin >> str;
        SetPassword(str);

        cout << "Enter your fullname: ";
        cin >> str;
        SetAdminName(str);
    }
    string ToString() const
    {
        ostringstream oss;
        string str;

        // Convert vector<int> to comma-separated string
        for (size_t i = 0; i < books_ids_from_admin.size(); i++)
        {
            if (i != 0)
            {
                str += ",";
            }
            str += to_string(books_ids_from_admin[i]);
        }

        oss << admin_id << ", \"" << admin_name << "\"," << password << "," << name << "," << email << ",{" << str << "}";

        return oss.str();
    }
};

#endif