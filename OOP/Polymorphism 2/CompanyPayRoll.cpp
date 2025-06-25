#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <utility>
#include <memory>
using namespace std;

class Payable
{
public:
    virtual Payable *Clone()
    {
        throw logic_error("Not implemented. Do override!");
        return nullptr;
    }
    virtual double GetAmountToPay() const
    {
        throw logic_error("Not implemented!");
    }
    virtual ~Payable() {}
};

class StaffWorker : public Payable
{
private:
    string name;
    string address;

public:
    StaffWorker(const string &name_ = "", const string &address_ = "") : name(name_), address(address_) {}

    virtual string GetName() const
    {
        throw logic_error("Not implemented. Override it!");
        return "";
    }

    virtual Payable *Clone() override
    {
        throw logic_error("Not implemented. Override it!");
        return nullptr;
    }

    virtual ~StaffWorker() {}
};

class Volunteers : public StaffWorker
{
private:
    int current_payment;

public:
    Volunteers(const string &name, const string &address_) : StaffWorker(name, address_), current_payment(0) {}

    virtual Payable *Clone() override
    {
        return new Volunteers(*this);
    }

    virtual double GetAmountToPay() const override
    {
        cout << "Volunteers\n";
        return current_payment;
    }
};

class Employee : public StaffWorker
{
private:
    int day_to_pay;

public:
    Employee(const string &name = "", const string &address_ = "") : StaffWorker(name, address_), day_to_pay(0) {}

    virtual Payable *Clone() override
    {
        return new Employee(*this);
    }

    virtual ~Employee() {}
};

class HourlyEmployee : public Employee
{
private:
    int total_working_hours;
    double salary_per_hour;

public:
    HourlyEmployee(int hours = 0, double rate = 0.0) : total_working_hours(hours), salary_per_hour(rate) {}

    virtual double GetAmountToPay() const override
    {
        cout << "HourlyEmployee\n";
        return total_working_hours * salary_per_hour;
    }

    virtual Payable *Clone() override
    {
        return new HourlyEmployee(*this);
    }
};

class SalariedEmployee : public Employee
{
private:
    double monthly_salary;

public:
    SalariedEmployee(double salary = 0.0) : monthly_salary(salary) {}

    virtual double GetAmountToPay() const override
    {
        cout << "SalariedEmployee\n";
        return monthly_salary;
    }

    virtual Payable *Clone() override
    {
        return new SalariedEmployee(*this);
    }
};

class CommissionEmployee : public SalariedEmployee
{
private:
    double commission_rate;
    double current_month_sales;

public:
    CommissionEmployee(double base_salary = 0.0, double rate = 0.0, double sales = 0.0)
        : SalariedEmployee(base_salary), commission_rate(rate), current_month_sales(sales) {}

    virtual double GetAmountToPay() const override
    {
        cout << "CommissionSalariedEmployee\n";
        return SalariedEmployee::GetAmountToPay() + current_month_sales * commission_rate;
    }

    virtual Payable *Clone() override
    {
        return new CommissionEmployee(*this);
    }
};

class Item
{
protected:
    string itemName;
    string serialNumber;
    double price;
    int quantity;

public:
    Item() : price(0), quantity(0) {}
    Item(const string &name, const string &serial)
        : itemName(name), serialNumber(serial), price(0), quantity(0) {}

    double GetPrice() const
    {
        return price * quantity;
    }

    void SetPrice(double p)
    {
        price = p;
    }

    void SetQuantity(int quantity_)
    {
        quantity = quantity_;
    }

    virtual Item *Clone() const
    {
        throw logic_error("Not implemented. Override it!");
        return nullptr;
    }

    virtual ~Item() {}
};

class Book : public Item
{
public:
    Book(const string &name, const string &serial)
        : Item(name, serial) {}

    virtual Item *Clone() const override
    {
        return new Book(*this);
    }
};

class Food : public Item
{
public:
    Food(const string &name, const string &serial)
        : Item(name, serial) {}

