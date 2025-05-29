#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cassert>
#include <fstream>
using namespace std;

vector<string> ReadFileLines(const string &path);
void WriteFileLines(const string &path,const vector<string> &lines, bool append = true);
vector<string> SplitString (const string &str,const string &delimiter = ",");
int ToInt(const string &str);
int ReadInt(int low, int high);
int ShowReadMenu(const vector<string> &choices);
#endif