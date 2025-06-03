#ifndef USERMANAGER
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
  
  
  void PrintSystemBooks(){
     BookManagerSystem.PrintListOfbookSystem();
  }
  void ViewProfilInformation(){
    current_user.Print();
  }
  void ViewCurrentReadingSessions(){
    current_user.GetCurrentSession().PrintLatestSessions(); // how many times he load & update the data ?
  }

  void UpdateDatabase(cosnt User &user)
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