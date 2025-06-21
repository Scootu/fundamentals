#include <iostream>
using namespace std;

class Worker {
    protected:
    string username;
    public:
        
};

class volunteers : public Worker {};
class employees: public Worker {
    private:
    bool isHourlyBased = false;
    public:
    employees(const bool& ishourlyBased):isHourlyBased(ishourlyBased) {}
    
    
};

