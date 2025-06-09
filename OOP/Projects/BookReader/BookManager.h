#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h"
#include "Admin.h"
#include "User.h"

using namespace std;

class BookManager
{
    int last_id = 0;
    map<int, Book> booksid_to_BookObject_map;

public:
    BookManager()
    {
        last_id = 0;
    }
    void LoadDataBase()
    {
        booksid_to_BookObject_map.clear();
        vector<string> lines = ReadFileLines("booklists.txt");
        for (const auto &line : lines)
        {
            Book book(line);
            last_id = max(last_id, book.GetBookId());
            booksid_to_BookObject_map[book.GetBookId()] = book;
        }
    }
    const map<int, Book> &GetBookIdToBookObjMap()
    {
        return booksid_to_BookObject_map;
    }
    void AddNewBook(Admin &admin)
    {
        // I need the book object to add to a list of map<int, vector<Book>> adminId_booksObject_map;
        //  do i need that or i just need to update the books_ids_from_admin ?
        LoadDataBase();
        //increament last_id
        ++last_id;
        Book book;
        string str;
        int currrent_number;
        cin.ignore();
        cout << "Enter title : ";
        getline(cin, str);
        book.SetBookTitle(str);
        cout << "Enter author: ";
        getline(cin, str);
        book.SetAuthor(str);
        cout << "Enter year: ";
        cin >> currrent_number;
        book.SetYear(currrent_number);
        cout << "Enter total pages number: ";
        cin >> currrent_number;
        book.SetTotalPageNumber(currrent_number);

        cout<<"Enter pages content\n";
        book.SetPagesContent();
        book.SetBookId(last_id);
        book.SetAdminId(admin.GetAdminId());
        admin.SetBookIdtoAdminList(last_id);
        booksid_to_BookObject_map[last_id] = book;
        book.SaveBookDataBase();
        UpdateDatabase(); // UpdateDatabse book
        
    }
    int ReadBookIdAny() const
    {
        int book_id;
        cout << "Enter Book id or -1 to cancel: ";
        cin >> book_id;

        if (book_id == -1)
            return -1;

        if (!booksid_to_BookObject_map.count(book_id))
        {
            cout << "\nERROR: No book with such ID. Try again\n\n";
            return ReadBookIdAny();
        }
        // const Book &book = bookid_bookobject_map.find(book_id)->second;

        return book_id;
    }

    void PrintListOfbookSystem()
    {
        for (const auto &pair : booksid_to_BookObject_map)
        {
            pair.second.Print();
        }
    }
    vector<int> GetListOfBooksIds()
    {
        LoadDataBase();
        vector<int> books_ids;
        for (const auto &pair : booksid_to_BookObject_map)
        {
            books_ids.push_back(pair.first);
        }
        return books_ids;
    }
    vector<Book> GetlistofBooks(const Admin &admin) // This is for an admin
    {
        LoadDataBase();
        const vector<int> &books_ids = admin.GetBooksIdsFromAdmin();
        vector<Book> books;
        for (const auto &book_id : books_ids)
        {
            if (!booksid_to_BookObject_map.count(book_id))
            {
                continue;
            }
            books.push_back(booksid_to_BookObject_map[book_id]);
        }

        return books;
    }

    void BookReadingFlow(Book &book)
    {
        // current_book = book; //?
        int choice;
        int current_pagenb = 0;
        book.ViewPageContent(0); // view first page
        do
        {

            cout << "Enter -1 to stop reading 1 to next page 0 to previous page :\n";
            cin >> choice;
            while (choice < -1 || choice > 1)

            {
                cout << "Invalid input, Try another value!\n";
                cin >> choice;
            }
            // show book content
            if (choice == 1)
            {
                book.ViewPageContent(++current_pagenb);
            }
            else if (choice == 0)
            {
                book.ViewPageContent(--current_pagenb);
            }
            else
            {
                return;
            }
        } while (choice != -1);
        book.SetLpn(current_pagenb);
    }

    void UpdateDatabase()
    {
        vector<string> lines;
        for (const auto &book : booksid_to_BookObject_map)
        {
            string line = book.second.ToString();
            lines.push_back(line);
        }
        WriteFileLines("booklists.txt", lines);
    }
};
#endif