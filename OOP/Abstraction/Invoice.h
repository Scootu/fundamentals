#include <string>
#include <utility>

using std::string ;

class Invoice  {
  private:
  string name_ ;
  int item_number_ ;
  float price_;
  int quantity_;

  public:
  Invoice():name_("Acer laptop"),item_number_(1011234),price_(3250.2),quantity_(2){};
  Invoice(string name,int item_number,float price,int quantity) : name_(std::move(name)),item_number_(item_number),price_(price),quantity_(quantity) {}
  // Setters
  void set_name(string name);
  void set_price(float price);
  void set_item_number(int item_number);
  void set_quantity(int quantity);
  // Getters
  string get_name();
  int get_item_number();
  float get_price();
  int get_quantity();
  //
  float GetTotalPrice();
  void Print();
  string ToString(); // Return a string for them comma separated
};
