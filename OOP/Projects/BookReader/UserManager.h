#ifndef USERMANAGER
#define USERMANAGER_H

#include "User.h"
class UserManager{
  private:
  int last_id;
  map<string, User> username_userObject_map;
  User current_user;
  public:
  UserManager(){
    last_id = 0;
  }

  void LoadDatabase(){
    last_id = 0;
    username_userObject_map.clear();
    
    
    vector<string> lines = ReadFileLines("userslist.txt");
    for(const auto& line:lines){
      User user(line);
      last_id = max(last_id,user.GetUserId());
      
    }
    
  }

};
#endif