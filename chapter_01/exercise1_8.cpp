#include <iostream>

int main()
{
    double radius = 5.5;
    double pi = 3.141592654;
    double perimeter = 2 * radius * pi;
    double area = radius * radius * pi;
    std::cout << "The perimeter is: " << perimeter << std::endl;
    std::cout << "The area is: " << area << std::endl;
    return 0;
}