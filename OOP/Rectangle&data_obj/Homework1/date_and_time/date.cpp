#include "date.h"
#include <string>
#include <sstream> // For std::ostringstream
#include <iomanip> // For std::setw and std::setfill

using std::string;

Date::Date(int d, int m, int y) : day_(d), month_(m), year_(y) {}

int Date::getDay(){
   return day_;
}
int Date::getMonth(){
   return month_;
}
int Date::getYear(){
    return year_;
}

string Date::getDate() {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << day_ << "/"
        << std::setw(2) << std::setfill('0') << month_ << "/"
        << year_;
    return oss.str();
}

