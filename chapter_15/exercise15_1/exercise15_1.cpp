#include <iostream>
#include "Triangle.h"

int main()
{
    double side1;
    double side2;
    double side3;
    std::string color;
    int filledInput;

    std::cout << "Enter three sides of the triangle: ";
    std::cin >> side1 >> side2 >> side3;

    std::cout << "Enter a color: ";
    std::cin >> color;

    std::cout << "Enter 1 if the triangle is filled, 0 otherwise: ";
    std::cin >> filledInput;

    Triangle triangle(side1, side2, side3, color, filledInput == 1);

    std::cout << "Area: " << triangle.getArea() << std::endl;
    std::cout << "Perimeter: " << triangle.getPerimeter() << std::endl;
    std::cout << "Color: " << triangle.getColor() << std::endl;
    std::cout << "Filled: " << (triangle.isFilled() ? "true" : "false") << std::endl;

    return 0;
}
