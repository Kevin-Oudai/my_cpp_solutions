#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

int main()
{
    const double PI = 3.14159;
    double radius;
    double angle1, angle2, angle3, angle4, angle5, x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;

    std::cout << "Enter the radius of the bounding circle: ";
    std::cin >> radius;

    srand(time(0));
    angle1 = 18 * PI / 180;
    angle2 = 90 * PI / 180;
    angle3 = 162 * PI / 180;
    angle4 = 234 * PI / 180;
    angle5 = 306 * PI / 180;

    x1 = radius * cos(angle1);
    y1 = radius * sin(angle1);

    x2 = radius * cos(angle2);
    y2 = radius * sin(angle2);

    x3 = radius * cos(angle3);
    y3 = radius * sin(angle3);

    x4 = radius * cos(angle4);
    y4 = radius * sin(angle4);

    x5 = radius * cos(angle5);
    y5 = radius * sin(angle5);

    std::cout << "The coordinates of five points on the pentagon are\n("
              << x1 << ", " << y1 << ")\n("
              << x2 << ", " << y2 << ")\n("
              << x3 << ", " << y3 << ")\n("
              << x4 << ", " << y4 << ")\n("
              << x5 << ", " << y5 << ")" << std::endl;

    return 0;
}