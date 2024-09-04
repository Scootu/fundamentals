#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

int main()
{

    // parameter: c string with path
    ifstream inputStream("C:\\Users\\anesHamdaoui\\c++\\Headers_Includes\\input.txt");

    if(inputStream.fail())
    {
        cout <<"Seems file is not there...or can't open it\n";
        return 0;
    }

    string line;
    //cin>>x;
     // Loop to read each line from the file
    while (getline(inputStream, line))
    {
        cout << line << endl;
    }

    inputStream.close();     //CLOSE if opened
    return 0;
}
