#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ===== Interfaces =====
class Object {
public:
    virtual string GetClassName() const = 0;
    virtual ~Object() {}
};

class Cloneable : virtual public Object {
public:
    virtual Object* Clone() const = 0;
    virtual ~Cloneable() {}
};

class Printable : virtual public Object {
public:
    virtual void Print(ostream& out) const = 0;
    virtual ~Printable() {}
};

ostream& operator<<(ostream& out, const Printable& p) {
    p.Print(out);
    return out;
}

class Comparable : virtual public Object {
public:
    virtual bool operator<(Object& obj) const = 0;
    virtual ~Comparable() {}
};

class Payable : public Cloneable, public Printable, public Comparable {
public:
    virtual double GetAmountToPay() const = 0;
    virtual ~Payable() {}
};

// ===== Items and Invoices =====
class Item {
protected:
    string itemName, serialNumber;
    double price;
    int quantity;

public:
    Item(const string& name, const string& serial) : itemName(name), serialNumber(serial), price(0), quantity(0) {}
    virtual ~Item() {}

    double GetPrice() const { return price * quantity; }
    void SetPrice(double p) { price = p; }
    void SetQuantity(int q) { quantity = q; }

    virtual Item* Clone() const = 0;
};

class Book : public Item {
public:
    Book(const string& name, const string& serial) : Item(name, serial) {}
    Item* Clone() const override { return new Book(*this); }
};

class Food : public Item {
public:
    Food(const string& name, const string& serial) : Item(name, serial) {}
    Item* Clone() const override { return new Food(*this); }
};

class Invoice : public Payable {
    vector<Item*> items;

public:
    Invoice() {}

    Invoice(const Invoice& other) {
        for (auto item : other.items)
            items.push_back(item->Clone());
    }

    Invoice& operator=(const Invoice&) = delete;

    void AddNewItemToInvoice(Item* item) {
        items.push_back(item->Clone());
    }

    double GetAmountToPay() const override {
        double sum = 0;
        for (auto item : items)
            sum += item->GetPrice();
        return sum;
    }

    Object* Clone() const override {
        return new Invoice(*this);
    }

    string GetClassName() const override { return "Invoice"; }

    void Print(ostream& out) const override {
        out << "Invoice total: " << GetAmountToPay() << "\n";
    }

    bool operator<(Object& obj) const override {
        Invoice* o = dynamic_cast<Invoice*>(&obj);
        if (!o) return GetClassName() < obj.GetClassName();
        return GetAmountToPay() < o->GetAmountToPay();
    }

    ~Invoice() {
        for (auto item : items)
            delete item;
    }
};

// ===== Employees =====
class SalariedEmployee : public Payable {
    double salary;
    string name;

public:
    SalariedEmployee(const string& name, double salary) : name(name), salary(salary) {}

    double GetAmountToPay() const override { return salary; }

    Object* Clone() const override { return new SalariedEmployee(*this); }

    string GetClassName() const override { return "SalariedEmployee"; }

    void Print(ostream& out) const override {
        out << "Employee " << name << " has salary " << salary << "\n";
    }

    bool operator<(Object& obj) const override {
        if (GetClassName() != obj.GetClassName())
            return GetClassName() < obj.GetClassName();

        auto* other = dynamic_cast<SalariedEmployee*>(&obj);
        return other && salary < other->salary;
    }
};

class HourlyEmployee : public Payable {
    int hours;
    double rate;

public:
    HourlyEmployee(int h, double r) : hours(h), rate(r) {}

    double GetAmountToPay() const override { return hours * rate; }

    Object* Clone() const override { return new HourlyEmployee(*this); }

    string GetClassName() const override { return "HourlyEmployee"; }

    void Print(ostream& out) const override {
        out << "Hourly employee earned " << GetAmountToPay() << "\n";
    }

    bool operator<(Object& obj) const override {
        auto* other = dynamic_cast<HourlyEmployee*>(&obj);
        if (!other) return GetClassName() < obj.GetClassName();
        return GetAmountToPay() < other->GetAmountToPay();
    }
};

class Volunteer : public Payable {
    string name, location;

public:
    Volunteer(const string& n, const string& l) : name(n), location(l) {}

    double GetAmountToPay() const override { return 0; }

    Object* Clone() const override { return new Volunteer(*this); }

    string GetClassName() const override { return "Volunteer"; }

    void Print(ostream& out) const override {
        out << "Volunteer " << name << " at " << location << " earns nothing.\n";
    }

    bool operator<(Object& obj) const override {
        return GetClassName() < obj.GetClassName();  // Always ranks lowest
    }
};

// ===== Utility Functions =====
bool ComparePayables(Payable* a, Payable* b) {
    return *a < *b;
}

// ===== Payroll =====
class Payroll : public Printable {
    vector<Payable*> payables;

public:
    void AddPayable(const Payable& p) {
        payables.push_back(dynamic_cast<Payable*>(p.Clone()));
    }

    void SortPayables() {
        sort(payables.begin(), payables.end(), ComparePayables);
    }

    void Print(ostream& out) const override {
        double total = 0;
        for (auto p : payables) {
            out << *p;
            total += p->GetAmountToPay();
        }
        out << "Total Payroll: " << total << "\n";
    }

    string GetClassName() const override { return "Payroll"; }

    ~Payroll() {
        for (auto p : payables)
            delete p;
    }
};

// ===== Company Runner =====
class Company {
    Payroll payroll;

public:
    void Run() {
        payroll.AddPayable(SalariedEmployee("John", 3000));
        payroll.AddPayable(HourlyEmployee(40, 15));
        payroll.AddPayable(Volunteer("Ali", "123 Street"));

        Invoice inv;
        Book b("C++ Book", "B001");
        b.SetPrice(50);
        b.SetQuantity(2);
        inv.AddNewItemToInvoice(&b);

        Food f("Lunch", "F002");
        f.SetPrice(10);
        f.SetQuantity(5);
        inv.AddNewItemToInvoice(&f);

        payroll.AddPayable(inv);
        payroll.SortPayables();
        cout << payroll;
    }
};

// ===== Main =====
int main() {
    Company c;
    c.Run();
    return 0;
}
