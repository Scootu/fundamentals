#include<iostream>

using namespace std;

int SumSquare(int arr[], int n) {
    int sum = 0;

     for (int i = 0; i < n;++i) {
         int sq = arr[i];
         sq = sq * sq;
         sum += sq;
     }
    return sum;
 }

int main() {
   int arr[4] = {2, 1, 3, 4};

   int result = SumSquare(arr, 4);

   cout<<"Array sum "<<result<<endl;

   return 0;
}
