#ifndef BOOKMANAGER
#define BOOKMANAGER_H

#include "Book.h"
#include "Helper.cpp"
#include <map>
#include <string>
using namespace std;
class BookManager
{
    int last_id;
    map<int, Book> booksid_to_BookObject_map;

public:
    BookManager()
    {
        last_id = 0;
    }
    void LoadDataBase()
    {
        last_id = 0;
        booksid_to_BookObject_map.clear();

        vector<string> lines = ReadFileLines("booklists.txt");
        for (auto &line : lines)
        {
            Book book(line);
            last_id = max(last_id, book.GetBookId());
            booksid_to_BookObject_map[book.GetBookId()] = book;
        }
    }
    const Book &addNewBook()
    {
    }
    const vector<Book>& GetlistofBooks(const vector<int> &books_ids)
    {
        LoadDataBase();
        vector<Book> books;
        for (auto book_id& : books_ids)
        {
            if(booksid_to_BookObject_map.find(book_id)!= -1)
            books.push_back(booksid_to_BookObject_map[book_id]);
        }
        return books;
    }
}
#endif