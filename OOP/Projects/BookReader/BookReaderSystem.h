#ifndef BOOKREADERSYSTEM
#define BOOKREADERSYSTEM_H

#include "UserManager.h"
#include "AdminManager.h"

class BookReaderSystem
{
private:
    UserManager users_manager;
    AdminManager admin_manager;

    void LoadDatabase(bool fill_admin_ids = false)
    {
        users_manager.LoadDatabase();
        admin_manager.LoadDatabase();
        book_manager.LoadDataBase();
        if (fill_admin_ids)
            ResetAdminBooksIds();
    }

    void ResetAdminBooksIds()
    {
        const Admin &admin = admin_manager.GetCurrentAdmin();
        const vector<int> &book_ids = users_manager.GetBookManagerSystem().GetListOfBooksIds();
        admin_manager.ResetBooksIdtoAdmin(book_ids);
    }

public:
    void Run()
    {
        LoadDatabase(false);
        users_manager.AccessSystem();
        ResetAdminBooksIds();

        vector<string> menu;
        menu.push_back("Print my profil information");
        menu.push_back("List current system books");
        menu.push_back("View current reading sessions");
        menu.push_back("Read a Book");
        menu.push_back("Logout");

        while (true)
        {
            int choice = showReadMenu();
            LoadDatabase(true);

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
                users_manager.UpdateDatabase();
            }

            else
            {
                break;
            }
        }
        Run();
    }
};
#endif