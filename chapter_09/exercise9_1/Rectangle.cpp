#include "Rectangle.h"

Rectangle::Rectangle()
{
    width = 1;
    height = 1;
}

Rectangle::Rectangle(double w, double h)
{
    width = w;
    height = h;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getWidth()
{
    return width;
}

void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
}

void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

double Rectangle::getArea()
{
    return height * width;
}

double Rectangle::getPerimeter()
{
    return 2 * (height + width);
}