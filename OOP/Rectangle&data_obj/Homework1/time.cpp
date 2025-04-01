

#include "time.h"
#include <string>
#include <sstream> // For std::ostringstream
#include <iomanip> // For std::setw and std::setfill

using std::string;

Time::Time(int h,int m,int s): houre_(h),minute_(m),second_(s){};
int Time::getHoure(){
    return houre_;
}
int Time::getMinute(){
    return minute_;
}
int Time::getSecond(){
    return second_;
}
string Time::getTime(){
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << houre_ << ":"
        << std::setw(2) << std::setfill('0') << minute_ << ":"
        << std::setfill('0') << second_;
    return oss.str();
}