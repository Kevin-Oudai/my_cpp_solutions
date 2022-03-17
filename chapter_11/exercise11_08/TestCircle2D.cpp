#include <iostream>
#include "Circle2D.h"

int main()
{
    Circle2D c1(2, 2, 5.5);
    Circle2D c2(2, 2, 5.4);
    Circle2D c3(4, 5, 5);

    std::cout << "Area of c1: " << c1.getArea() << std::endl;
    std::cout << "Perimeter of c1: " << c1.getPerimeter() << std::endl;
    (c1.contains(3, 3)) ? std::cout << "c1 contains (3, 3)" << std::endl
                        : std::cout << "c1 does not contain (3, 3)" << std::endl;
    (c1.contains(c2)) ? std::cout << "c1 contains c2" << std::endl : std::cout << "c1 does not contain c2" << std::endl;
    (c1.overlaps(c3)) ? std::cout << "c1 overlaps c3" << std::endl : std::cout << "c1 does not overlap c3" << std::endl;

    return 0;
}