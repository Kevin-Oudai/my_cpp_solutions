#ifndef RECTANGLE
#define RECTANGLE

class Rectangle
{
public:
    Rectangle();
    Rectangle(double width, double height);
    double getHeight();
    double getWidth();
    void setHeight(double h);
    void setWidth(double w);
    double getArea();
    double getPerimeter();

private:
    double height;
    double width;
};

#endif