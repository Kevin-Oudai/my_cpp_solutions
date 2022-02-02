// Listing 9.11 - TestCircleWithPrivateDataFields.cpp

#include <iostream>
#include "CircleWithPrivateDataFields.h"

int main()
{
    Circle circle1;
    Circle circle2(5.0);

    std::cout << "The area of the circle of radius " << circle1.getRadius() << " is "
              << circle1.getArea() << std::endl;

    std::cout << "The area of the circle of radius " << circle2.getRadius() << " is "
              << circle2.getArea() << std::endl;

    // Modify circle radius
    circle2.setRadius(100);
    std::cout << "The area of the circle of radius " << circle2.getRadius() << " is "
              << circle2.getArea() << std::endl;

    return 0;
}