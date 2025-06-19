#include <bits/stdc++.h>
using namespace std;

class Address
{
private:
    string address;
    string city;
    string name;

public:
    Address()
    {
        address = "non";
        city = "anonymous";
        name = "default";
    }
    Address(string n, string c, string a) : name(n), city(c), address(a) {}
};

class package
{
private:
    Address sender;
    Address receiver;

    double weight;
    double price;

public:
    package()
    {
        weight = 0;
        price = 0;
    }
    package(Address sender_, Address rec, double w, double p) : sender(sender_), receiver(rec), weight(w), price(p) {}

    const Address &GetSender() const
    {
        return sender;
    }
    const Address &GetReceiver() const
    {
        return receiver;
    }
    double GetWeight() const
    {
        return weight;
    }

    double GetPrice() const
    {
        return price;
    }

    // Setters

    void SetSender(const Address &send)
    {
        sender = send;
    }
    void SetReceiver(const Address &rec)
    {
        receiver = rec;
    }
    void SetWeight(const double &w)
    {
        weight = w;
    }
    void SetPrice(const double &p)
    {
        price = p;
    }
    // methods
    double TotalCost() const
    {
        return weight * price;
    }
};

class packageTwoDay : public package
{
private:
    float fee = 1.2; //  value
public:
    packageTwoDay()
    {
        package();
    }
    packageTwoDay(Address sender_, Address rec, double w, double p,double fee_)
    {
        package(sender_, rec, w, p);
        fee = fee_;
    } 
    
    void SetFee(double fee_){
        fee = fee_;
    }
    const double& TotalCost() const {
        return GetWeight() * GetPrice() * fee;
    }

};
class HeavyWeight : public package {
    private:
    const int limit_kg = 100; // 10 kg limit
    double extra_price_per_kg;
    public:
    HeavyWeight(Address sender_, Address rec, double w, double p,double extra_price_per_kg){
        package(sender_,rec,w,p);
        extra_price_per_kg = extra_price_per_kg;
    }
    
	double TotalCost() const {
		double ret = package::TotalCost();

		if (GetWeight() > limit_kg)
			ret += (GetWeight() - limit_kg) * extra_price_per_kg;
		return ret;
	}

};
class Card {
    private:
    string cardNumber;
    string cardHolderName;
    string expiryDate;
    string cvv;
    public:
    Card() {
        // Default constructor
        cardNumber = "0000-0000-0000-0000";
        cardHolderName = "Anonymous";
        expiryDate = "01/01/2000";
        cvv = "000";

    }
    Card(string cardNumber_, string cardHolderName_, string expiryDate_, string cvv_)
        : cardNumber(cardNumber_), cardHolderName(cardHolderName_), expiryDate(expiryDate_), cvv(cvv_) {}
};
class DebitCard: public Card {
    private:
    // No additional fields for DebitCard, but can be extended if needed
    string bankName; // Additional field for DebitCard
    string accountNumber; // Additional field for DebitCard

    public:
    DebitCard() : Card() {} // Default constructor
    DebitCard(string cardNumber_, string cardHolderName_, string expiryDate_, string cvv_, string bankName_, string accountNumber_)
        : Card(cardNumber_, cardHolderName_, expiryDate_, cvv_), bankName(bankName_), accountNumber(accountNumber_) {}
    // Additional methods for DebitCard can be added here
};
class CreditCard: public Card {
    private:
    string creditLimit; // Additional field for CreditCard
    string interestRate; // Additional field for CreditCard
    public:
    CreditCard() : Card() {} // Default constructor
    CreditCard(string cardNumber_, string cardHolderName_, string expiryDate_, string cvv_, string creditLimit_, string interestRate_)
        : Card(cardNumber_, cardHolderName_, expiryDate_, cvv_), creditLimit(creditLimit_), interestRate(interestRate_) {}
    // Additional methods for CreditCard can be added here

};


class shipment {
    private:
    package standard;
    HeavyWeight HeavyPackage;
    packageTwoDay TwoDayPackage;
    Card info;
    vector<package> packages;
    public:
    shipment()
        : standard(), HeavyPackage(Address(), Address(), 0.0, 0.0, 0.0), TwoDayPackage(Address(), Address(), 0, 0, 0), info(), packages() 
    {
        // All members are initialized using their default constructors
    }
    void AddPackage(const package &pack) {
        packages.push_back(pack);
    }
    double TotalPriceOfShipment() const{
          double sum ; 
          for(auto pack: packages){
            sum+= pack.TotalCost();
          }
          return sum;
    }
    void SetCardInfo(Card info_){ // Can be either Debit or Credit card
        info = info_;
    }
};
class Customer {
    private:
    string fullname;
    vector<shipment> shipments;
    vector<Card> cards;

    public:
    Customer(string fullName_) : fullname(fullName_) {}

    void CreateShipment(Card card, package pack) {
        shipment newShipment;
        newShipment.SetCardInfo(card); // Default card info, can be set later
        newShipment.AddPackage(pack); // Default package, can be added later
        shipments.push_back(newShipment);
        cards.push_back(card); // Store the card used for this shipment
    }

    double TotalShipmentPrice() const {
        double sum = 0;
        for(auto ship : shipments){
            sum += ship.TotalPriceOfShipment();
        }
        return sum;
    }

};
class PackageDeliveryService
{

private:

    vector<Customer> customers;

public:
    PackageDeliveryService() {}
    PackageDeliveryService(const vector<Customer> &custs) : customers(custs) {}
    vector<Customer> &GetCustomers()
    {
        return customers;
    }
    void AddCustomer(const Customer &customer)
    {
        customers.push_back(customer);
    }

    double TotalRevenue()
    {
        double total = 0;
        for (const auto &customer : customers)
        {
            total += customer.TotalShipmentPrice();
        }
        return total;
    }
};