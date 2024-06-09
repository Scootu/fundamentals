#include <iostream>
#include <cctype>
#include <limits>
using namespace std;

int ConvertToInt(const char* sNumber)
{
    if (sNumber == nullptr || *sNumber == '\0')
    {
        return 0; // Handle empty or null input
    }
    int iNum = 0;
    int sign = 1; // Assume positive, adjust if needed
    if (*sNumber == '-' || *sNumber == '+')
    {
        if (*sNumber == '-')
        {
            sign = -1;
        }
        sNumber++; // Skip the sign character in the memory
    }
    while (*sNumber != '\0')
    {
        if (!isdigit(*sNumber))
        {
            return numeric_limits<int>::min(); // Indicate invalid input
        }

        iNum = iNum * 10 + (*sNumber - '0'); // Subtracting the ASCII value of '0' from any digit character converts it to its corresponding numerical value.
        sNumber++; // Move the pointer to the next character in Memory allocation
    }
    return iNum * sign;
}

void Grouping(const char* sequence) // 111222365ffff887f45f
{
    if(sequence == nullptr || *sequence == '\0')
        return;
    char fsPtr = *sequence;
    // Find the null terminator in temp
    string temp;
    temp += fsPtr;
    sequence++; // Move to the next character
    while(*sequence != '\0') //Until the sequence end
    {
        if(fsPtr != *sequence)
        {
            fsPtr = *sequence;
            cout <<temp;
            cout <<" ";
            temp ="";
        }
        temp += *sequence;

        sequence++;
    }

}
int main()
{
    const char* test1 = "12345";
    cout << ConvertToInt(test1) << endl;

    const char* test2 = "-12345";
    cout << ConvertToInt(test2) << endl;

    const char* test3 = "abc";
    cout << ConvertToInt(test3) << endl;
    //Grouping function
    const char* test4 = "111222365ffff887f45f";
    Grouping(test4);
    return 0 ;
}
