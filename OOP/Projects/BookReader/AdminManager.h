#ifndef ADMINMANAGER
#define ADMINMANAGER_H
#include "Admin.h"
#include "Book.h"
#include <map>
#include <string>

using namespace std;

class AdminManager
{
private:
    // map<Admin,vector<User>> Adminobject_usersObject_map;
    Admin current_Admin;
    int last_id;
    map<string,Admin> adminName_AdminObject_map;
    BookManager bookManagerSystem;
    
public:
   AdminManager();
   void LoadDatabase();
   void AccessSystem();
   void DoLogin();
   void DoSignUp();
   void AddNewBook(){
        bookManagerSystem.AddNewBook(current_Admin);
   }
   void UpdateDatabase(const Admin& admin);
   void ResetBooksIdtoAdmin(const vector<int>& bookIds){ // to Update the books_ids_from_admin
         current_Admin.ResetBooksIdsFromAdmin(bookIds);
    }
};
#endif