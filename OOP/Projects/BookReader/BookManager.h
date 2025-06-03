#ifndef BOOKMANAGER
#define BOOKMANAGER_H

#include "Book.h"
#include "Admin.h"
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
    void AddNewBook(const Admin& admin)
    {
         //I need the book object to add to a list of map<int, vector<Book>> adminId_booksObject_map; 
         // do i need that or i just need to update the books_ids_from_admin ?
    }

    void PrintListOfbookSystem(){
        for(auto& pair: booksid_to_BookObject_map){
            pair.second.Print();
        }
    }
    const vector<Book>& GetlistofBooks(const Admin& admin) // This is for an admin
    {
        LoadDataBase();
        const vector<int> &books_ids = admin.GetBooksIdsFromAdmin();
        vector<Book> books;
        for (auto book_id& : books_ids)
        {
            if(!booksid_to_BookObject_map.count(book_id)){
                cout << "Book id:"<<book_id<<" doen't exist! \n\n";
                continue;
            }
            books.push_back(booksid_to_BookObject_map[book_id]);
        }
       
        return books;
    }
    void ResetBooksIdtoAdmin();// to Update the books_ids_from_admin
}
#endif