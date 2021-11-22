// Listing 10.3 - PassObjectByValue.cpp

#include <iostream>

// CircleWithPrivateDataFields.h is defined in Listing 9.9
#include "CircleWithPrivateDataFields.h"

void printCircle(Circle c)
{
    std::cout << "The area of the circle of " << c.getRadius() << " is " << c.getArea() << std::endl;
}

int main()
{
    Circle myCircle(5.0);
    printCircle(myCircle);

    return 0;
}