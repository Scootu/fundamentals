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


using namespace std;

struct UsersManager
{
private:
    map<string, User> userame_userobject_map;
    User current_user;
    int last_id;

public:
    UsersManager();
    const User &GetcurrentUser() const
    {
        return current_user;
    }
    void LoadDatabase();
    void AccessSystem();
    void DoLogin();
    void DoSignUp();
    void ResetToQuestions(const vector<int> &to_questions)
    {
        current_user.ResetToQuestions(to_questions);
    }

    void ResetFromQuestions(const vector<pair<int, int>> &to_questions)
    {
        current_user.ResetFromQuestions(to_questions);
    }
    void ListUsersNamesIds() const;
    pair<int, int> ReadUserId() const;
    void UpdateDatabase(const User &user) const;
};
#endif // USERSMANAGER_H