#include "User.h"

User::User() : user_id(-1), allow_anonymous_questions(-1) {}

User::User(const string &line)
{
    vector<string> substrs = SplitString(line);
    assert(substrs.size() == 6);

    user_id = ToInt(substrs[0]);
    user_name = substrs[1];
    password = substrs[2];
    name = substrs[3];
    email = substrs[4];
    allow_anonymous_questions = ToInt(substrs[5]);
}
int User::GetUserId() const
{
    return user_id;
}
int User::GetAllowAnonymousQuestions() const
{
    return allow_anonymous_questions;
}
int User::GetQuestionIdFromMe(int index) const
{
    assert(index >= 0 && index < (int)questions_id_from_me.size());
    return questions_id_from_me[index];
}
int User::GetQuestionIdThread(int question_id, int index) const
{
    assert(questionid_questionidsThead_to_map.count(question_id));
    assert(index >= 0 && index < (int)questionid_questionidsThead_to_map.at(question_id).size());
    return questionid_questionidsThead_to_map.at(question_id)[index];
}
// Setters
void User::SetQuestionIdThread(int question_id, int index, int id)
{
    assert(questionid_questionidsThead_to_map.count(question_id));
    assert(index >= 0 && index < (int)questionid_questionidsThead_to_map[question_id].size());
    questionid_questionidsThead_to_map[question_id][index] = id;
}
void User::SetUserId(int id)
{
    user_id = id;
}
void User::SetAllowAnonymousQuestions(int id)
{
    allow_anonymous_questions = id;
}
void User::SetQuestionsIdFromMe(int id)
{
    questions_id_from_me.push_back(id);
}
void User::SetQuestionIdThread(int question_id, int id)
{
    assert(questionid_questionidsThead_to_map.count(question_id));
    questionid_questionidsThead_to_map[question_id].push_back(id);
}
// @Override
// This is a simple system to ask questions and answer them.
string User::ToString() const
{
    ostringstream oss;
    oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << allow_anonymous_questions;

    return oss.str();
}

void User::Print() const
{
    cout << "User " << user_id << ", " << user_name << " " << password << ", " << name << ", " << email << "\n";
}
void User::ReadUser(const string &user_name, int id)
{
    setUserName(user_name);
    SetUserId(id);

    string str;

    cout << "Enter password: ";
    cin >> str;
    setPassword(str);

    cout << "Enter name : ";
    cin >> str;
    setName(str);

    cout << "Enter email: ";
    cin >> str;
    setEmail(str);

    cout << "Allow anonymous questions? (0 or 1)";
    int st;
    cin >> st;
    SetAllowAnonymousQuestions(st);
}
void User::ResetToQuestions(const vector<int> &to_questions)
{
    questions_id_from_me.clear();

    for (const auto &question_id : to_questions)
        questions_id_from_me.push_back(question_id);
}
void User::ResetFromQuestions(const vector<pair<int, int>> &to_questions)
{
    questionid_questionidsThead_to_map.clear();

    for (const auto &id_pair : to_questions)
        questionid_questionidsThead_to_map[id_pair.first].push_back(id_pair.second);
}
