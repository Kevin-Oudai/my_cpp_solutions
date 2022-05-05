#include <iostream>
#include <cmath>

int main()
{
    double s1, s2, s3, area;
    std::cout << "Enter the sides of a triangle: ";
    std::cin >> s1 >> s2 >> s3;

    if (s1 == s2 && s2 == s3)
    {
        area = pow(3, 0.5) * pow(s1, 2) / 4.0;
        std::cout << "The area of the equilateral triangle is " << area << " units squared." << std::endl;
    }
    else
        std::cout << "The input is invalid." << std::endl;

    return 0;
}