#include <iostream>
#include "LinearEquation.h"

int main()
{
    double a, b, c, d, e, f;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a = y1 - y2;
    b = x2 - x1;
    e = x2 * y1 - x1 * y2;
    c = y3 - y4;
    d = x4 - x3;
    f = x4 * y3 - x3 * y4;
    LinearEquation l(a, b, c, d, e, f);

    if (l.isSolvable())
    {
        std::cout << "The intersecting point is at (" << l.getX() << ", " << l.getY()
                  << ")" << std::endl;
    }
    else
    {
        std::cout << "The two lines are parallel" << std::endl;
    }
}
