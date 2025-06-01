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

    int GetSessionId()
    {
        return session_id;
    }
    int GetBookId()
    {
        return BookId;
    }
    int GetLpn()
    {
        return last_page_number;
    }
    string GetTimeKnow()
    {
        return time_now;
    }
    map<int, session> GetSessionIdFromSessionObj()
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

    void AddNewSession(int bookId, int lpn, int session_id_)
    {
        // Get current time
        auto now = chrono::system_clock::now();

        // Convert to time_t
        time_t now_time = chrono::system_clock::to_time_t(now);

        // Format as string (e.g., "2023-10-15 14:30:45")
        ostringstream oss;
        oss << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S");
        string time_str = oss.str();

        // Create new session with formatted time
        session s(session_id_, bookId, lpn, time_str);

        // Store the session (assuming you want to add it to the map)
        session_id_session_object_map[session_id_] = s;
        last_id = session_id_ + 1; // Update last_id if needed
    }
    void Print() const
    {
        cout << "Session ID: " << session_id << "Book ID: " << book_id
             << ", Last Page: " << last_page_number
             << ", Timestamp: " << time_now << "\n";
    }

    void UploadHistoryOfSessions(const string &line)
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
                int session_id = stoi(components[0]);
                int book_id = stoi(components[1]);
                int last_page = stoi(components[2]);
                string timestamp = components[3];

                // sessions.emplace_back(session_id, book_id, last_page, timestamp);
                session ses;
                ses.SetSessionId(session_id);
                ses.SetBookId(book_id);
                ses.SetLpn(last_page);
                ses.SetTime(timestamp);
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
    void PrintHistoryOfSessions(){
         cout <<"\n";

         if(session_id_session_object_map.size() == 0){
            cout <<"No sessions";
         }

         for(const auto &pair:session_id_session_object_map){
            const session& ses = pair.second;
            ses.Print();
         }
         cout <<"\n";
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
        current_session.UploadHistoryOfSessions(substr[5]);
    }
    int GetUserId(){
        return user_id;
    }
    string GetFullName(){
        return full_name;
    }
    string GetPassword(){
        return password;
    }
    string GetEmail(){
        return email;
    }
    session GetCurrentSession(){
        return current_session;
    }

    void Print() const
    {
        cout << "User " << user_id << ", " << user_name << "," << password << ", " << full_name << ", " << email << "\n";
    }
    string ToString() const
    {
        ostringstream oss;
        string str;
        for (int i = 0; i < historyOfsessions.size(); i++)
        {
            if (i != 0)
            {
                str += ",";
            }
            str += historyOfsessions[i].ToString();
        }
        oss << user_id << ",\"" << full_name << "\"" << "," << user_name << "," << password << "," << email << "[" << str << "]";
        return oss.str();
    }
};

#endif