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
    map<int, vector<Book>> adminId_booksObject_map;
    map<string,Admin> adminName_AdminObject_map;
    
public:
   AdminManager();
   void LoadDatabase();
   void AccessSystem();
   void DoLogin();
   void DoSignUp();
   //void ListUsersNamesIds();
   void UpdateDatabase(const Admin& admin);
};
#endif