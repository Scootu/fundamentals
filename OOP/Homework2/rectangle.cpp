

#include "rectangle.h"
#include <math.h>

Rectangle::Rectangle(int w,int l):width_(w),length_(l){}
//Getter 
float Rectangle::getArea(){
    return width_*length_;
}
float Rectangle::getDiagonel(){
    return sqrt(width_*width_+length_*length_);
}
float Rectangle::getPerimeter(){
    return 2*(width_*length_);
}
//Setter 

void Rectangle::setLenght(float length){
      length_ = length;
}

void Rectangle::setWidth(float width){
    width_ = width;
}