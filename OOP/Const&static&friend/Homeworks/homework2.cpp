#include <bits/stdc++.h>
using namespace std;


class Employee {
private:
	string name;

public:
	Employee(string name) :
			name(name) {
		cout<<"Constructor: "<<name<<"\n";
	}
	~Employee() {
		cout<<"Destructor: "<<name<<"\n";
	}
};

int main() {
	static Employee belal("Belal");
	Employee most("Mostafa");
	if (true)
		Employee("Mona");
	static Employee Asmaa("Asmaa");

	return 0;
}
