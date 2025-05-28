
#include "User.h"
#include "Question.h"

struct QuestionsManager
{
private:
	// From question id to list of questions IDS on this question (thread questions) - All users
	map<int, vector<int>> questionid_questionidsThead_to_map;

	// Map the question id to question object. Let's keep one place ONLY with the object
	// When you study pointers, easier handling
	map<int, Question> questionid_questionobject_map;

	int last_id;

public:
	QuestionsManager();
	void LoadDatabase();
	void FillUserQuestions(User &user);
	void PrintUserToQuestions(User &user) const;
	void PrintUserFromQuestions(User &user) const;
	int ReadQuestionIdAny(User &user) const;
	int ReadQuestionIdThread(User &user) const;
	void AnswerQuestion(User &user);
	void DeleteQuestion(User &user);
	void AskQuestion(User &user, pair<int, int> to_user_pair);
	void ListFeed();
	void UpdateDatabase() const;
};
