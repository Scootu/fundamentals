#include <iostream>
#include <cctype>
#include <limits>
#include <assert.h>
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
bool LessThan(const char* str1, const char* str2)
{
    // Check for null pointers
    assert(str1 != nullptr && str2 != nullptr);

    // Compare characters until the end of one of the strings
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 < *str2)
        {
            return true;
        }
        else if (*str1 > *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }

    // If str1 is shorter than str2, it is lexicographically smaller
    if (*str1 == '\0' && *str2 != '\0')
    {
        return true;
    }

    // If str1 is longer than str2, it is not lexicographically smaller
    return false;
}

// I lose my main file for no risen just codeblocks crash and a lost a lot of solutions and this what i get

string add9999(string num)
{

// Check if it's a number
    int i = 0, k = 0, sum = 0;
    int cnt = 1;
    string sSum = "", sNum = "";

// Find the length of the string
    while (num[i] != '\0')
    {
        i++;
    }
    int t = 0;
    if(i>=6)
    {
        for (;t < 6; t++)
        {
            sNum += num[t+(i-6)];
        }
    }
    else
    {
        // Get the first 6 digits
        for (; t < 6; t++)
        {
            sNum += num[t];
        }

    }

// Convert sNum to an integer
    for (int j = t -1 ; j >= 0; j--)
    {
        sum = sum + (sNum[j] - '0') * cnt;
        cnt *= 10;
    }

// Add 9999 to the integer
    sum += 9999;
    cout <<sum<<endl;
// Convert the sum back to a string
    while (sum > 0)
    {
        sSum = char(sum % 10 + '0') + sSum;
        sum = sum / 10;
        k++;
    }
    while(k<t)
    {
        sSum = '0' + sSum;
        k++;
    }
    for(int z = (i-6)-1;z<=0;z--){
        sSum = num[z] + sSum;
    }
    cout <<num<<endl;
    cout <<sSum<<endl;
    return sSum;
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
    cout<<add9999("10000000000")<<endl;
    return 0 ;
}
