#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>

using namespace std;
namespace fs = filesystem;

vector<string> SplitString(const string &str, const string &delimiter = ",", bool isSplitBooksIds = false);
vector<int> SplitBooksids(const string &str);
string Trim(const string &str);
int ToInt(const string &str);
vector<string> ReadFileLines(const string &path);
string FindBookContentFile(int book_id, const string &books_dir = "books");
int ReadInt(int low, int high);
int showReadMenu(const vector<string> &choices);
void WriteFileLines(const string &path, const vector<string> &lines, bool append = false);

#endif