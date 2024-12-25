
#include <iostream>
#include <string>
#include "Invoice.h"

using std::cout;
using std::endl;

void Invoice::set_item_number(int item_number){
    item_number_ = item_number ;
}
void Invoice::set_quantity(int quantity){
    quantity_ = quantity;
}
void Invoice::set_name(string name){
    name_ = name ;
}
void Invoice::set_price(float price){
    price_ = price;
}

int Invoice::get_quantity(){
    return quantity_;
}
float Invoice::get_price(){
    return price_;
}
string Invoice::get_name(){
    return name_;
}
int Invoice::get_item_number(){
    return item_number_;
}

float Invoice::GetTotalPrice(){
    return price_*quantity_;
}
void Invoice::Print(){
   cout<<"Invoice : \n";
   cout<<"Item number : "<<item_number_<<"\n";
   cout<<"Name : "<<name_<<"\n";
   cout<<"Price : "<<price_<<"\n";
   cout<<"Quantity : "<<quantity_<<"\n";
   cout <<"Total price :"<<GetTotalPrice()<<"\n";
}

string Invoice::ToString(){
    return std::string(name_) + " " + std::to_string(item_number_) + " " + std::to_string(price_) + " " + std::to_string(quantity_);
}
