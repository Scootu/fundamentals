#include <fstream>
#include <iostream>
#include <cstdlib>  // Include this for the exit function

using namespace std;

int main(){
    ofstream outputStream;
    // Double the backslashes in the file path
    string outputPath = "C:\\Users\\anesHamdaoui\\c++\\Headers_Includes\\my_file.txt";

    outputStream.open(outputPath.c_str());

    if(outputStream.fail())
    {
        cout << "Couldn't open output file\n"
             << "\tMaybe permission or wrong path\n";
        exit(1);
    }

    cout << "Let's use the output stream\n";
    outputStream << "Hello world\n";
    outputStream.close();
    return 0;
}
