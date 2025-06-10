#ifndef HOMEWORK_H
#define HOMEWORD_H

class Shape{
    //data members 
    //funtion members
    //perimiter 
    //size  
};

class TwoDimensionalShape : public Shape {
    ////more parameters 
};
class ThreeDimensionalShape : public Shape {};

class Circle : public TwoDimensionalShape {};
class Square : public TwoDimensionalShape  {};
class Triangle : public TwoDimensionalShape {};

//////////////
class Sphere : public ThreeDimensionalShape {};
class Cube : public ThreeDimensionalShape {};
class Tetrahedron : public ThreeDimensionalShape {};


#endif 