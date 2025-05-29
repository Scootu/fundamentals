
#include "QuestionsManager.h"

QuestionsManager::QuestionsManager()
{
    last_id = 0;
}

void QuestionsManager::LoadDatabase()
{
    last_id = 0;
    questionid_questionidsThead_to_map.clear();
    questionid_questionobject_map.clear();

    vector<string> lines = ReadFileLines("18_questions.txt");
    for (auto &line : lines)
    {
        Question question(line);
        last_id = max(last_id, question.GetQuestionId());

        questionid_questionobject_map[question.GetQuestionId()] = question;

        if (question.GetParentQuestionId() == -1)
            questionid_questionidsThead_to_map[question.GetQuestionId()].push_back(question.GetQuestionId());
        else
            questionid_questionidsThead_to_map[question.GetParentQuestionId()].push_back(question.GetQuestionId());
    }
}

void QuestionsManager::PrintUserToQuestions(const User &user) const
{
    cout << "\n";

    if (user.GetQuestionIdThreadtoidSize(0) == 0)
        cout << "No Questions";

    for (auto &pair : user.GetQuestionIdThread()) // pair<int, vector<Question>>
    {                                             // pair<int, vector<Question>>
        cout << "Thread Question Id (" << pair.first << ")\n";
        if (pair.second.size() == 0)
            cout << "No Questions\n";

        for (int pos = 0; pos < user.GetQuestionIdThreadtoidSize(pair.first); ++pos)
        {
            int question_id = user.GetQuestionIdThread(pair.first, pos);
            const Question &question = questionid_questionobject_map.at(question_id);
            question.PrintToQuestion();
        }
    }
    cout << "\n";
}

void QuestionsManager::PrintUserFromQuestions(const User &user) const
{
    cout << "\n";
    if (user.GetQuestionsIdFromMeSize() == 0)
        cout << "No Questions";

    for (auto &question_id : user.GetQuestionIdFromMe())
    { //  vector<Question>

        // Get the question from the map. & means same in memory, DON'T COPY
        const Question &question = questionid_questionobject_map.at(question_id);
        question.PrintFromQuestion();
    }
    cout << "\n";
}

// Used in Answering a question for YOU.
// It can be any of your questions (thread or not)
int QuestionsManager::ReadQuestionIdAny(const User &user) const
{
    int question_id;
    cout << "Enter Question id or -1 to cancel: ";
    cin >> question_id;

    if (question_id == -1)
        return -1;

    if (!questionid_questionobject_map.count(question_id))
    {
        cout << "\nERROR: No question with such ID. Try again\n\n";
        return ReadQuestionIdAny(user);
    }
    const Question &question = questionid_questionobject_map.at(question_id);

    if (question.GetToUserId() != user.GetUserId())
    {
        cout << "\nERROR: Invalid question ID. Try again\n\n";
        return ReadQuestionIdAny(user);
    }
    return question_id;
}

// Used to ask a question on a specific thread for whatever user
int QuestionsManager::ReadQuestionIdThread(const User &user) const
{
    int question_id;
    cout << "For thread question: Enter Question id or -1 for new question: ";
    cin >> question_id;

    if (question_id == -1)
        return -1;

    if (!questionid_questionidsThead_to_map.count(question_id))
    {
        cout << "No thread question with such ID. Try again\n";
        return ReadQuestionIdThread(user);
    }
    return question_id;
}

void QuestionsManager::AnswerQuestion(const User &user)
{
    int question_id = ReadQuestionIdAny(user);

    if (question_id == -1)
        return;

    Question &question = questionid_questionobject_map[question_id];

    question.PrintToQuestion();

    if (question.GetAnswerText() != "")
        cout << "\nWarning: Already answered. Answer will be updated\n";

    cout << "Enter answer: "; // if user entered comma, system fails :)
    string line;
    getline(cin, line);
    getline(cin, line);
    question.SetAnswerText(line);
}

void QuestionsManager::DeleteQuestion(const User &user)
{
    int question_id = ReadQuestionIdAny(user);

    if (question_id == -1)
        return;

    vector<int> ids_to_remove; // to remove from questionid_questionobject_map

    // Let's see if thread or not. If thread, remove all of it
    if (questionid_questionidsThead_to_map.count(question_id))
    { // thread
        ids_to_remove = questionid_questionidsThead_to_map[question_id];
        questionid_questionidsThead_to_map.erase(question_id);
    }
    else
    {
        ids_to_remove.push_back(question_id);

        // let's find in which thread to remove. Consistency is important when have multi-view
        for (auto &pair : questionid_questionidsThead_to_map)
        {
            vector<int> &vec = pair.second;
            for (int pos = 0; pos < (int)vec.size(); ++pos)
            {
                if (question_id == vec[pos])
                {
                    vec.erase(vec.begin() + pos);
                    break;
                }
            }
        }
    }

    for (auto id : ids_to_remove)
    {
        questionid_questionobject_map.erase(id);
    }
}

void QuestionsManager::AskQuestion(const User &user,const pair<int, int> &to_user_pair)
{
    Question question;

    if (!to_user_pair.second)
    {
        cout << "Note: Anonymous questions are not allowed for this user\n";
        question.SetIsAnonymousQuestions(0);
    }
    else
    {
        cout << "Is anonymous questions?: (0 or 1): ";
        int r;
        cin >> r;
        question.SetIsAnonymousQuestions(r);
    }

    question.SetParentQuestionId(ReadQuestionIdThread(user));
    cout << "Enter question text: ";
    string line; // if user entered comma, system fails :)
    getline(cin, line);
    question.SetQuestionText(line); // read last enter
    // getline(cin, question.question_text);	// read last enter
    getline(cin, line);
    question.SetQuestionText(line);
    // cout << "Enter question text: ";
    question.SetFromUserId(user.GetUserId());
    question.SetToUserId(to_user_pair.first);

    // What happens in 2 parallel sessions who asked question?
    // They are given same id. This is wrong handling :)
    question.SetQuestionId(++last_id);
    questionid_questionobject_map[question.GetQuestionId()] = question;

    if (question.GetParentQuestionId() == -1)
        questionid_questionidsThead_to_map[question.GetQuestionId()].push_back(question.GetQuestionId());
    else
        questionid_questionidsThead_to_map[question.GetParentQuestionId()].push_back(question.GetQuestionId());
}

void QuestionsManager::ListFeed() const
{
    for (const auto &pair : questionid_questionobject_map)
    {
        const Question &question = pair.second;

        if (question.GetAnswerText() == "")
            continue;

        question.PrintFeedQuestion();
    }
}

void QuestionsManager::UpdateDatabase() const
{
    vector<string> lines;

    for (const auto &pair : questionid_questionobject_map)
        lines.push_back(pair.second.ToString());

    WriteFileLines("18_questions.txt", lines, false);
}