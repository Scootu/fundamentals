#include <iostream>

#include "date.h"

using std::cout;
using std::cin;
using std::endl;

int main(){
    Date date1(14, 7, 2024);  // Create Date object
    int d = date1.getDay();   // Get the day
    cout << "Day: " << d << endl;  // Print the day
    return 0 ;
}
