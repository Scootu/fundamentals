#include <iostream>
#include <string>
#include <exception>
#include <vector>
using namespace std;

class PayRoll {
public:
    virtual PayRoll* Clone() {
        throw logic_error("Not implemented. Do override!");
        return nullptr;
    }
    virtual void PayMoney(const PayRoll& payObject) {
        throw logic_error("Not implemented!");
    }
    virtual ~PayRoll() {}
};

class Worker : public PayRoll {
protected:
    string username;

public:
    Worker(const string& name = "") : username(name) {}

    virtual string GetName() const {
        throw logic_error("Not implemented. Override it!");
        return "";
    }

    virtual PayRoll* Clone() override {
        throw logic_error("Not implemented. Override it!");
        return nullptr;
    }

    virtual ~Worker() {}
};

class Volunteers : public Worker {
public:
    Volunteers(const string& name) : Worker(name) {}

    virtual string GetName() const override {
        return username;
    }

    virtual PayRoll* Clone() override {
        return new Volunteers(*this);
    }

    virtual void PayMoney(const PayRoll& payObject) override {
        cout << "Volunteer " << GetName() << " is not paid." << endl;
    }
};

class Pay {
public:
    virtual Pay* Clone() {
        throw logic_error("Not implemented. Override it!");
        return nullptr;
    }

    virtual int GetTotalPaymentPerMonth() const {
        throw logic_error("Not implemented. Override it!");
        return -1;
    }

    virtual int GetTotalPaymentPerDay() const {
        throw logic_error("Not implemented. Override it!");
        return -1;
    }

    virtual ~Pay() {}
};

class Hourly : public Pay {
private:
    int pricePerHour;
    int totalHoursPerDay;

public:
    Hourly(int perHour, int totalHours)
        : pricePerHour(perHour), totalHoursPerDay(totalHours) {}

    virtual Pay* Clone() override {
        return new Hourly(*this);
    }

    virtual int GetTotalPaymentPerDay() const override {
        return pricePerHour * totalHoursPerDay;
    }

    virtual int GetTotalPaymentPerMonth() const override {
        return GetTotalPaymentPerDay() * 30;
    }
};

class Salary : public Pay {
private:
    int dailyAmount;

public:
    Salary(int amountPerDay) : dailyAmount(amountPerDay) {}

    virtual Pay* Clone() override {
        return new Salary(*this);
    }

    virtual int GetTotalPaymentPerMonth() const override {
        return dailyAmount * 30;
    }

    virtual int GetTotalPaymentPerDay() const override {
        return dailyAmount;
    }
};

class Employee : public Worker {
protected:
    Pay* payType;

public:
    Employee(const string& name, Pay* payment)
        : Worker(name), payType(payment) {}

    virtual int GetTotalSalary() const {
        return payType->GetTotalPaymentPerMonth();
    }

    virtual void PayMoney(const PayRoll& payObject) override {
        cout << username << " is paid: " << GetTotalSalary() << " DA" << endl;
    }

    virtual PayRoll* Clone() override {
        return new Employee(*this);
    }

    virtual ~Employee() {
        delete payType;
    }
};

class CommissionEmployee : public Employee {
private:
    int ratio;

public:
    CommissionEmployee(const string& name, Pay* payment, int r)
        : Employee(name, payment), ratio(r) {}

    void SetRatio(int r) {
        ratio = r;
    }

    virtual int GetTotalSalary() const override {
        return payType->GetTotalPaymentPerMonth() * ratio;
    }

    virtual PayRoll* Clone() override {
        return new CommissionEmployee(*this);
    }
};

class Item {
protected:
    string itemName;
    string serialNumber;

public:
    Item() = default;
    Item(const string& name, const string& serial)
        : itemName(name), serialNumber(serial) {}

    virtual Item* Clone() const {
        throw logic_error("Not implemented. Override it!");
        return nullptr;
    }

    virtual ~Item() {}
};

class Book : public Item {
public:
    Book(const string& name, const string& serial)
        : Item(name, serial) {}

    virtual Item* Clone() const override {
        return new Book(*this);
    }
};

class Food : public Item {
public:
    Food(const string& name, const string& serial)
        : Item(name, serial) {}

    virtual Item* Clone() const override {
        return new Food(*this);
    }
};

class Invoice : public PayRoll {
private:
    vector<Item*> items;

public:
    void AddNewItemToInvoice(const Item& item) {
        items.push_back(item.Clone());
    }

    virtual void PayMoney(const PayRoll& payObject) override {
        cout << "Paying invoice with " << items.size() << " items." << endl;
    }

    virtual PayRoll* Clone() override {
        Invoice* newInvoice = new Invoice();
        for (Item* it : items) {
            newInvoice->AddNewItemToInvoice(*it);
        }
        return newInvoice;
    }

    virtual ~Invoice() {
        for (auto ptr : items) {
            delete ptr;
        }
        items.clear();
    }
};

int main() {
    // Create polymorphic list of PayRoll*
    vector<PayRoll*> payrollList;

    // Add Employee
    Pay* hourlyPay = new Hourly(150, 8);
    PayRoll* labourer = new Employee("Ali", hourlyPay);
    payrollList.push_back(labourer);

    // Add CommissionEmployee
    Pay* baseSalary = new Salary(2000);
    PayRoll* sales = new CommissionEmployee("Sara", baseSalary, 2);
    payrollList.push_back(sales);

    // Add Invoice
    Invoice* invoice = new Invoice();
    invoice->AddNewItemToInvoice(Book("C++ Primer", "B123"));
    invoice->AddNewItemToInvoice(Food("Pizza", "F456"));
    payrollList.push_back(invoice);

    // Loop over and pay everyone/invoice
    for (PayRoll* p : payrollList) {
        p->PayMoney(*p);
    }

    // Clean up memory
    for (PayRoll* p : payrollList) {
        delete p;
    }

    return 0;
}

