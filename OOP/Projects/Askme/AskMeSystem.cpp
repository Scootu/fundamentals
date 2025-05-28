#include "AskMeSystem.h"

void AskMeSystem::LoadDatabase(bool fill_user_questions)
{
    users_manager.LoadDatabase();
    questions_manager.LoadDatabase();

    if (fill_user_questions) // first time, waiting for login
        questions_manager.FillUserQuestions(current_user);
}

void AskMeSystem::run() 
{
    LoadDatabase();
    users_manager.AccessSystem();
    questions_manager.FillUserQuestions(current_user);

    vector<string> menu;
    menu.push_back("Print Questions To Me");
    menu.push_back("Print Questions From Me");
    menu.push_back("Answer Question");
    menu.push_back("Delete Question");
    menu.push_back("Ask Question");
    menu.push_back("List System Users");
    menu.push_back("Feed");
    menu.push_back("Logout");

    while (true)
    {
        int choice = ShowReadMenu(menu);
        LoadDatabase(true);

        if (choice == 1)
            questions_manager.PrintUserToQuestions(current_user);
        else if (choice == 2)
            questions_manager.PrintUserFromQuestions(current_user);
        else if (choice == 3)
        {
            questions_manager.AnswerQuestion(current_user);
            questions_manager.UpdateDatabase();
        }
        else if (choice == 4)
        {
            questions_manager.DeleteQuestion(current_user);
            // Let's build again (just easier, but slow)
            questions_manager.FillUserQuestions(current_user);
            questions_manager.UpdateDatabase();
        }
        else if (choice == 5)
        {
            pair<int, int> to_user_pair = users_manager.ReadUserId();
            if (to_user_pair.first != -1)
            {
                questions_manager.AskQuestion(current_user, to_user_pair);
                questions_manager.UpdateDatabase();
            }
        }
        else if (choice == 6)
            users_manager.ListUsersNamesIds();
        else if (choice == 7)
            questions_manager.ListFeed();
        else
            break;
    }
    run(); // Restart again
}