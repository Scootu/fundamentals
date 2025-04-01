#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

int main(){
    Queue<int> Qint(5);
    Qint.enqueue(1);
    Qint.enqueue(2);
    Qint.enqueue(3);
    Qint.dequeue();
    cout << Qint.front()<<endl;;
    Qint.print();
    Queue<char> Qchar(2);
    Qchar.enqueue('u');
    Qchar.enqueue('i');
    Qchar.print();
    Queue<Employee> Qemployee(5);
    Employee emp1("hamdaoui",45,"senior architect",5);
    Employee emp2("dahmand",15,"full stack developer",5);
    Employee emp3("moloud",45,"software manager",8);
    Qemployee.enqueue(emp1);
    Qemployee.enqueue(emp2);
    Qemployee.enqueue(emp3);
    Qemployee.print();
    return 0;
}