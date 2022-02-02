// Listing 10.8 - TestCircleWithStaticDataFields.cpp

#include <iostream>
#include "CircleWithStaticDataFields.h"

int main()
{
    std::cout << "Number of circle objects created: "
              << Circle::getNumberOfObjects() << std::endl;

    Circle circle1;
    std::cout << "The area of the circle of radius "
              << circle1.getRadius() << " is " << circle1.getArea() << std::endl;

    std::cout << "Number of circle objects created: "
              << Circle::getNumberOfObjects() << std::endl;

    Circle circle2(5.0);
    std::cout << "The area of the circle of radius "
              << circle2.getRadius() << " is " << circle2.getArea() << std::endl;
    std::cout << "Number of circle objects created: "
              << Circle::getNumberOfObjects() << std::endl;

    circle1.setRadius(3.3);
    std::cout << "The area of the circle of radius "
              << circle1.getRadius() << " is " << circle1.getArea() << std::endl;

    std::cout << "circle1.getNumberOfObjects() returns "
              << circle1.getNumberOfObjects() << std::endl;

    std::cout << "circle2.getNumberOfObjects() returns "
              << circle2.getNumberOfObjects() << std::endl;

    return 0;
}