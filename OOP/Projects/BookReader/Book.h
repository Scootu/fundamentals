#ifndef BOOK
#define BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem> // Requires C++17 or later
using namespace std;
namespace fs = filesystem;

class Book {
    int book_id;
    string admin_id;
    string title;
    string author;
    int year;
    //vector<pair<string, string>> chapters; // chapter name + content
    
    public :
    Book():year(-1){}
    Book(const string& line){
        vector<string> str = SplitString(line);
        assert(str.size() == 5);
        book_id = ToInt(str[0]);
        admin_id = ToInt(str[1]);
        title = str[2];
        author = str[3];
        year = str[4];
    }

    int GetBookId(){
        return book_id;
    }
    string GetAdminId(){
        return admin_id;
    }
    string GetBookTitle(){
        return title;
    }
    string GetAuthor(){
        return author;
    }
    int Getyear(){
        return year;
    }
    
};
/*
Book parseBookFile(const string& filename) {
    Book book;
    ifstream inFile(filename);
    string line;
    string currentChapter;
    string currentContent;
    
    if (!inFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return book;
    }
    
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        
        // Check for metadata tags
        if (line.find("[TITLE]") == 0) {
            book.title = line.substr(7);
        }
        else if (line.find("[AUTHOR]") == 0) {
            book.author = line.substr(8);
        }
        else if (line.find("[YEAR]") == 0) {
            book.year = stoi(line.substr(6));
        }
        // Check for chapter markers
        else if (line.find("[CHAPTER") == 0) {
            if (!currentChapter.empty()) {
                book.chapters.emplace_back(currentChapter, currentContent);
                currentContent.clear();
            }
            currentChapter = line;
        }
        else {
            currentContent += line + "\n";
        }
    }
    
    // Add the last chapter
    if (!currentChapter.empty()) {
        book.chapters.emplace_back(currentChapter, currentContent);
    }
    
    inFile.close();
    return book;
}
*/
/*
void saveChaptersToFiles(const Book& book, const string& outputDir) {
    // Create output directory if it doesn't exist
    fs::create_directory(outputDir);
    
    // Save each chapter to a separate file
    for (size_t i = 0; i < book.chapters.size(); ++i) {
        string filename = outputDir + "/chapter_" + to_string(i + 1) + ".txt";
        ofstream outFile(filename);
        
        if (outFile.is_open()) {
            outFile << book.chapters[i].first << "\n\n"; // Chapter title
            outFile << book.chapters[i].second;          // Chapter content
            outFile.close();
            cout << "Saved: " << filename << endl;
        } else {
            cerr << "Error creating file: " << filename << endl;
        }
    }
}

*/
#endif