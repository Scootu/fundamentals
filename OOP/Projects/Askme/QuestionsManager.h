
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
	//Filluserquestion() was rempaced with readuser in user.h
	void PrintUserToQuestions(const User &user) const;
	void PrintUserFromQuestions(const User &user) const;
	int ReadQuestionIdAny(const User &user) const;
	int ReadQuestionIdThread(const User &user) const;
	void AnswerQuestion(const User &user);
	void DeleteQuestion(const User &user);
	void AskQuestion(const User &user, const pair<int, int> &to_user_pair);
	void ListFeed() const ;
	void UpdateDatabase() const;

	vector<pair<int, int>> GetUserFromQuestions(const User &user) const
	{
		vector<pair<int, int>> question_ids;

		for (const auto &pair : questionid_questionidsThead_to_map)
		{ // pair<int, vector<Question>>
			for (const auto &question_id : pair.second)
			{ //  vector<Question>
				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = questionid_questionobject_map.find(question_id)->second;

				if (question.GetToUserId() == user.GetUserId())
				{
					if (question.GetParentQuestionId() == -1)
						question_ids.push_back(make_pair(question.GetQuestionId(), question.GetQuestionId()));
					else
						question_ids.push_back(make_pair(question.GetParentQuestionId(), question.GetQuestionId()));
				}
			}
		}
		return question_ids;
	}
	vector<int> GetUserToQuestions(const User &user) const
	{
		vector<int> question_ids;

		for (const auto &pair : questionid_questionidsThead_to_map)
		{ // pair<int, vector<Question>>
			for (const auto &question_id : pair.second)
			{ //  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = questionid_questionobject_map.find(question_id)->second;

				if (question.GetFromUserId() == user.GetUserId())
					question_ids.push_back(question.GetQuestionId());
			}
		}
		return question_ids;
	}
};
