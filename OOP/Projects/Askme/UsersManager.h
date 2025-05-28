#ifndef USERSMANAGER_H
#define USERSMANAGER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cassert>
#include "User.h"
#include "Question.h"
#include "QuestionsManager.h"

using namespace std;

struct UsersManager
{
private:
    map<string, User> userame_userobject_map;
    User current_user;
    int last_id;

public:
    UsersManager();
    User& GetcurrentUser(){
        return current_user;
    }
    void LoadDatabase();
    void AccessSystem();
    void DoLogin();
    void DoSignUp();
    void ListUsersNamesIds();
    pair<int, int> ReadUserId();
    void UpdateDatabase(User &user) const;
};
#endif // USERSMANAGER_H