#include "AskMeSystem.h"

void AskMeSystem::LoadDatabase(bool fill_user_questions) {	// Internal
		users_manager.LoadDatabase();
		questions_manager.LoadDatabase();

		if (fill_user_questions)	// first time, waiting for login
			ResetCurrentUserQuestions();
	}

void AskMeSystem::Run() {	// only public one
		LoadDatabase(false);
		users_manager.AccessSystem();
		ResetCurrentUserQuestions();

		vector<string> menu;
		menu.push_back("Print Questions To Me");
		menu.push_back("Print Questions From Me");
		menu.push_back("Answer Question");
		menu.push_back("Delete Question");
		menu.push_back("Ask Question");
		menu.push_back("List System Users");
		menu.push_back("Feed");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			LoadDatabase(true);

			if (choice == 1)
				questions_manager.PrintUserToQuestions(users_manager.GetcurrentUser());
			else if (choice == 2)
				questions_manager.PrintUserFromQuestions(users_manager.GetcurrentUser());
			else if (choice == 3) {
				questions_manager.AnswerQuestion(users_manager.GetcurrentUser());
				questions_manager.UpdateDatabase();
			} else if (choice == 4) {
				questions_manager.DeleteQuestion(users_manager.GetcurrentUser());
				// Let's build again (just easier, but slow)
				ResetCurrentUserQuestions();
				questions_manager.UpdateDatabase();
			} else if (choice == 5) {
				pair<int, int> to_user_pair = users_manager.ReadUserId();
				if (to_user_pair.first != -1) {
					questions_manager.AskQuestion(users_manager.GetcurrentUser(), to_user_pair);
					questions_manager.UpdateDatabase();
				}
			} else if (choice == 6)
				users_manager.ListUsersNamesIds();
			else if (choice == 7)
				questions_manager.ListFeed();
			else
				break;
		}
		Run();	// Restart again
	}
