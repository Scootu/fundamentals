#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include "BookManager.h"

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
    BookManagerSystem.LoadDataBase();
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
  /*
  const vector<int> &GetUserBookIds() const
  {
    return
  }
  */
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

    UpdateDatabase();
  }
  BookManager &GetBookManagerSystem()
  {
    return BookManagerSystem;
  }
  void ReadBook()
  {
    int book_id = BookManagerSystem.ReadBookIdAny();

    if (book_id == -1)
    {
      return;
    }
    Book book = BookManagerSystem.GetBookIdToBookObjMap().find(book_id)->second;

    // Start showing the first page
    BookManagerSystem.BookReadingFlow(book);
    // Enter -1 to cancle 1 to move to the next page 0 to previous page
    current_user.GetCurrentSession().AddNewSession(book); // To save lpn
    username_userObject_map[current_user.GetUserName()] = current_user; // udpate the state
    UpdateDatabase();
  }
  /*
  void CreateNewSession(const Book &book)
  {
    current_user.GetCurrentSession().AddNewSession(book);
  }
  */
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
    current_user.ViewCurrentSessionReadingList();
  }

  void UpdateDatabase()
  {
    vector<string> lines;
    for (const auto &user : username_userObject_map)
    {

      string line = user.second.ToString();
      lines.push_back(line);
    }
    WriteFileLines("userslist.txt", lines);
  }
  const User &GetcurrentUser() const
  {
    return current_user;
  }
};
#endif