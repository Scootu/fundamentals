#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <string>

using std::string;
namespace Date_ { 
struct Date
{
    int getDay();
    int getMonth();
    int getYear();
    string getDate();

     // Constructors
    Date(int d, int m, int y);  // Day, Month, Year
    Date(int m, int y);         // Month, Year (assume day = 1)
    //Date(int d, int m);         // Day, Month (assume year = current year)

    // Static methods for alternative order
    static Date fromYearMonthDay(int y, int m, int d); // Year, Month, Day
private:
    int day_;
    int month_;
    int year_;

};
}
#endif // DATE_H_INCLUDED
