#include <iostream>

int main()
{
    double x1, y1, x2, y2, slope;
    std::cout << "Enter the coordinates for two points: ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    slope = (y2 - y1) / (x2 - x1);
    std::cout << "The slope for the line that connects two points (" << x1
              << ", " << y1 << ") and (" << x2 << ", " << y2 << ") is "
              << slope << std::endl;
    return 0;
}