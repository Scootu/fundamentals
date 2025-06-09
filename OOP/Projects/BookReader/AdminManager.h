#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H
#include "Admin.h"
#include "Book.h"
#include <map>
#include <vector>
#include "BookManager.h"
using namespace std;

class AdminManager
{
private:
    // map<Admin,vector<User>> Adminobject_usersObject_map;
    Admin current_Admin;
    int last_id;
    map<string, Admin> adminName_AdminObject_map;
    BookManager bookManagerSystem;

public:
    AdminManager();
    void LoadDatabase();
    void AccessSystem();
    void DoLogin();
    void DoSignUp();
    const Admin &GetCurrentAdmin() const
    {
        return current_Admin;
    }
    void AddNewBook()
    {
        bookManagerSystem.AddNewBook(current_Admin);
        adminName_AdminObject_map[current_Admin.GetAdminName()] = current_Admin; // updatedatabase
    }
    void UpdateDatabase();
    void ResetBooksIdtoAdmin()
    { // to Update the books_ids_from_admin
        current_Admin.ResetBooksIdsFromAdmin();
    }
    void PrintMyBooksIdsList()
    {
        const vector<Book> &books = bookManagerSystem.GetlistofBooks(current_Admin);
        if (books.size() == 0)
        {
            cout << "No books \n";
        }
        else
        {
            for (const auto &book : books)
            {
                book.Print();
            }
        }
    }
    ~AdminManager(){
        cout<<"Admin manager destructor!\n";
    }
};
#endif