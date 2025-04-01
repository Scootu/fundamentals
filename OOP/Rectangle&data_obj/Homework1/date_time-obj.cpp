#include <iostream>

#include "date.h"
#include "time.h"
using std::cout;
using std::cin;
using std::endl;

using Date_::Date;

int main(){
    Date date1(14, 7, 2024);  // Create Date object
    Date date2(7,2004);
    Date date3(2007,5,16);
    //Time 
    Time time1(8,15,99);
    cout <<date1.getDate() << endl;  // Print the day
    cout <<date2.getDate() << endl;
    cout <<date3.getDate() << endl;
    cout << time1.getTime() <<endl;
    return 0 ;
}
