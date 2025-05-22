// NOT well tested :)
// This is a simple system to ask questions and answer them.
// It is not a real system. It is just a simple example to show how to use classes and objects.
#include "Question.h"
#include "Helper.cpp"
#include "User.h"
#include "QuestionsManager.h"
#include "UsersManager.h"
#include <map>
#include <utility>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


struct UsersManager {
	map<string, User> userame_userobject_map;
	User current_user;
	int last_id;

	UsersManager() {
		last_id = 0;
	}

	void LoadDatabase() {
		last_id = 0;
		userame_userobject_map.clear();

		vector<string> lines = ReadFileLines("18_users.txt");
		for (auto &line : lines) {

			User user(line);
			userame_userobject_map[user.user_name] = user;
			last_id = max(last_id, user.user_id);
		}
	}

	void AccessSystem() {
		int choice = ShowReadMenu( { "Login", "Sign Up" });
		if (choice == 1)
			DoLogin();
		else
			DoSignUp();
	}

	void DoLogin() {
		LoadDatabase();	// in case user added from other parallel run

		while (true) {
			cout << "Enter user name & password: ";
			cin >> current_user.user_name >> current_user.password;

			if (!userame_userobject_map.count(current_user.user_name)) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			User user_exist = userame_userobject_map[current_user.user_name];

			if (current_user.password != user_exist.password) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			current_user = user_exist;
			break;
		}
	}

	void DoSignUp() {
		while (true) {
			cout << "Enter user name. (No spaces): ";
			cin >> current_user.user_name;

			if (userame_userobject_map.count(current_user.user_name))
				cout << "Already used. Try again\n";
			else
				break;
		}
		cout << "Enter password: ";
		cin >> current_user.password;

		cout << "Enter name: ";
		cin >> current_user.name;

		cout << "Enter email: ";
		cin >> current_user.email;

		cout << "Allow anonymous questions? (0 or 1): ";
		cin >> current_user.allow_anonymous_questions;

		// What happens in 2 parallel sessions if they signed up?
		// They are given same id. This is wrong handling :)
		current_user.user_id = ++last_id;
		userame_userobject_map[current_user.user_name] = current_user;

		UpdateDatabase(current_user);
	}

	void ListUsersNamesIds() {
		for (auto &pair : userame_userobject_map)
			cout << "ID: " << pair.second.user_id << "\t\tName: " << pair.second.name << "\n";
	}

	pair<int, int> ReadUserId() {
		int user_id;
		cout << "Enter User id or -1 to cancel: ";
		cin >> user_id;

		if (user_id == -1)
			return make_pair(-1, -1);

		for (auto &pair : userame_userobject_map) {
			if (pair.second.user_id == user_id)
				return make_pair(user_id, pair.second.allow_anonymous_questions);
		}

		cout << "Invalid User ID. Try again\n";
		return ReadUserId();
	}

	void UpdateDatabase(User &user) {
		string line = user.ToString();
		vector<string> lines(1, line);
		WriteFileLines("18_users.txt", lines);
	}
};

struct AskMeSystem {
	UsersManager users_manager;
	QuestionsManager questions_manager;

	void LoadDatabase(bool fill_user_questions = false) {
		users_manager.LoadDatabase();
		questions_manager.LoadDatabase();

		if (fill_user_questions)	// first time, waiting for login
			questions_manager.FillUserQuestions(users_manager.current_user);
	}

	void run() {
		LoadDatabase();
		users_manager.AccessSystem();
		questions_manager.FillUserQuestions(users_manager.current_user);

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
				questions_manager.PrintUserToQuestions(users_manager.current_user);
			else if (choice == 2)
				questions_manager.PrintUserFromQuestions(users_manager.current_user);
			else if (choice == 3) {
				questions_manager.AnswerQuestion(users_manager.current_user);
				questions_manager.UpdateDatabase();
			} else if (choice == 4) {
				questions_manager.DeleteQuestion(users_manager.current_user);
				// Let's build again (just easier, but slow)
				questions_manager.FillUserQuestions(users_manager.current_user);
				questions_manager.UpdateDatabase();
			} else if (choice == 5) {
				pair<int, int> to_user_pair = users_manager.ReadUserId();
				if (to_user_pair.first != -1) {
					questions_manager.AskQuestion(users_manager.current_user, to_user_pair);
					questions_manager.UpdateDatabase();
				}
			} else if (choice == 6)
				users_manager.ListUsersNamesIds();
			else if (choice == 7)
				questions_manager.ListFeed();
			else
				break;
		}
		run();	// Restart again
	}
};

int main() {
	AskMeSystem service;
	service.run();

	return 0;
}


/*
101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
205,101,45,13,0,What about python?,
211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa
212,-1,13,45,0,Please search archive before asking,
300,101,11,13,1,Is it ok to learn Java for OOP?,Good choice
301,-1,11,13,0,Free to meet?,
302,101,11,13,1,Why so late in reply?,

13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
11,noha,222,noha_salah,nono171@gmail.com,0
45,ali,333,ali_wael,wael@gmail.com,0
*/

