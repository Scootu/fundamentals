
#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cassert>
#include <Helper.cpp>

using namespace std;


struct Question
{
private:
    int question_id;
    // To support thread. Each question look to a parent question
    // -1 No parent (first question in the thread)
    int parent_question_id;
    int from_user_id;
    int to_user_id;
    int is_anonymous_questions; // 0 or 1
    string question_text;
    string answer_text; // empty = not answered
public:
    Question()
    { // default constructor
        question_id = parent_question_id = from_user_id = to_user_id = -1;
        is_anonymous_questions = 1;
    }

    Question(string line)
    {
        vector<string> substrs = SplitString(line);
        // assert(substrs.size() == 7);

        question_id = ToInt(substrs[0]);
        parent_question_id = ToInt(substrs[1]);
        from_user_id = ToInt(substrs[2]);
        to_user_id = ToInt(substrs[3]);
        is_anonymous_questions = ToInt(substrs[4]);
        question_text = substrs[5];
        answer_text = substrs[6];
    }

    string ToString();
    void PrintToQuestion() const;
    void PrintFromQuestion() const;
    void PrintFeedQuestion() const;
};
#endif