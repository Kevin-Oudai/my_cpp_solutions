// Listing 10.4 - PassObjectByReference.cpp

#include <iostream>
#include "CircleWithPrivateDataFields.h"

void printCircle(Circle &c)
{
    std::cout << "The area of the circle of " << c.getRadius() << " is " << c.getArea() << std::endl;
}

int main()
{
    Circle myCircle(5.0);
    printCircle(myCircle);

    return 0;
}