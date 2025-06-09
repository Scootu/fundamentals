#ifndef BOOKREADERSYSTEM_H
#define BOOKREADERSYSTEM_H

#include "UserManager.h"
#include "AdminManager.h"

class BookReaderSystem
{
private:
    UserManager users_manager;
    AdminManager admin_manager;

    void LoadDatabase()
    {
        users_manager.LoadDatabase();
        admin_manager.LoadDatabase();
    }
   /*
   void ResetAdminBooksIds()
   {
    const Admin &admin = admin_manager.GetCurrentAdmin();
    vector<int> book_ids = users_manager.GetBookManagerSystem().GetListOfBooksIds();
    //admin_manager.ResetBooksIdtoAdmin(book_ids);
}
*/
    void RunUser()
    {
        // in case user try to login
        LoadDatabase();
        users_manager.AccessSystem();

        vector<string> menu;
        menu.push_back("Print my profil information");
        menu.push_back("List current system books");
        menu.push_back("View current reading sessions");
        menu.push_back("Read a Book");
        menu.push_back("Logout");

        while (true)
        {
            int choice = showReadMenu(menu);
            LoadDatabase();

            if (choice == 1)
            {
                users_manager.ViewProfilInformation();
            }
            else if (choice == 2)
            {
                users_manager.PrintSystemBooks();
            }
            else if (choice == 3)
            {
                users_manager.ViewCurrentReadingSessions();
            }
            else if (choice == 4)
            {
                users_manager.ReadBook();
                users_manager.UpdateDatabase(); // To save session in userslist.txt
            }

            else
            {
                break;
            }
        }
        RunUser();
    }
    void RunAdmin()
    {
        LoadDatabase();
        admin_manager.AccessSystem();

        vector<string> menu;
        menu.push_back("Print my profil information");
        menu.push_back("Add new book");
        menu.push_back("View my books list");
        menu.push_back("Logout");

        while (true)
        {
            int choice = showReadMenu(menu);
            LoadDatabase();

            if (choice == 1)
            {
                admin_manager.GetCurrentAdmin().Print();
            }
            else if (choice == 2)
            {
                admin_manager.AddNewBook();
                admin_manager.UpdateDatabase();
            }
            else if (choice == 3)
            {
                admin_manager.PrintMyBooksIdsList();
            }
            else
            {
                break;
            }
        }
        RunAdmin();
    }

public:
    void RunSystem()
    {
        int choice;
        cout << "Admin 0 or User 1 ?\n";
        if (ReadInt(0, 1))
        {
            RunUser();
        }
        else 
        {
            RunAdmin();
        }
        RunSystem();
    }
};
#endif