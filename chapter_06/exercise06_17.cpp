// Exercise 6.17 - Equilateral Triangle Validation and Perimeter

#include <iostream>

bool isValid(double side1, double side2, double side3)
{
    if (side1 == side2 && side2 == side3)
    {
        return true;
    }
    return false;
}

double perimeter(double side1)
{
    return side1 * 3;
}

int main()
{
    std::cout << "Enter the length of the side for a triangle: ";
    double side1, side2, side3, perim;
    std::cin >> side1 >> side2 >> side3;

    if (isValid(side1, side2, side3))
    {
        perim = perimeter(side1);
        std::cout << "The perimeter is: " << perim << std::endl;
    }
    else
    {
        std::cout << "The inputs are invalid" << std::endl;
    }

    return 0;
}