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
    void run();
};

#endif