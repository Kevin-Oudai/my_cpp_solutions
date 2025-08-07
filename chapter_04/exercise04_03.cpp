// Listing 4.1 - ComputeAngles.cpp

#include <iostream>
#include <cmath>

int main()
{
    // Prompt the user to enter three points
    std::cout << "Enter three points: ";
    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    std::cout << "Enter three points: ";
    double x4, y4, x5, y5, x6, y6;
    std::cin >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    // Compute three sides
    double a = std::sqrt((x5 - x6) * (x5 - x6) + (y5 - y6) * (y5 - y6));
    double b = std::sqrt((x4 - x6) * (x4 - x6) + (y4 - y6) * (y4 - y6));
    double c = std::sqrt((x4 - x5) * (x4 - x5) + (y4 - y5) * (y4 - y5));

    double d = std::sqrt((x5 - x6) * (x5 - x6) + (y5 - y6) * (y5 - y6));
    double e = std::sqrt((x4 - x6) * (x4 - x6) + (y4 - y6) * (y4 - y6));
    double f = std::sqrt((x4 - x5) * (x4 - x5) + (y4 - y5) * (y4 - y5));

    // Obtain three angles in radians
    double A = acos((a * a - b * b - c * c) / (-2 * b * c));
    double B = acos((b * b - a * a - c * c) / (-2 * a * c));
    double C = acos((c * c - b * b - a * a) / (-2 * b * a));

    double D = acos((d * d - e * e - f * f) / (-2 * e * f));
    double E = acos((e * e - d * d - f * f) / (-2 * d * f));
    double F = acos((f * f - e * e - d * d) / (-2 * e * d));

    // Display the angles in degrees
    const double PI = 3.14159;
    std::cout << "The three angles are " << A * 180 / PI << " "
              << B * 180 / PI << " " << C * 180 / PI << std::endl;

    std::cout << "The three angles are " << D * 180 / PI << " "
              << E * 180 / PI << " " << F * 180 / PI << std::endl;

    if (A == D || A == E || A == F)
    {
        if (B == D || B == E || B == F)
            if (C == D || C == E || C == F)
            {
                std::cout << "The angles in both triangles are the same." << std::endl;
            }
    }
    else
    {
        std::cout << "The angles are not the same." << std::endl;
    }

    return 0;
}