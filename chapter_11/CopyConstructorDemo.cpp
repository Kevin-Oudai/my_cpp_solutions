#include <iostream>
#include "CircleWithDestructor.h" // Defined in Listing 11.11

int main()
{
    Circle circle1(5);
    Circle circle2(circle1); // Use copy constructor

    std::cout << "After creating circle2 from cricle1: " << std::endl;
    std::cout << "\tcircle1.getRadius() returns " << circle1.getRadius() << std::endl;
    std::cout << "\tcircle2.getRadius() returns " << circle2.getRadius() << std::endl;

    circle1.setRadius(10.5);
    circle2.setRadius(20.5);
    std::cout << "After modifying circle1 and circle2: " << std::endl;
    std::cout << "\tcircle1.getRadius() returns " << circle1.getRadius() << std::endl;
    std::cout << "\tcircle2.getRadius() returns " << circle2.getRadius() << std::endl;

    return 0;
}