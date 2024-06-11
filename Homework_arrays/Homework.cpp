#include <iostream>
#include <cctype>
#include <limits>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <chrono>
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
vector<int> sumQuery(int arr[], int size1, int queries[][2], int size2)
{
    vector<int> results(size2, 0); // Initialize results with the number of queries

    int accArray[size1] = {0};
    accArray[0] = arr[0];
    cout << accArray[0] << " " ;
    for(int i= 1; i<size1; ++i)
    {
        accArray[i] = arr[i] + accArray[i-1];
        cout << arr[i] + accArray[i-1] << " " ;
    }
    cout <<endl;
    // Process each query
    for (int i = 0; i < size2; ++i)   //O(n)
    {
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
bool searchNum(int arr[],int size,int num) // 10 elements sorted
{
    int md= size / 2 ;
    if(num > md)
    {
        for(int i = md; i<size; ++i) // O(n)
        {
            if(arr[i] == num)
            {
                return true;
            }
        }
    }
    else
    {
        for(int i = 0; i<md; ++i) // O(n)
        {
            if(arr[i] == num)
            {
                return true;
            }
        }
    }


    return false;
}
bool nonsortedSearchNum(int arr[],int size,int num)
{
    for(int i = 0; i<size; ++i) // O(n)
    {
        if(arr[i] == num)
        {
            return true;
        }
    }
    return false ;
}
int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
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
    for(int num:results)
    {
        cout << num <<" "; // 10 82
    }
    cout <<endl;
    int testArraySorted[] = {1, 4, 7, 9, 10, 12, 15, 18, 20, 22, 23, 25, 27, 29, 32, 34, 35, 37, 39, 40, 42, 44, 46, 48, 49, 50, 52, 54, 56, 58, 60, 62, 63, 65, 67, 69, 70, 72, 74, 76, 78, 79, 81, 83, 85, 87, 88, 90, 92, 94, 95, 97, 99, 101, 103, 105, 107, 109, 110, 112, 114, 116, 118, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 139, 140, 142, 144, 146, 148, 150, 152, 153, 155, 157, 159, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 179, 181, 183, 185, 187};
    auto t1 = high_resolution_clock::now();
    cout <<searchNum(testArraySorted,100,78)<<endl; // 0.0527ms
    // cout <<nonsortedSearchNum(testArraySorted,100,78)<<endl; // 0.0507ms
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";

    return 0;
}
