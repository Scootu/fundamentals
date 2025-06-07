#include "AdminManager.h"


AdminManager::AdminManager()
{
   last_id = 0;
}
void AdminManager::AccessSystem()
{
   int choice = showReadMenu({"Login", "Sign up"});
   if (choice == 1)
      DoLogin();
   else
      DoSignUp();
}

void AdminManager::LoadDatabase()
{
   last_id = 0;
   //adminId_bookObject_map.clear();
   adminName_AdminObject_map.clear();
   vector<string> lines = ReadFileLines("AdminList.txt");
   for (auto &line : lines)
   {
      Admin admin(line);
      adminName_AdminObject_map[admin.GetName()] = admin;
      //adminId_booksObject_map[admin.GetAdminId()] = bookManagerSystem.GetlistofBooks(admin);
      last_id = max(last_id, admin.GetAdminId());
   }
}
void AdminManager::DoLogin()
{
   LoadDatabase();
   while (true)
   {
      string name, password;
      cout << "Enter name & password: ";
      cin >> name >> password;
      current_Admin.SetName(name);
      current_Admin.SetPassword(password);

      if (!adminName_AdminObject_map.count(current_Admin.GetName()))
      {
         cout << "Invalid user name or password. Try again \n\n";
         continue;
      }
      const Admin &admin_exist = adminName_AdminObject_map[current_Admin.GetName()];

      if (admin_exist.GetPassword() != current_Admin.GetPassword())
      {
         cout << "Invalid user name or password. Try again \n\n";
         continue;
      }
      current_Admin = admin_exist;
      break;
   }
}
void AdminManager::DoSignUp()
{
   string admin_name;
		while (true) {
			cout << "Enter admin name. (No spaces): ";
			cin >> admin_name;

			if (adminName_AdminObject_map.count(admin_name))
				cout << "Already used. Try again\n";
			else
				break;
		}
		// Move logic to admin class, which may keep extending data members in future

		current_Admin.ReadAdmin(admin_name, ++last_id);
		adminName_AdminObject_map[current_Admin.GetName()] = current_Admin;

		UpdateDatabase(current_Admin);

}
void AdminManager::UpdateDatabase(const Admin &admin)
{
   string line = admin.ToString();
   vector<string> lines(1, line);

   WriteFileLines("AdminList.txt", lines);
}