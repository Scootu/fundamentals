#include <iostream>

using namespace std;

int main()
{
    //Fibonacci series
    for(int i = 0,a = 1, b =2,temp = 0; i < 10 && a < 60; ++i,temp = a + b,a =b, b =temp)
        cout << a<< " ";
    cout <<"\n";
    cout << "The deference between per and post increment ++i & i++ in a for loop \n";
    for(int i = 0; i<10; i++)
    {
        cout << i <<" ";
    }
    cout << "\n";
    for(int i = 0; i<10; ++i)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << "It's the same \n";
    int iNum = 0 ;
    for(int i = 1 ; i <= 100; i++)
    {
        if(i % 4 == 0 )
            iNum++;
        else if(i % 6 ==0 && i % 10 == 0)
        {
            iNum++;
        }
    }
    cout <<
         "The total number of integers in the range up to 100 that are divisible by 4 or by both 6 and 10 is:"<<iNum<<endl;
    //Find how many numbers
    int iCount  = 0 ;
    for(int i = 0;i<100;i++){
        for(int j = (i>=70? i + 1 :70);j<200;j++){
            if(i<j && (i+j) % 7 == 0){
                iCount++;
            }
        }
    }
    cout << "The total number x + y x[1-100] y[70-200] divisible by 7 is "<<iCount<<endl;
    int iCount1 = 0 ;
    for(int i = 0;i< 100;i++){
        for(int j = 0 ;j<100;j++){
            for(int k = 0 ; k< 100 ;k++){
               int t = 100 - (i+j+k);
                    if(t>=0 && t<100){
                        iCount1++;
                    }
            }
        }
    }
    cout <<"Total of 4 numbers in range [1-100] equal to 100"<<iCount1<<endl;
    return 0;

}