    virtual Item *Clone() const override
    {
        return new Food(*this);
    }
};
class Invoice;
class ValidationRule
{
public:
    virtual ~ValidationRule() = 0;
    virtual bool validate(const Invoice* const invoice) const = 0;
};
// Add this line after the class:
ValidationRule::~ValidationRule() {}

class ValidatorGroup
{
    protected:
    vector<ValidationRule *> rules;

public:

    bool virtual validateInvoice(const Invoice* const invoice) const
    {
         cout << "Validator\n";
        for (const auto &rule : rules)
        {
              rule->validate(invoice);
        }
        return true;
    }

    virtual ~ValidatorGroup() {}
};

class Invoice : public Payable
{
private:
    int invoice_id = -1;
    vector<Item *> items;
    ValidatorGroup* validator; //doen't know which validator/rule

public: 
    Invoice(ValidatorGroup* validator) : validator(validator) {}
    void AddNewItemToInvoice(Item *item)
    {
        items.push_back(item->Clone());
    }

    virtual double GetAmountToPay() const override
    {
        cout << "Invoice\n";
        double sum = 0;
        for (const Item *item_ptr : items)
            sum += item_ptr->GetPrice();

        return sum;
    }

    virtual Payable *Clone() override
    {
        Invoice *newInvoice = new Invoice(validator);
        for (Item *it : items)
        {
            newInvoice->AddNewItemToInvoice(it);
        }
        return newInvoice;
    }

    virtual ~Invoice()
    {
        for (auto ptr : items)
        {
            delete ptr;
        }
        items.clear();
    }
};



class OutOfDateValidationRule : public ValidationRule
{
public:
    bool validate(const Invoice* const invoice) const override
    {
        // Implementation to check if invoice is out-of-date
        // ...
        return true;
    }
};

class TaxAdvantageValidationRule : public ValidationRule
{
public:
    bool validate(const Invoice* const invoice) const override
    {
        // Implementaion to check tax advantages
        // ..
        return true;
    };
};


class MandatoryInvoiceValidator : public ValidatorGroup {
    public:
     MandatoryInvoiceValidator() { //Could be singleton
        rules.push_back(new TaxAdvantageValidationRule());
     }
};
class CompleteInvoiceValidator : public ValidatorGroup {
    public:
      CompleteInvoiceValidator(){
        rules.push_back(new OutOfDateValidationRule());
        rules.push_back(new TaxAdvantageValidationRule());
     }
};

class Payroll
{
private:
    vector<Payable *> payables;

public:
    void AddPayable(Payable *payable)
    {
        payables.push_back(payable->Clone());
    }

    void Pay()
    {
        cout << "Payroll::Pay\n";
        for (const auto payable : payables)
        {
            payable->GetAmountToPay();
        }
    }

    ~Payroll()
    {
        for (auto p : payables)
        {
            delete p;
        }
        payables.clear();
    }
};

class Company
{
private:
    Payroll payroll;
    bool is_use_complete_validations = true;
    ValidatorGroup* validator = nullptr;

public:


    Company(){
        if(is_use_complete_validations){
            validator = new CompleteInvoiceValidator();
            
        }else {
            validator = new MandatoryInvoiceValidator();
        }
    };
    void Run()
    {
        payroll.AddPayable(new Volunteers("John", "123 Street"));
        payroll.AddPayable(new HourlyEmployee(40, 10.5));
        payroll.AddPayable(new SalariedEmployee(3000));
        payroll.AddPayable(new CommissionEmployee(2500, 0.1, 5000));

        Invoice *invoice = new Invoice(validator);
        Book *book = new Book("C++ Book", "B123");
        book->SetPrice(50);
        book->SetQuantity(2);
        invoice->AddNewItemToInvoice(book);

        Food *food = new Food("Lunch", "F456");
        food->SetPrice(10);
        food->SetQuantity(5);
        invoice->AddNewItemToInvoice(food);
        
        payroll.AddPayable(invoice);

        payroll.Pay();
        validator->validateInvoice(invoice);
        delete invoice;
        delete book;
        delete food;
    }
};

int main()
{
    Company company;
    company.Run();

    return 0;
}
