//
// Created by anesHamdaoui on 11/14/2024.
//
#include "rectangle.h"

int main() {
    Rectangle r1, r2, r3;

    r1.set_width(10);
    r1.set_length(10);
    r2.set_width(10);
    r2.set_length(10);
    r3.set_width(10);
    r3.set_length(10);
    r1.display();
    r2.display();
    r3.display();

    return 0;
}

Rectangle::Rectangle() : width(1), length(1) {}
Rectangle::Rectangle(int w, int l) : width(w), length(l) {}

inline int Rectangle::get_length() {
    return length;
}
inline int Rectangle::get_width() {
    return width;
}
inline void Rectangle::set_length(int l) {
    length = l;
}
inline void Rectangle::set_width(int w) {
    width = w;
}
inline float Rectangle::calculate_area() {
    return width * length;
}
inline float Rectangle::calculate_perimeter() {
    return 2 * (width + length);
}
inline void Rectangle::display() {
    std::cout << "Width: " << width << ", Length: " << length 
              << ", Area: " << calculate_area() 
              << ", Perimeter: " << calculate_perimeter() << "\n";
}
