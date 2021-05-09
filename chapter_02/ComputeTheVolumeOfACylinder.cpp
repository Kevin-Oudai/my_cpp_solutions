#include <iostream>

int main()
{
    double radius, length, area, volume;
    double pi = 3.141592654;
    std::cout << "Enter the radius and length of a cylinder: ";
    std::cin >> radius >> length;
    area = radius * radius * pi;
    volume = area * length;
    std::cout << "The area is " << area << std::endl;
    std::cout << "The volume is " << volume << std::endl;
    return 0;
}