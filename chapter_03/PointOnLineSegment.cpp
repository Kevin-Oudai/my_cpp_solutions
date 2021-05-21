#include <iostream>

int main()
{
    double x0, x1, x2, y0, y1, y2;
    std::cout << "Enter three points for p0, p1, and p2: ";
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    double state = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);

    if (state == 0 && x1 >= x2 && x0 <= x2)
        std::cout << "(" << x2 << ", " << y2 << ") is on the line segment from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << "). " << std::endl;
    else
        std::cout << "(" << x2 << ", " << y2 << ") is not on the line segment from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << "). " << std::endl;

    return 0;
}