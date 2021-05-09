#include <iostream>

int main()
{
    double width = 4.5;
    double height = 7.9;
    double area = width * height;
    double perimeter = 2 * (width + height);
    std::cout << "The area of the rectangle is: " << area << std::endl;
    std::cout << "The perimeter of the rectangle is: " << perimeter << std::endl;
    return 0;
}