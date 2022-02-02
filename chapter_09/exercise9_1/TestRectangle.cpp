#include <iostream>
#include "Rectangle.h"

void displayRectangle(Rectangle rect)
{
    std::cout << "The rectangle with width "
              << rect.getWidth() << " and height "
              << rect.getHeight() << " has an area of "
              << rect.getArea() << " square units and the perimeter is "
              << rect.getPerimeter() << " units." << std::endl;
}

int main()
{
    Rectangle rect1(4, 40);
    Rectangle rect2(3.5, 35.9);
    displayRectangle(rect1);
    displayRectangle(rect2);
    return 0;
}