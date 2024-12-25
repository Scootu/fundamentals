
#include "helper.h"

#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include <vector>
using std::cin;
using std::cout;
using std::istringstream;
using std::shared_ptr;
using std::string;
using std::vector;

namespace Faculty
{

    double Helper::Probability()
    {
        return rand() * 1.0 / RAND_MAX;
    }

    /*
     * TODO: This function doesn't handle every wrong error.
     *  E.g.: 10.23
     *    In these examples, we read the integer part and return
     */
    int Helper::ReadInt(int low, int high)
    {
        // let's read it as string to avoid any stream problems...and validate it.
        string input;

        cin >> input;

        istringstream stringstreamObj(input);

        // TIP: Always define variables as close as to their first usage
        int value;
        stringstreamObj >> value;

        if (stringstreamObj.fail())
        {
            cout << "ERROR: Expected integer input...Try again - Enter number ";
            return ReadInt(low, high);
        }

        if (low <= value && value <= high)
            return value;

        cout << "ERROR: Expected range is low = " << low << ", high = " << high << "...Try again - Enter number ";
        return ReadInt(low, high);
    }

    string Helper::ToString(int val, int length)
    {
        ostringstream oss;

        oss << val;

        string ret = oss.str();

        while ((int)ret.size() < length)
            ret = "0" + ret;

        return ret;
    }

    int Helper::RunMenu(vector<string> &menu)
    {
        cout << "\n\nPlease make a choice:\n";

        for (int i = 0; i < (int)menu.size(); ++i)
            cout << "\t" << i + 1 << " - " << menu[i] << "\n";

        cout << "\tEnter Choice: ";

        return Helper::ReadInt(1, menu.size());
    }

};
