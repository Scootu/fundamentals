#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#include <string>

using std::string;

struct Time
{
    int getMinute();
    int getSecond();
    int getHoure();
    string getTime();

    Time(int h,int m,int s);
private:
    int minute_;
    int second_;
    int houre_;
};



#endif // TIME_H_INCLUDED