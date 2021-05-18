#include <iostream>
#include <iomanip>

int main()
{
    double a, b, c, d, e, f, x, y, D;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a = y1 - y2;
    b = x2 - x1;
    e = x2 * y1 - x1 * y2;
    c = y3 - y4;
    d = x4 - x3;
    f = x4 * y3 - x3 * y4;

    D = a * d - b * c;
    if (D == 0)
    {
        std::cout << "The two lines are parallel" << std::endl;
    }
    else
    {
        x = (e * d - b * f) / D;
        y = (a * f - e * c) / D;
        std::cout << "The intersecting point is at (" << x << ", " << y
                  << ")" << std::endl;
    }

    return 0;
}