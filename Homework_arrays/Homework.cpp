#include <iostream>
#include <cctype>
#include <limits>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
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
bool sumINarray(int arr[],int size,int sum)// we suppose the array is sorted in ascending way
{
    for(int i =0 ; i<size; ++i)  //O(n�)
    {
        for(int j = i+1; j<size; ++j)
        {
            if(arr[i] + arr[j] == sum)
            {
                return true;
            }
        }
    }
    return false;
}
// This function generated by chatGpt
bool sumINarrayGpt(int arr[], int size, int sum)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int current_sum = arr[left] + arr[right];
        if (current_sum == sum)
        {
            return true;
        }
        else if (current_sum < sum)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return false;
}
int numberOfDigits(int number)
{
    if (number == 0) return 1;  // Special case for 0
    return log10(abs(number)) + 1;
}
/* void bigFactorial(int fac) // This my function to calculate factorial , it's work correct until 60! give a false result !
{
    const int Max = 10000000;
    vector<int> reversedFac(Max);
    reversedFac[0] = 1 ; // Initialize first element by 1 // 1
    //Think in it as reversed array the arr[0] = first digits
    int t = 1 ;
    for(int i = 2 ; i< fac+1; ++i)
    {
        //Multiply i by every cell and get the carry to the next cell
        //Loop
        int z = 0 ;
        while(z < t)
        {
            reversedFac[z] = reversedFac[z] * i ; // 0 2 3 0 4
            z++;
        }
        z = 0 ;
        int j = t; // 4
        while(z < j)  // 2
        {
            int mul = reversedFac[z] ;
            if(mul > 9)  // Move carry to next digit  k = 0
            {
                reversedFac[z] = mul % 10 ; // First digit //
                reversedFac[z + 1] = mul / 10 + reversedFac[z+1]  ; // 12
                if(t <= z + 1)
                {
                    t++; // the last position 3
                }
            }
            ++z; // 2 3 4 end
        }

    }
    cout <<fac<<"! = ";
    for(int num = t - 1 ; num >= 0; --num)
    {
         cout << reversedFac[num];
    }
    cout <<endl;
}*/
void bigFactorial(int fac)
{
    const int Max = 10000000;
    vector<int> reversedFac(Max, 0);
    reversedFac[0] = 1; // Initialize first element by 1
    int t = 1; // Number of digits in the result

    for (int i = 2; i <= fac; ++i)
    {
        // Multiply i by every cell and get the carry to the next cell
        int carry = 0;
        for (int j = 0; j < t; ++j)
        {
            int prod = reversedFac[j] * i + carry;
            reversedFac[j] = prod % 10; // Store last digit of the product in current cell
            carry = prod / 10; // Carry over the remaining part
        }

        // Process the remaining carry
        while (carry)
        {
            reversedFac[t] = carry % 10;
            carry /= 10;
            ++t; // Increment the number of digits
        }
    }

    cout << fac << "! = ";
    for (int num = t - 1; num >= 0; --num)
    {
        cout << reversedFac[num];
    }
    cout << endl;
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
    for(int num:results)
    {
        cout << num <<" "; // 10 82
    }
    cout <<endl;
    int testArraySorted[] = {1, 4, 7, 9, 10, 12, 15, 18, 20, 22, 23, 25, 27, 29, 32, 34, 35, 37, 39, 40, 42, 44, 46, 48, 49, 50, 52, 54, 56, 58, 60, 62, 63, 65, 67, 69, 70, 72, 74, 76, 78, 79, 81, 83, 85, 87, 88, 90, 92, 94, 95, 97, 99, 101, 103, 105, 107, 109, 110, 112, 114, 116, 118, 120, 122, 124, 126, 127, 129, 131, 133, 135, 137, 139, 140, 142, 144, 146, 148, 150, 152, 153, 155, 157, 159, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 179, 181, 183, 185, 187};
    cout <<searchNum(testArraySorted,100,78)<<endl; // 0.0527ms
    // cout <<nonsortedSearchNum(testArraySorted,100,78)<<endl; // 0.0507ms
    cout << sumINarray(testArraySorted,100,42)<<endl; // 20 + 22
    cout << sumINarrayGpt(testArraySorted,100,42)<<endl; // 20 + 22 O(n)
    bigFactorial(60); // 24
    return 0;
}
