#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <map>
#include "Helper.h"
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
    session()
    {
        last_id = 0;
    }
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
    void SetSessionId_toSessionObj(int id, session ses)
    {
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
        int lpn = book.GetLpn(); // is this lpn ?
        // Create new session with formatted time
        session s(++last_id, bookId, lpn, time_str);

        session_id_session_object_map[s.GetSessionId()] = s;
        // UpdateDatabase()
    }
    void LoadFromPreviousSession(); // Another concept
    void Print() const
    {
        cout << "Session ID: " << session_id << ", Book ID: " << book_id
             << ", Last Page: " << last_page_number
             << ", Timestamp: " << time_now << "\n";
    }
    void ResetHistoryOfSessions(const map<int, session> &sessions_ids)
    {
        session_id_session_object_map.clear();
        for (const auto &pair : sessions_ids)
        {
            session_id_session_object_map[pair.first] = pair.second;
            pair.second.Print();
        }
    }
    void LoadHistroyOfSessions(const string &line)
    {             
        session_id_session_object_map.clear(); // clear previous entries

        string s = line;

        // Remove outer brackets [ ... ]
        if (!s.empty() && s.front() == '[' && s.back() == ']')
            s = s.substr(1, s.size() - 2);

        size_t start_pos = 0, end_pos = 0;

        while ((start_pos = s.find('{', end_pos)) != string::npos)
        {
            end_pos = s.find('}', start_pos);
            if (end_pos == string::npos)
                break;

            string session_str = s.substr(start_pos + 1, end_pos - start_pos - 1);

            // Remove trailing comma inside the session if present
            if (!session_str.empty() && session_str.back() == ',')
                session_str.pop_back();

            // Split into exactly 3 parts: session_id, book_id, lpn, and the rest is timestamp
            size_t p1 = session_str.find(',');
            size_t p2 = session_str.find(',', p1 + 1);

            if (p1 == string::npos || p2 == string::npos)
                continue;

            string sid_str = Trim(session_str.substr(0, p1));
            string bid_str = Trim(session_str.substr(p1 + 1, p2 - p1 - 1));
            string lpn_str = Trim(session_str.substr(p2 + 1)); // this includes timestamp

            // Split lpn and timestamp
            size_t p3 = lpn_str.find(',');
            if (p3 == string::npos)
                continue;

            string lpn_val = Trim(lpn_str.substr(0, p3));
            string timestamp = Trim(lpn_str.substr(p3 + 1));

            if (sid_str.empty() || bid_str.empty() || lpn_val.empty() || timestamp.empty())
                continue;

            int session_id = ToInt(sid_str);
            int book_id = ToInt(bid_str);
            int last_page = ToInt(lpn_val);

            session ses;
            ses.SetSessionId(session_id);
            ses.SetBookId(book_id);
            ses.SetLpn(last_page);
            ses.SetTime(timestamp);

            last_id = max(last_id, session_id);
            
            session_id_session_object_map[session_id] = ses;
        }
    }

    string ToString() const
    {
        ostringstream oss;
        oss << "{" << session_id << "," << book_id
            << "," << last_page_number
            << "," << time_now << "}";

        return oss.str();
    }
    void PrintLatestSessions() const
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
    void PrintHistoryOfSessions() const
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
    string session_buffer;
    session current_session;
    // vector<session> historyOfsessions;

public:
    User() = default;
    User(const string &line)
    {
        vector<string> substr = SplitString(line, ",", true);

        user_id = ToInt(substr[0]);
        user_name = substr[1];
        full_name = substr[3];
        password = substr[2];
        email = substr[4];
        // historyOfsessions = current_session.GetHistoryOfSessions(substr[5]);
        // initialize session
        session_buffer = substr[5];

        // current_session.GetSessionIdFromSessionObj().clear();
        // LoadHistroyOfSessions(current_session,substr[5]); // Are loading data in the constructor don't prohibited the oop concepts
        current_session.LoadHistroyOfSessions(session_buffer);
    }
    /*
    void ResetSessionsIdsToSessionObjects(){
        map<int,session> sessionids_sessionsobject = current_session.LoadHistroyOfSessions(session_buffer);
        current_session.ResetHistoryOfSessions(sessionids_sessionsobject);
    }
    */
    void ViewCurrentSessionReadingList()
    {
        current_session.PrintLatestSessions();
    }
    int GetUserId() const
    {
        return user_id;
    }
    string GetUserName() const
    {
        return user_name;
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
    session &GetCurrentSession() // is not const
    {
        return current_session;
    }
    void SetUserName(const string &user_name_)
    {
        user_name = user_name_;
    }
    void SetUserId(const int &id_)
    {
        user_id = id_;
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
        cin.ignore();
        cout << "Enter Full name: ";
        getline(cin, str);
        SetFullName(str);

        cout << "Enter email: ";
        cin >> str;
        SetEmail(str);
    }

    void Print() const
    {
        cout << "User : " << user_id << ", " << user_name << "," << password << ", " << full_name << ", " << email << "\n";
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
        oss << user_id << "," << user_name << "," << password << ",\"" << full_name << "\"," << email << ",[" << str << "]";
        return oss.str();
    }
};

#endif