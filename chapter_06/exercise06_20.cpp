// Exercise 6.20 - Geometry: point position

#include <iostream>

bool leftOfTheLine(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double state = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (state > 0)
        return true;
    return false;
}

bool onTheSameLine(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double state = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (state == 0)
        return true;
    return false;
}
// Did not need this function but I choose to leave it.
// bool rightOfTheLine(double x0, double y0, double x1, double y1, double x2, double y2)
// {
//     double state = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
//     if (state < 0)
//         return true;
//     return false;
// }

bool onTheLineSegment(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double state = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (state == 0 && x2 > x0 && x2 < x1)
        return true;
    return false;
}

int main()
{
    std::cout << "Enter three points for p0, p1 and p2: ";
    double x0, y0, x1, y1, x2, y2;
    std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

    if (onTheLineSegment(x0, y0, x1, y1, x2, y2))
    {
        std::cout << "(" << x2 << ", " << y2 << ") is on the line segment from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ")" << std::endl;
    }
    else if (onTheSameLine(x0, y0, x1, y1, x2, y2))
    {
        std::cout << "(" << x2 << ", " << y2 << ") is on the same line from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ")" << std::endl;
    }
    else if (leftOfTheLine(x0, y0, x1, y1, x2, y2))
    {
        std::cout << "(" << x2 << ", " << y2 << ") is on the left of the line from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ")" << std::endl;
    }
    else
    {
        std::cout << "(" << x2 << ", " << y2 << ") is on the right of the line from ("
                  << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ")" << std::endl;
    }
    return 0;
}