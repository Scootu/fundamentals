#ifndef USERMANAGER
#define USERMANAGER_H

#include "User.h"
class UserManager{

  int last_id;
  map<string, User> username_userObject_map;
  
};
#endif