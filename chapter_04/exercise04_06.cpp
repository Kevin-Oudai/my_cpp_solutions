#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

int main()
{
    const double PI = 3.14159;
    double angle1, angle2, angle3, x1, y1, x2, y2, x3, y3;

    srand(time(0));
    angle1 = (rand() % 360) * PI / 180;
    angle2 = (rand() % 360) * PI / 180;
    angle3 = (rand() % 360) * PI / 180;

    x1 = 40 * cos(angle1);
    y1 = 40 * sin(angle1);

    x2 = 40 * cos(angle2);
    y2 = 40 * sin(angle2);

    x3 = 40 * cos(angle3);
    y3 = 40 * sin(angle3);

    std::cout << "The three points are (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2
              << ") and (" << x3 << ", " << y3 << ")." << std::endl;

    double a = std::sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    double b = std::sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    double c = std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    double A = acos((a * a - b * b - c * c) / (-2 * b * c));
    double B = acos((b * b - a * a - c * c) / (-2 * a * c));
    double C = acos((c * c - b * b - a * a) / (-2 * b * a));

    std::cout << std::setprecision(1) << std::showpoint << std::fixed;
    std::cout << "The three angles formed in the triangle are " << A * 180 / PI << ", "
              << B * 180 / PI << " and " << C * 180 / PI << " degrees." << std::endl;
    return 0;
}