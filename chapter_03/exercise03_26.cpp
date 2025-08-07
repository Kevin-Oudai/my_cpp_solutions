#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double x1, x2, y1, y2, r1, r2, distance;

    std::cout << "Enter circle1's center x-, y-coordinates, and radius: ";
    std::cin >> x1 >> y1 >> r1;
    std::cout << "Enter circle2's center x-, y-coordinates, and radius: ";
    std::cin >> x2 >> y2 >> r2;
    distance = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);

    bool inside = distance <= abs(r1 - r2);
    bool overlap = distance <= abs(r1 + r2);

    if (inside)
        std::cout << "circle2 is inside circle1" << std::endl;
    else if (overlap)
        std::cout << "circle2 overlaps circle1" << std::endl;
    else
        std::cout << "circle2 does not overlap circle1" << std::endl;
    return 0;
}