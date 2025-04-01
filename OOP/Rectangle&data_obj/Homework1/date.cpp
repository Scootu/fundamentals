#include "date.h"
#include <string>
#include <sstream> // For std::ostringstream
#include <iomanip> // For std::setw and std::setfill

using std::string;
namespace Date_{ 
// Constructors
Date::Date(int d, int m, int y) : day_(d), month_(m), year_(y) {}

// Month and year provided, assume day = 1
Date::Date(int m, int y) : month_(m), year_(y), day_(1) {}

// Day and month provided, assume a default year (e.g., 2024)
//Date::Date(int d, int m) : day_(d), month_(m), year_(2024) {}

// Static method for Year, Month, Day ordering
Date Date::fromYearMonthDay(int y, int m, int d) {
    return Date(d, m, y);
}
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

}