#include <iostream>

const int SIZE = 2;

bool getIntersectingPoint(const double points[][SIZE], double result[])
{
    double a, b, c, d, e, f, x, y, D;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = points[0][0];
    y1 = points[0][1];
    x2 = points[1][0];
    y2 = points[1][1];
    x3 = points[2][0];
    y3 = points[2][1];
    x4 = points[3][0];
    y4 = points[3][1];

    a = y1 - y2;
    b = x2 - x1;
    e = x2 * y1 - x1 * y2;
    c = y3 - y4;
    d = x4 - x3;
    f = x4 * y3 - x3 * y4;

    D = a * d - b * c;

    if (D == 0)
    {
        return false;
    }
    else
    {
        result[0] = (e * d - b * f) / D;
        result[1] = (a * f - e * c) / D;
        return true;
    }
}

int main()
{
    double points[4][2] = {}, result[2] = {};
    std::cout << "Enter 4 points: ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> points[i][j];
        }
    }
    bool hasPoint = getIntersectingPoint(points, result);
    if (hasPoint)
    {
        std::cout << "The intersecting point is (" << result[0] << ", " << result[1] << ")." << std::endl;
    }
    else
    {
        std::cout << "There is no intersecting point." << std::endl;
    }

    return 0;
}