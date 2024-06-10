#include <iostream>
#include <cctype>
#include <limits>
#include <assert.h>
#include <vector>
using namespace std;

int ConvertToInt(const char *sNumber)
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
        sNumber++;                           // Move the pointer to the next character in Memory allocation
    }
    return iNum * sign;
}

void Grouping(const char *sequence) // 111222365ffff887f45f
{
    if (sequence == nullptr || *sequence == '\0')
        return;
    char fsPtr = *sequence;
    // Find the null terminator in temp
    string temp;
    temp += fsPtr;
    sequence++;               // Move to the next character
    while (*sequence != '\0') // Until the sequence end
    {
        if (fsPtr != *sequence)
        {
            fsPtr = *sequence;
            cout << temp;
            cout << " ";
            temp = "";
        }
        temp += *sequence;

        sequence++;
    }
}
bool LessThan(const char *str1, const char *str2)
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
    assert(isdigit(num[0]));
    int i = 0, k = 0, sum = 0;
    int cnt = 1;
    string sSum = "", sNum = "";

    // Find the length of the string
    while (num[i] != '\0')
    {
        i++;
    }
    int t = 0;
    if (i >= 6)
    {
        for (; t < 6; t++)
        {
            sNum += num[t + (i - 6)];
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
    for (int j = t - 1; j >= 0; j--)
    {
        sum = sum + (sNum[j] - '0') * cnt;
        cnt *= 10;
    }

    // Add 9999 to the integer
    sum += 9999;
    cout << sum << endl;
    // Convert the sum back to a string
    while (sum > 0)
    {
        sSum = char(sum % 10 + '0') + sSum;
        sum = sum / 10;
        k++;
    }
    while (k < t)
    {
        sSum = '0' + sSum;
        k++;
    }
    for (int z = (i - 6) - 1; z >= 0; z--)
    {
        sSum = num[z] + sSum;
    }
    return sSum;
}
vector<int> sumQuery(int arr[], int size1, int queries[][2], int size2) {
    vector<int> results(size2, 0); // Initialize results with the number of queries

    int accArray[size1] = {0};
    accArray[0] = arr[0];
    cout << accArray[0] << " " ;
    for(int i= 1;i<size1;++i){
        accArray[i] = arr[i] + accArray[i-1];
        cout << arr[i] + accArray[i-1] << " " ;
    }
    cout <<endl;
    // Process each query
    for (int i = 0; i < size2; ++i) { //O(n)
        int start = queries[i][0];
        int iEnd = queries[i][1];

        // Assert that induces are within bounds
        assert(start >= 0 && iEnd < size1 && start <= iEnd);
        int index = iEnd - start ;
        // Compute sum for the interval [start, iEnd]
        results[i] = accArray[index];
    }

    return results;
}
int main()
{
    const char *test1 = "12345";
    cout << ConvertToInt(test1) << endl;

    const char *test2 = "-12345";
    cout << ConvertToInt(test2) << endl;

    const char *test3 = "abc";
    cout << ConvertToInt(test3) << endl;
    // Grouping function
    const char *test4 = "111222365ffff887f45f";
    Grouping(test4);
    cout << add9999("100256") << endl;
    // cout << add9999("Hello")<<endl; Check if it is a digit
    // Check it with long numbers
    cout << add9999("100000000000000000000000000999999")<<endl; // This number impossible to make with int
    //Sum query
    int arr[7] = {1,2,5,77,8,2,9}; // 1 3 8 85 93 95 104
    int queries[3][2] = {{0,4},{1,3}}; // 93 8
    vector<int> results(2);
    results = sumQuery(arr,7,queries,2);
    for(int num:results){
        cout << num <<" "; // 10 82
    }

    return 0;
}
