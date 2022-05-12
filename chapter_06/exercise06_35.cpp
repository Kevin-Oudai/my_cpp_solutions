// Exercise 6.35 - Geometry: intersection

#include <iostream>
#include <iomanip>

void intersectPoint(double x1, double y1, double x2, double y2,
                    double x3, double y3, double x4, double y4,
                    double &x, double &y, bool &isIntersecting);
void solveEquation(double a, double b, double c, double d, double e, double f, double &x, double &y, bool &isSolvable, int D);

void intersectPoint(double x1, double y1, double x2, double y2,
                    double x3, double y3, double x4, double y4,
                    double &x, double &y, bool &isIntersecting)
{
    double a = y1 - y2;
    double b = x2 - x1;
    double e = x2 * y1 - x1 * y2;
    double c = y3 - y4;
    double d = x4 - x3;
    double f = x4 * y3 - x3 * y4;
    double D = a * d - b * c;
    isIntersecting = D == 0 ? false : true;
    solveEquation(a, b, c, d, e, f, x, y, isIntersecting, D);
}

void solveEquation(double a, double b, double c, double d, double e, double f, double &x, double &y, bool &isSolvable, int D)
{
    if (!isSolvable)
    {
        std::cout << "The two lines do not cross" << std::endl;
    }
    else
    {
        x = (e * d - b * f) / D;
        y = (a * f - e * c) / D;
        std::cout << std::setprecision(1) << std::showpoint << std::fixed;
        std::cout << "The intersecting point is: (" << x << ", " << y << ")" << std::endl;
    }
}

int main()
{
    std::cout << "Enter the endpoints of the first line segment: ";
    double x1, y1, x2, y2, x3, y3, x4, y4, x, y;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << "Enter the endpoints of the first line segment: ";
    std::cin >> x3 >> y3 >> x4 >> y4;
    bool isIntersecting;
    intersectPoint(x1, y1, x2, y2, x3, y3, x4, y4, x, y, isIntersecting);
    return 0;
}
