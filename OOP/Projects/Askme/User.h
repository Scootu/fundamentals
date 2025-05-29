#ifndef USER_H
#define USER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include "Helper.h"
using namespace std;

class User
{
    // Map the user name to user object. Let's keep one place ONLY with the object
private:
    int user_id; // internal system ID
    string user_name;
    string password;
    string name;
    string email;
    int allow_anonymous_questions; // 0 or 1

    vector<int> questions_id_from_me;
    // From question id to list of questions IDS on this question (thread questions) - For this user
    map<int, vector<int>> questionid_questionidsThead_to_map;

public:
    User() ;
    User(const string &line) ;
    string GetUserName() const
    {
        return user_name;
    }
    string GetPassword() const
    {
        return password;
    }
    string GetName() const
    {
        return name;
    }
    string GetEmail() const
    {
        return email;
    }
    void setUserName(const string &username_)
    {
        user_name = username_;
    }
    void setName(const string &name_)
    {
        name = name_;
    }
    void setPassword(const string &password_)
    {
        password = password_;
    }
    void setEmail(const string &email_)
    {
        email = email_;
    }

    // Getters
    int GetUserId() const ;
    int GetAllowAnonymousQuestions() const ;
    int GetQuestionIdFromMe(int index) const ;
    int GetQuestionIdThread(int question_id, int index) const ;
    const vector<int>& GetQuestionIdFromMe() const
    {
        return questions_id_from_me;
    }
    const map<int, vector<int>>& GetQuestionIdThread() const
    {
        return questionid_questionidsThead_to_map;
    }
    void ClearQuestionIdThread()
    {
        questionid_questionidsThead_to_map.clear();
    }
    void ClearQuestionsIdFromMe()
    {
        questions_id_from_me.clear();
    }
    int GetQuestionsIdFromMeSize() const
    {
        return questions_id_from_me.size();
    }
    int GetQuestionIdThreadtoidSize(int question_id) const
    {
        if(questionid_questionidsThead_to_map.at(question_id).size()== 0){

            return 0;
        }
        assert(questionid_questionidsThead_to_map.count(question_id));
        return questionid_questionidsThead_to_map.at(question_id).size();
    }
    // Setters
    void SetQuestionIdThread(int question_id, int index, int id) ;
    void SetUserId(int id) ;
    void SetAllowAnonymousQuestions(int id) ;
    void SetQuestionsIdFromMe(int id) ;

    void SetQuestionIdThread(int question_id, int id) ;

    string ToString() const ;
    void Print() const ;
    void ReadUser(const string &user_name,int id);
    void ResetToQuestions(const vector<int> &to_questions);
    void ResetFromQuestions(const vector<pair<int, int>> &to_questions);
};

#endif // USER_H