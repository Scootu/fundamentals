#include <iostream>
#include <bitset>
using namespace std;

void printNumber(int n , int len)
{
    if(!len){
        return;
    }
    printNumber(n>>1,len-1); // remove last bit
    cout <<(n&1);            // print last bit
}
int countNumBits1(int mask){        // O(bits length)
    int res = 0 ;
    while(mask){
        res++;
        mask >>= 1;
    }
    return res;
}
void printAllSubset(int len){
     for(int i = 0 ; i < (1 << len);++i){
        printNumber(i,len);
     }
}
unsigned int rotateRight(unsigned int number, int rotate_by) {
    int num_bits = sizeof(number) * 8; // Number of bits in an unsigned int (32 bits typically)
    rotate_by = rotate_by % num_bits; // Ensure rotate_by is within the number of bits

    // Perform the rotation using bitwise operations
    unsigned int right_part = number >> rotate_by; // Right shift by rotate_by positions
    unsigned int left_part = number << (num_bits - rotate_by); // Left shift the remaining part

    return (right_part | left_part); // Combine both parts using bitwise OR
}
void intersection(int A[60], int len1, int B[60] , int len2)
{
     int mask1 = 0;
     int mask2 = 0;
     for(int i = 0 ; i < len1 ; ++i)
         mask1 = setBit1(mask1,A[i]);

     for(int i = 0; i < len2;++i)
         mask2 = setBit1(mask2,B[i]);

     int inter = mask1 & mask2; //O(1) noes intersection

      for(int i = 0 ; i< max(len1,len2);++i) {
          if(getBit(inter,i))
             cout << i<< " ";
      }
      cout << "\n";
}
// Better Memory
// Say you have numbers in range 100 Million, and you want to know if some number visited before or NOT
// Simply: bool vis[100 * 1000 * 1000]; and mark in it.
//
// But 100 Million is too much! What about 100Million / 8 = 12500000 12 Milion and half!
// You know that each character is 8 bits. Bool too takes 8 bits. UTILIZE byte!

const int MAX = 100000000;
char vis[MAX / 8 + 1];

void setVisited(int i) { // in past vis[i] = 1
    // Now each byte is responsible for 8 bits.
    // So first we need to know which char is for us. Then my byte is in i / 8
    // And then which bit within us. Any inside this byte in i % 8

    vis[i >> 3] |= (1 << (i & 7));

    // Or more efficiently
    // vis[i>>3] |= 1<<(i&7) );
}

bool isVisited(int i) { // in past if(vis[i])
    return vis[i >> 3] & (1 << (i & 7));
}

int main(){
    int x = 1145;
    bitset<16> binary(x);
    cout << binary<<endl;

    bool odd = x & 1 ; // Compare with the least significant bit and 1 if LSB  = 1 than x&1 == 1 else 0
    cout <<"it's is odd : "<< odd <<endl;
    x = x >> 1 ; // x / 2
    bitset<16> binary1(x);
    cout << binary1<<endl;
    x = x << 2 ; // x * 4
    bitset<16> binary2(x);
    cout << binary2<<endl;
    //Let's try this X%(2^n)  = X & (2^n -1)
    //For example n = 5
    // if(x%(2^5) == x & (2^5 - 1)){
      //  cout << "This sentence is true "<<endl;
   // }
    cout << "print x : ";
    printNumber(x,16);
    cout << endl ;
    cout << "number of bits in x is : ";
    cout <<countNumBits1(x)<< endl;

    // rotate a bit 1646
    bitset<32> bi1(1646);

    int y = 1647;
    printNumber(y,32);
    cout << endl;

    unsigned int z = rotateRight(1646,5);
    printNumber(z,32);
    cout << endl;
    cout << countNumBits1(840) << endl ;
    return 0 ;
}
