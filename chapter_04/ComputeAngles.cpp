// Listing 4.1 - ComputeAngles.cpp

#include <iostream>
#include <cmath>

int main()
{
    // Prompt the user to enter three points
    std::cout << "Enter three points: ";
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Compute three sides
    double a = std::sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double b = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double c = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    // Obtain three angles in radians
    double A = acos((a * a - b * b - c * c) / (-2 * b * c));
    double B = acos((b * b - a * a - c * c) / (-2 * a * c));
    double C = acos((c * c - b * b - a * a) / (-2 * b * a));

    // Display the angles in degrees
    const double PI = 3.14159;
    std::cout << "The three angles are " << A * 180 / PI << " "
              << B * 180 / PI << " " << C * 180 / PI << std::endl;

    return 0;
}