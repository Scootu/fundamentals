#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Color
{
};
class Shape
{
protected:
    Color color;

public:
    virtual double ComputeArea() = 0;
    virtual void Draw() = 0;
};

class ImageEditor
{
protected:
    vector<Shape *> shapes;

public:
    void AddNewShape(Shape *shape)
    {
        shapes.push_back(shape); //Need Clone ?
    }
    virtual void Draw()
    {
        for (auto shape : shapes)
        {
            shape->Draw();
            cout << "\n";
        }
    };
};

class AdobePhotoshop : public ImageEditor
{
public:
    void Draw() ;
    void EnlargeShapes(double percent);
};

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
  string ToString() {
    ostringstream oss;
    oss << x << " " << y;
    return oss.str();
}
};

class Rectangle : public Shape
{
private:
    Point top_left;
    Point right_bottom;

public:
    double ComputeArea() {return 0;};
    void Draw()
    {
        cout << top_left.ToString() << " " << right_bottom.ToString() << "\n";
    };
};

class Circle : public Shape
{
private:
    double *radius;
    int *center;

public:
    double ComputeArea() {return 0;};
    void Draw()
    {
        cout << *radius << " " << *center << "\n";
    };
};

int main()
{
    Rectangle *rec = new Rectangle();
    Circle *circle = new Circle();

    ImageEditor imageEditor; // need to be a pointer ?
    imageEditor.AddNewShape(rec);
    imageEditor.AddNewShape(circle);
    imageEditor.Draw();
    return 0;
}