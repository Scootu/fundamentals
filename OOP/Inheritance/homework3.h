#ifndef HOMEWORK_3
#define HOMEWORK_3

/*
Design Review of the Car Inheritance Hierachy 
The main issue with this desing is that it uses inheritance incorrectly by modeling a "has-a" relationship (composition) using an "is-a" relationship (inheritance)

Problems with the Current Design 
1.Inheritance Misuse : 
A Car Has an Engine, but a Car is not an Engine 
A.Car has FourWheels, but a Car is not FourWheels 
2.Violation of Liskov substitution Principle:
You wouldn't expect a Car to be substitutable for an Engine or Fourwheels in all contexts 


Recommended Solution 
*/

class Engine {};
class FourWheels {};

class Car {
    private:
    Engine engine;
    FourWheels wheels;

    public:
    //Car functionality
};

/*
Tip for the Enginner: 
Remember that inheritance should model "is-a" relationships, while compositoin models 'has-a' relationships, A car has an engine and has wheels, but isn't an engine or wheels 
itself.Consider refactoring to use composition instead of inheritance for these relationships.
*/

#endif 