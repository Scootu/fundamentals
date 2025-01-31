#include <iostream>

using namespace std;


class ClassA { 
private:
    int *val;
public:
    ClassA(int v) {
        val = new int;
        *val = v;
    }
    ClassA(const ClassA& A){
        val = new int;
        *val = *A.val;
    }
    ~ClassA() { 
          delete val;
          val = NULL;
     }

     int* GetVal() {  // return content of pointer instead of a pointer (Deep copy)
         return val;
     }
     
     void SetVal(int* val) { 
          *(this->val) = *val; // Use a Deep Copy
     }
};

int main() { 
    ClassA a1(10);
    ClassA a2(20);
    a2.SetVal(a1.GetVal()); // Copy 
    delete a1.GetVal(); // Risk of dangling pointers and double deletions.
    cout<<*a2.GetVal()<<endl;
    return 0;
}