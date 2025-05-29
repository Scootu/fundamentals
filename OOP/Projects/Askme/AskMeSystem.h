#ifndef ASKMESYSTEM_H
#define ASKMESYSTEM_H

#include "UsersManager.h"
#include "QuestionsManager.h"


struct AskMeSystem
{
private:
    UsersManager users_manager;
    QuestionsManager questions_manager;
    User current_user = users_manager.GetcurrentUser();

public:
    void LoadDatabase(bool fill_user_questions = false);
    	/*
	 * Probably the most important design change
	 * We needed to decouple the question manager from relying on User implementation
	 * We break to 2 steps
	 * 1) Question manager return relevant question
	 * 2) User manager helps reseting the user question. Even the manager doesn't do this by itself
	 *
	 * This is more OO now
	 */
	void ResetCurrentUserQuestions() {
		const User& user = users_manager.GetcurrentUser();

		const auto &to_questions = questions_manager.GetUserToQuestions(user);
		users_manager.ResetToQuestions(to_questions);

		const auto &from_questions = questions_manager.GetUserFromQuestions(user);
		users_manager.ResetFromQuestions(from_questions);
	}
    void Run();
};

#endif