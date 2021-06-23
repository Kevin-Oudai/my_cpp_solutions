// Listing 6.8

#include <iostream>

void printArea(double radius = 1)
{
    double area = radius * radius * 3.14159;
    std::cout << "area is " << area << std::endl;
}

int main()
{
    printArea();
    printArea(4);

    return 0;
}