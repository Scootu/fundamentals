#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

using std::string;

struct Date
{
    int getDay();
    int getMonth();
    int getYear();
    string getDate();

    Date(int d,int m, int y);
private:
    int day_;
    int month_;
    int year_;

};

#endif // DATE_H_INCLUDED
