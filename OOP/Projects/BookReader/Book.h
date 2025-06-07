#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem> // Requires C++17 or later
#include <cassert>
using namespace std;
namespace fs = filesystem;

class Book
{
    int book_id;
    int admin_id;
    string title;
    string author;
    int year;
    int totalPageNumber;
    int current_page = 0; 
    vector<pair<int, string>> pages; // page content

public:
    Book() : year(-1) {}
    Book(const string &line)
    {
        vector<string> str = SplitString(line);
        assert(str.size() == 6);
        book_id = ToInt(str[0]);
        admin_id = ToInt(str[1]);
        title = str[2];
        author = str[3];
        year = ToInt(str[4]);
        totalPageNumber = ToInt(str[5]);
        // Load pages content
        LoadBookPagesContent();
    }

    int GetBookId() const
    {
        return book_id;
    }
    int GetAdminId() const
    {
        return admin_id;
    }
    string GetBookTitle() const
    {
        return title;
    }
    string GetAuthor() const
    {
        return author;
    }
    int Getyear() const
    {
        return year;
    }
    int GetTotalPageNumber() const
    {
        return totalPageNumber;
    }
    int GetLpn() const {
        return current_page;
    }
    void SetLpn(const int& lpn){
         current_page = lpn;
    }
    void SetBookId(const int &id)
    {
        book_id = id;
    }
    void SetAdminId(const int &id)
    {
        admin_id = id;
    }
    void SetBookTitle(const string &t)
    {
        title = t;
    }
    void SetAuthor(const string &author_)
    {
        author = author_;
    }
    void Print() const
    {
        cout << "Book id: " << book_id << ", Admin id: " << admin_id << ",Title: " << title << ", Author: " << author << ", Year: " << year << ", Total page number: " << totalPageNumber << "\n";
    }
    string ToString() const
    {
        ostringstream oss;
        oss << book_id << "," << admin_id << "," << title << "," << author << "," << year << "," << totalPageNumber;
        return oss.str();
    }

    void LoadBookPagesContent(const string &books_dir = "books")
    {
        pages.clear();

        string filename = FindBookContentFile(book_id, books_dir);
        if (filename.empty())
        {
            cerr << "Error: No content file found for book ID " << book_id << endl;
            return;
        }

        ifstream inFile(filename);
        if (!inFile.is_open())
        {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line;
        string currentPageContent;
        int currentPageNumber = 0;
        bool inPage = false;

        while (getline(inFile, line))
        {
            // Trim trailing whitespace
            size_t endpos = line.find_last_not_of(" \t\r\n");
            if (endpos != string::npos)
                line = line.substr(0, endpos + 1);
            else
                line.clear();

            if (line.empty())
                continue;

            // Detect start of a new page
            if (line.rfind("[PAGE ", 0) == 0)
            {
                // Save the previous page if any
                if (inPage && !currentPageContent.empty())
                {
                    pages.emplace_back(currentPageNumber, currentPageContent);
                    currentPageContent.clear();
                }

                // Extract page number
                size_t endBracket = line.find(']');
                if (endBracket != string::npos)
                {
                    try
                    {
                        currentPageNumber = stoi(line.substr(6, endBracket - 6));
                        inPage = true;
                    }
                    catch (...)
                    {
                        cerr << "Warning: invalid page number in line: " << line << endl;
                        inPage = false;
                    }
                }
            }
            // Ignore metadata tags like [TITLE], [AUTHOR], etc.
            else if (line.rfind("[TITLE]", 0) == 0 || line.rfind("[AUTHOR]", 0) == 0 || line.rfind("[YEAR]", 0) == 0)
            {
                continue;
            }
            else if (inPage)
            {
                // Append line to page content
                if (!currentPageContent.empty())
                    currentPageContent += "\n";
                currentPageContent += line;
            }
        }

        // Add the last page if any
        if (inPage && !currentPageContent.empty())
        {
            pages.emplace_back(currentPageNumber, currentPageContent);
        }

        totalPageNumber = pages.size();
        inFile.close();
    }

    void ViewPageContent(int pagenb) 
    {
        if (pagenb < 0 || pagenb >= static_cast<int>(pages.size()))
        {
            throw out_of_range("Invalid page number: " + to_string(pagenb));
        }

        if (pagenb == static_cast<int>(pages.size()) - 1)
        {
            cout << "Last page! \n";
        }

        cout << pages.at(pagenb).second << "\n";
        //Set last page number 
        SetLpn(pagenb);
    }
};

#endif