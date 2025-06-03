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
#include "Book.h"
using namespace std;

struct session
{
private:
    int session_id;
    int book_id;
    int last_page_number;
    string time_now;
    int last_id;

    map<int, session> session_id_session_object_map;

public:
    chrono::system_clock::time_point now; // Store time as a time_point
    session(int sessionId, int bookId, int lpn, string time) : session_id(sessionId), book_id(bookId),
                                                               last_page_number(lpn),
                                                               time_now(time), last_id(0) {} // Initialize 'now' with current time

    const int &GetSessionId() const
    {
        return session_id;
    }
    const int &GetBookId() const
    {
        return book_id;
    }
    const int &GetLpn() const
    {
        return last_page_number;
    }
    const string &GetTimeKnow() const
    {
        return time_now;
    }
    const map<int, session> &GetSessionIdFromSessionObj() const
    {
        return session_id_session_object_map;
    }
    void SetSessionId(int id)
    {
        session_id = id;
    }
    void SetBookId(int bookId)
    {
        book_id = bookId;
    }
    void SetLpn(int n)
    {
        last_page_number = n;
    }
    void SetTime(string time)
    {
        time_now = time;
    }

    void AddNewSession(const Book &book) // need a bookObj ?
    {
        // Get current time
        auto now = chrono::system_clock::now();

        // Convert to time_t
        time_t now_time = chrono::system_clock::to_time_t(now);

        // Format as string (e.g., "2023-10-15 14:30:45")
        ostringstream oss;
        oss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
        string time_str = oss.str();
        int bookId = book.GetBookId();
        int lpn = book.GetTotalPageNumber();
        // Create new session with formatted time
        session s(++last_id, bookId, lpn, time_str);

        // Store the session (assuming you want to add it to the map)
        session_id_session_object_map[s.GetSessionId()] = s;
        // UpdateDatabase()
    }
    void Print() const
    {
        cout << "Session ID: " << session_id << "Book ID: " << book_id
             << ", Last Page: " << last_page_number
             << ", Timestamp: " << time_now << "\n";
    }

    void LoadHistroyOfSessions(const string &line)
    {

        // Extract content between [ ]
        string s = line;
        if (s.front() == '[' && s.back() == ']')
        {
            s = s.substr(1, s.size() - 2);
        }

        // Split into individual session strings between { }
        size_t start_pos = 0;
        size_t end_pos = 0;
        while ((start_pos = s.find('{', end_pos)) != string::npos)
        {
            end_pos = s.find('}', start_pos);
            if (end_pos == string::npos)
                break;

            string session_str = s.substr(start_pos + 1, end_pos - start_pos - 1);

            // Parse session components
            vector<string> components;
            size_t pos = 0;
            while ((pos = session_str.find(',')) != string::npos)
            {
                string token = session_str.substr(0, pos);
                components.push_back(Trim(token));
                session_str.erase(0, pos + 1);
            }
            components.push_back(Trim(session_str)); // Add last component

            if (components.size() >= 4)
            {
                // Create session object (assuming session_id is auto-generated elsewhere)
                int session_id = ToInt(components[0]);
                int book_id = ToInt(components[1]);
                int last_page = ToInt(components[2]);
                string timestamp = components[3];

                // sessions.emplace_back(session_id, book_id, last_page, timestamp);
                session ses;
                ses.SetSessionId(session_id);
                ses.SetBookId(book_id);
                ses.SetLpn(last_page);
                ses.SetTime(timestamp);
                last_id = max(last_id, ses.GetSessionId());
                session_id_session_object_map[ses.GetSessionId()] = ses;
            }
        }
    }
    string ToString() const
    {
        ostringstream oss;
        oss << "{" << book_id
            << "," << last_page_number
            << "," << time_now << "}";

        return oss.str();
    }
    void PrintLatestSessions()
    {
        const int max_sessions_to_print = 5; // Print latest 5 sessions
        cout << "\n";

        if (session_id_session_object_map.empty())
        {
            cout << "No sessions\n";
            return;
        }

        // Start from the end and move backwards
        auto it = session_id_session_object_map.rbegin(); // Reverse iterator
        int count = 0;

        while (it != session_id_session_object_map.rend() && count < max_sessions_to_print)
        {
            const session &s = it->second;
            s.Print();
            ++it;
            ++count;
        }
    }
    void PrintHistoryOfSessions()
    {
        cout << "\n";

        if (session_id_session_object_map.size() == 0)
        {
            cout << "No sessions";
        }

        for (const auto &pair : session_id_session_object_map)
        {
            const session &ses = pair.second;
            ses.Print();
        }
        cout << "\n";
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
    session current_session;
    // vector<session> historyOfsessions;

public:
    User(const string &line)
    {
        string substr = SplitString(line, ",", true);

        user_id = ToInt(substr[0]);
        user_name = substr[1];
        full_name = substr[2];
        password = substr[3];
        email = substr[4];
        // historyOfsessions = current_session.GetHistoryOfSessions(substr[5]);
        // initialize session
        current_session.session_id_session_object_map.clear();
        current_session.LoadHistroyOfSessions(substr[5]);
    }
    int GetUserId() const
    {
        return user_id;
    }
    string GetUserName() const
    {
    }
    string GetFullName() const
    {
        return full_name;
    }
    string GetPassword() const
    {
        return password;
    }
    string GetEmail() const
    {
        return email;
    }
    const session &GetCurrentSession() const
    {
        return current_session;
    }
    void SetUserName(const string &user_name_)
    {
        user_name = user_name_;
    }
    void SetUserId(const int &id_)
    {
        user_id = id;
    }
    void SetFullName(const string &name)
    {
        full_name = name;
    }
    void SetPassword(const string &pass)
    {
        password = pass;
    }
    void SetEmail(const string &e)
    {
        email = e;
    }
    void ReadUser(const string &user_name, int id)
    {
        SetUserName(user_name);
        SetUserId(id);

        string str;

        cout << "Enter password: ";
        cin >> str;
        SetPassword(str);

        cout << "Enter name: ";
        cin >> str;
        SetFullName(str);

        cout << "Enter email: ";
        cin >> str;
        SetEmail(str);
    }



    void Print() const
    {
        cout << "User " << user_id << ", " << user_name << "," << password << ", " << full_name << ", " << email << "\n";
    }
    string ToString() const
    {
        ostringstream oss;
        string str;

        for (const auto &pair : current_session.GetSessionIdFromSessionObj())
        {
            str += pair.second.ToString();
            str += ",";
        }
        oss << user_id << ",\"" << full_name << "\"" << "," << user_name << "," << password << "," << email << "[" << str << "]";
        return oss.str();
    }
};

#endif