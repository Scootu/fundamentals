
#include "UsersManager.h"
UsersManager::UsersManager()
{
    last_id = 0;
}

void UsersManager::LoadDatabase()
{
    last_id = 0;
    userame_userobject_map.clear();

    vector<string> lines = ReadFileLines("18_users.txt");
    for (auto &line : lines)
    {

        User user(line);
        userame_userobject_map[user.GetUserName()] = user;
        last_id = max(last_id, user.GetUserId());
    }
}

void UsersManager::AccessSystem()//contiue creating setters in user.h
{
    int choice = ShowReadMenu({"Login", "Sign Up"});
    if (choice == 1)
        DoLogin();
    else
        DoSignUp();
}

void UsersManager::DoLogin()
{
    LoadDatabase(); // in case user added from other parallel run

    while (true)
    {
        string password,username;
        cout << "Enter user name & password: ";
        cin >> username >> password;
        current_user.setUserName(username);
        current_user.setPassword(password);
        if (!userame_userobject_map.count(current_user.GetUserName()))
        {
            cout << "\nInvalid user name or password. Try again\n\n";
            continue;
        }
        User user_exist = userame_userobject_map[current_user.GetUserName()];

        if (current_user.GetPassword() != user_exist.GetPassword())
        {
            cout << "\nInvalid user name or password. Try again\n\n";
            continue;
        }
        current_user = user_exist;
        break;
    }
}

void UsersManager::DoSignUp()
{
   string user_name;
		while (true) {
			cout << "Enter user name. (No spaces): ";
			cin >> user_name;

			if (userame_userobject_map.count(user_name))
				cout << "Already used. Try again\n";
			else
				break;
		}
		// Move logic to user class, which may keep extending data members in future

		current_user.ReadUser(user_name, ++last_id);
		userame_userobject_map[current_user.GetUserName()] = current_user;

    UpdateDatabase(current_user);
}

void UsersManager::ListUsersNamesIds() const
{
    for (auto &pair : userame_userobject_map)
        cout << "ID: " << pair.second.GetUserId() << "\t\tName: " << pair.second.GetName() << "\n";
}

pair<int, int> UsersManager::ReadUserId() const
{
    int user_id;
    cout << "Enter User id or -1 to cancel: ";
    cin >> user_id;

    if (user_id == -1)
        return make_pair(-1, -1);

    for (auto &pair : userame_userobject_map)
    {
        if (pair.second.GetUserId() == user_id)
            return make_pair(user_id, pair.second.GetAllowAnonymousQuestions());
    }

    cout << "Invalid User ID. Try again\n";
    return ReadUserId();
}

void UsersManager::UpdateDatabase(const User &user) const
{
    string line = user.ToString();
    vector<string> lines(1, line);
    WriteFileLines("18_users.txt", lines);
}