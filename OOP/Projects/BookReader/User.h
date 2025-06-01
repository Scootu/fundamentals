#ifndef USER
#define USER_H

#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <map>
#include "Helper.cpp"
using namespace std;

struct session
{
    int session_id;
    int book_id;
    int last_page_number;
    string time_now;
    chrono::system_clock::time_point now; // Store time as a time_point

    map<int, session> session_id_session_object_map;

    session(int bookId, int lpn,string time) : book_id(bookId),
                                   last_page_number(lpn),
                                   time_now(time) {} // Initialize 'now' with current time

    void Print() const
    {
        cout << "Session ID: " << session_id << "Book ID: " << book_id
             << ", Last Page: " << last_page_number
             << ", Timestamp: " << time_now;
    }
    string ToString() const
    {
        ostringstream oss;

        // Convert stored time_point to time_t
        time_t now_time = chrono::system_clock::to_time_t(now);

        // Format time as string
        oss << "{Book ID: " << book_id
            << ", Last Page: " << last_page_number
            << ", Timestamp: " << time_now << "}";

        return oss.str();
    }
};
class User
{
private:
    int user_id;
    string user_name;
    string full_name;
    string password;
    string email;
    vector<session> historyOfsessions;

public:
    User(const string &line)
    {
        string substr = SplitString(line, "?", true);

        user_id = ToInt(substr[0]);
        user_name = substr[1];
        full_name = substr[2];
        password = substr[3];
        email = substr[4];
        historyOfsessions = SplitStringSessions(substr[5]);
    }
};

#endif