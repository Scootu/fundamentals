#ifndef USERMANAGER
#define USERMANAGER_H

#include "User.h"
#include "BookManager.h"
#include "Helper.cpp"
#include "Book.h"
class UserManager
{
private:
  int last_id;
  map<string, User> username_userObject_map;
  User current_user;
  BookManager BookManagerSystem;

public:
  UserManager()
  {
    last_id = 0;
  }

  void LoadDatabase()
  {
    last_id = 0;
    username_userObject_map.clear();

    vector<string> lines = ReadFileLines("userslist.txt");
    for (const auto &line : lines)
    {
      User user(line);
      username_userObject_map[user.GetUserName()] = user;
      last_id = max(last_id, user.GetUserId());
    }
  }
  void AccessSystem()
  {
    int choice = showReadMenu({"Login", "Sign Up"});
    if (choice == 1)
      DoLogin();
    else
      DoSignUp();
  }
  void DoLogin()
  {
    LoadDatabase(); // in case user added from other parallel run

    while (true)
    {
      string name, pass;
      cout << "Enter user name & password: ";
      cin >> name >> pass;
      current_user.SetUserName(name);
      current_user.SetPassword(pass);

      if (!username_userObject_map.count(current_user.GetUserName()))
      {
        cout << "\nInvalid user name or password. Try again\n\n";
        continue;
      }
      const User &user_exist = username_userObject_map[current_user.GetUserName()];

      if (current_user.GetPassword() != user_exist.GetPassword())
      {
        cout << "\nInvalid user name or password. Try again\n\n";
        continue;
      }
      current_user = user_exist;
      break;
    }
  }

  void DoSignUp()
  {
    string user_name;
    while (true)
    {
      cout << "Enter user name. (No spaces): ";
      cin >> user_name;

      if (username_userObject_map.count(user_name))
        cout << "Already used. Try again\n";
      else
        break;
    }
    // Move logic to user class, which may keep extending data members in future

    current_user.ReadUser(user_name, ++last_id);
    username_userObject_map[current_user.GetUserName()] = current_user;

    UpdateDatabase(current_user);
  }
  void ReadBook(const UserManager &userManager)
  {
    int book_id = ReadBookIdAny();

    if (book_id == -1)
    {
      return;
    }
    const Book &book = BookManagerSystem.GetBookIdToBookObjMap().find(book_id)->second;
    current_user.GetCurrentSession().AddNewSession(book);
    }
  void CreateNewSession(const Book &book)
  {
    current_user.GetCurrentSession().AddNewSession(book);
  }
  void PrintSystemBooks()
  {
    BookManagerSystem.PrintListOfbookSystem();
  }
  void ViewProfilInformation()
  {
    current_user.Print();
  }
  void ViewCurrentReadingSessions()
  {
    current_user.GetCurrentSession().PrintLatestSessions(); // how many times he load & update the data ?
  }

  void UpdateDatabase(const User &user)
  {
    string line = user.ToString();
    vector<string> lines(1, line);
    WriteFileLines("18_users.txt", lines);
  }
  const User &GetcurrentUser() const
  {
    return current_user;
  }
};
#endif