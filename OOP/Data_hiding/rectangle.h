//
// Created by anesHamdaoui on 11/14/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <iostream>

class Rectangle {
    int width, length;
public:
    Rectangle();
    Rectangle(int w, int l);
    int get_width();
    int get_length();
    void set_width(int w);
    void set_length(int l);
    void display();
    float calculate_area();
    float calculate_perimeter();
};


#endif //RECTANGLE_H
