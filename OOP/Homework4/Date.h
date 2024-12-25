#ifndef DATE_H
#define DATE_H

#include "Date.cpp"
#include <iostream>
using namespace std;


Date::Date(const int &d, const int &m, const int &y) : year_(y), month_(m), day_(d) {}
bool Date::valid() const
{
    // Check if the year is valid (assuming only non-negative years are valid)
    if (year_ < 0)
        return false;

    // Check if the month is within 1-12 range
    if (month_ < 1 || month_ > 12)
        return false;

    // Days in each month (index 0 = January, ..., 11 = December)
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year in February
    bool is_leap_year = (year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0));
    if (is_leap_year && month_ == 2)
        days_in_month[1] = 29;

    // Check if the day is within the valid range for the month
    if (day_ < 1 || day_ > days_in_month[month_ - 1])
        return false;

    return true;
}
int Date::day() const
{
    return day_;
}
int Date::month() const
{
    return month_;
}
int Date::year() const
{
    return year_;
}
void Date::set_day(const int day)
{
    day_ = day;
}
void Date::set_month(const int month)
{
    month_ = month;
}
void Date::set_year(const int year)
{
    year_ = year;
}
bool operator==(const Date &d1, const Date &d2)
{
    // check for equality
    if (!d1.valid())
    {
        return false;
    };
    if (!d2.valid())
    {
        return false;
    };
    if ((d1.day() == d2.day()) && (d1.month() == d2.month()) && (d1.year() == d2.year()))
    {
        return true;
    };
    return false;
}

bool operator!=(const Date &d1, const Date &d2)
{
    return !(d1 == d2);
}
bool operator<(const Date &d1, const Date &d2)
{
    if (!d1.valid())
    {
        return false;
    }; // not meaningful, return anything
    if (!d2.valid())
    {
        return false;
    }; // should really be an exception, but ?
    if (d1.year() < d2.year())
    {
        return true;
    }
    else if (d1.year() > d2.year())
    {
        return false;
    }
    else
    { // same year
        if (d1.month() < d2.month())
        {
            return true;
        }
        else if (d1.month() > d2.month())
        {
            return false;
        }
        else
        { // same month
            if (d1.day() < d2.day())
            {
                return true;
            }
            else
            {
                return false;
            }
        };
    };
    return false;
};
bool operator>(const Date &d1, const Date &d2)
{
    if (d1 == d2)
    {
        return false;
    }; // this is strict inequality
    if (d1 < d2)
    {
        return false;
    };
    return true;
}
bool operator<=(const Date &d1, const Date &d2)
{
    if (d1 == d2)
    {
        return true;
    }
    return (d1 < d2);
}
bool operator>=(const Date &d1, const Date &d2)
{
    if (d1 == d2)
    {
        return true;
    };
    return (d1 > d2);
};
inline Date next_Date(const Date &d)
{
    Date ndat;
    if (!d.valid())
    {
        return ndat;
    };
    ndat = Date((d.day() + 1), d.month(), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(1, (d.month() + 1), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(1, 1, (d.year() + 1));
    return ndat;
}
inline Date previous_Date(const Date &d)
{
    Date ndat;
    if (!d.valid())
    {
        return ndat;
    }; // return zero
    ndat = Date((d.day() - 1), d.month(), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(31, (d.month() - 1), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(30, (d.month() - 1), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(29, (d.month() - 1), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(28, (d.month() - 1), d.year());
    if (ndat.valid())
        return ndat;
    ndat = Date(31, 12, (d.year() - 1));
    return ndat;
}

Date Date::operator++(int)
{ // postfix operator
    Date d = *this;
    *this = next_Date(d);
    return d;
}
Date Date::operator++()
{ // prefix operator
    *this = next_Date(*this);
    return *this;
}
Date Date::operator --(int)
{ // postfix operator, return current value
    Date d = *this;
    *this = previous_Date(*this);
    return d;
}
Date Date::operator --()
{ // prefix operator, return new value
    *this = previous_Date(*this);
    return *this;
};
inline long long_Date(const Date &d)
{
    if (d.valid())
    {
        return d.year() * 10000 + d.month() * 100 + d.day();
    };
    return -1;
};
ostream &operator<<(ostream &os, const Date &d)
{
    if (d.valid())
    {
        os << " " << d.day() << "/" << d.month() << "/" << d.year();
    }
    else
    {
        os << " invalid date ";
    };
    return os;
}

Date::~Date()
{
    cout << "Terminat object" << endl;
}
#endif