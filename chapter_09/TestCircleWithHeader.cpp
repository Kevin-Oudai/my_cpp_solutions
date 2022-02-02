// Listing 9.5 - TestCircleWithHeader.cpp

#include <iostream>
#include "Circle.h"

int main()
{
    Circle circle1;
    Circle circle2(5.0);

    std::cout << "The area of the circle of radius " << circle1.radius
              << " is " << circle1.getArea() << std::endl;

    std::cout << "The area of the circle of radius " << circle2.radius
              << " is " << circle2.getArea() << std::endl;

    // Modify circle radius
    circle2.radius = 100;

    std::cout << "The area of the circle of radius " << circle2.radius
              << " is " << circle2.getArea() << std::endl;

    return 0;
}