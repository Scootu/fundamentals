#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
vector<string> SplitString(const string &str, const string &delimiter = ",", bool isSplitBooksIds = false)
{
    string s = str;
    vector<string> strs;
    size_t pos = 0;
    string substr;

    while ((pos = s.find(delimiter)) != string::npos &&
           (isSplitBooksIds ? strs.size() < 5 : true))
    {
        substr = s.substr(0, pos);
        // Remove surrounding quotes if present
        if (substr.front() == '"' && substr.back() == '"')
        {
            substr = substr.substr(1, substr.size() - 2);
        }
        strs.push_back(substr);
        s.erase(0, pos + delimiter.length());
    }
    // Handle the last element
    if (!s.empty())
    {
        strs.push_back(s);
    }
    return strs;
}
vector<int> SplitBooksids(const string &str)
{
    string s = str;
    // Remove curly braces if present
    if (s.front() == '{' && s.back() == '}')
    {
        s = s.substr(1, s.size() - 2);
    }

    vector<int> bookIds;
    size_t pos = 0;
    string token;
    string delimiter = ",";

    while ((pos = s.find(delimiter)) != string::npos)
    {
        token = s.substr(0, pos);
        bookIds.push_back(ToInt(token));
        s.erase(0, pos + delimiter.length());
    }
    if (!s.empty())
    {
        bookIds.push_back(ToInt(s));
    }
    return bookIds;
}

int ToInt(const string &str)
{
    istringstream iss(str);
    int num;

    iss >> num;

    return num;
}
vector<string> ReadFileLines(const string &path)
{
    vector<string> lines;

    fstream file_handler(path.c_str());

    if (file_handler.fail())
    {
        cout << "\n\nERROR: Can't open the file\n\n";
        return lines;
    }
    string line;
    while (getline(file_handler, line))
    {
        if (line.size() == 0)
        {
            continue;
        }
        lines.push_back(line);
    }
    file_handler.close();
    return lines;
}
int ReadInt(int low, int high)
{
    cout << "\nEnter number in range " << low << " - " << high << ": ";
    int value;

    cin >> value;
    if (low <= value && value <= high)
        return value;

    cout << "ERROR: invalid number...Try again\n";
    return ReadInt(low, high);
}
int showReadMenuAdmin(const vector<string> &choices)
{
    cout << "\nMenu:\n";
    for (int ch = 0; ch < (int)choices.size(); ++ch)
    {
        cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
    }
    return ReadInt(1, choices.size());
}
void WriteFileLines(const string &path, const vector<string> &lines, bool append)
{
    auto status = ios::in | ios::out | ios::app;

    if (!append)
    {
        status = ios::in | ios::out | ios::trunc; // overwrite
    }

    fstream file_handler(path.c_str(), status);

    if (file_handler.fail())
    {
        cout << "\n\nERROR: Can't open the file\n\n";
        return;
    }
    for (auto line : lines)
    {
        file_handler << line << "\n";
    }
    file_handler.close();
}
