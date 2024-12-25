#include <iostream>

#include "Invoice.h"

int main(){
    Invoice invoice1;
    Invoice invoice2("hello",100000,45.3,4);
    invoice1.Print();
    return 0 ;
}
