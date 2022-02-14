#include <iostream>
#include "RegularPolygon.h"

int main()
{
    RegularPolygon a;
    RegularPolygon b(6, 4);
    RegularPolygon c(10, 4, 5.6, 7.8);

    std::cout << "Perimeter of a: " << a.getPerimeter() << std::endl;
    std::cout << "Perimeter of b: " << b.getPerimeter() << std::endl;
    std::cout << "Perimeter of c: " << c.getPerimeter() << std::endl;

    std::cout << "Area of a: " << a.getArea() << std::endl;
    std::cout << "Area of b: " << b.getArea() << std::endl;
    std::cout << "Area of c: " << c.getArea() << std::endl;
    return 0;
}