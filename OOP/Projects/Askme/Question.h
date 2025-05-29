
#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cassert>
#include "Helper.h"

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

    Question(string &line)
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
    int GetQuestionId() const
    {
        return question_id;
    }
    int GetParentQuestionId() const
    {
        return parent_question_id;
    }
    int GetFromUserId() const
    {
        return from_user_id;
    }
    int GetToUserId() const
    {
        return to_user_id;
    }
    int GetIsAnonymousQuestions() const
    {
        return is_anonymous_questions;
    }
    const string& GetQuestionText() const
    {
        return question_text;
    }
    const string& GetAnswerText() const
    {
        return answer_text;
    }
    void SetQuestionId(int id)
    {
        question_id = id;
    }
    void SetParentQuestionId(int id)
    {
        parent_question_id = id;
    }
    void SetFromUserId(int id)
    {
        from_user_id = id;
    }
    void SetToUserId(int id)
    {
        to_user_id = id;
    }
    void SetIsAnonymousQuestions(int id)
    {
        is_anonymous_questions = id;
    }
    void SetQuestionText(const string &text)
    {
        question_text = text;
    }
    void SetAnswerText(const string &text)
    {
        answer_text = text;
    }
    // @Override
    // This is a simple system to ask questions and answer them.
    string ToString() const;
    void PrintToQuestion() const;
    void PrintFromQuestion() const;
    void PrintFeedQuestion() const;
};
#endif