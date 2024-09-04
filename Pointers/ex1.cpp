#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;
int countWords(string line){
    int i = 0 ,nWords = 0;

    istringstream iss(line);
    while(i < line.length()){
        string str;
        if(iss >> str)
            ++nWords;
        ++i;
    }
    return nWords;
}
void letterOccu(string line)
{
    const int l = 26 ;
    int arr[l] = {0};
    int a = 26 - ('z' - 'z');
    int i = 0 ;
    istringstream iss(line);
    while(i < line.length()){
        char t ;
        if(iss >> t && isalpha(t)){
           t = tolower(t);
           int a = 26 - ('z' - t);
           ++arr[a-1];
        }
    i++;
    }

    for(int i = 0 ; i < 26; ++i){
        if(arr[i] > 0){

        char l = 'z' - (26 - (i +1));
        cout <<arr[i] << " "<<l << endl;
        }
    }

}
int main(){
    cout <<"Please enter a line of text: \n";
    string line;
    getline(cin,line);
    cout << countWords(line) <<" words"<<endl;
    letterOccu(line);
    return 0 ;
}
