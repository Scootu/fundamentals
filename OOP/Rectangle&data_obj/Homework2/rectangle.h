#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include <stdexcept>

using std::invalid_argument;

struct Rectangle
{
    private:
    float width_;
    float length_;

    //validate 
    void validateRectangle(){
        if(width_ <= 0 || length_ <=0 )  throw invalid_argument( "received negative value" );
    }
    public:
    //Default Rectangle 
    Rectangle():width_(1),length_(1){}
    //Parameter Rectangle
    Rectangle(int w,int l);
    //gettter 
    float getArea();
    float getDiagonel();
    float getPerimeter();
    //Setter 
    void setWidth(float length);
    void setLenght(float width);
};

#endif // RECTANGLE_H_INCLUDED