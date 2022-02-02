// The sample run of this code had incorrect results. I plotted these points and manually worked it out.
// If you got the same answer as the sample run please let me know.
#include <iostream>
#include <cmath>

const int SIZE = 2;
void sortResult(double areas[])
{
    double memory;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (areas[i] > areas[j])
            {
                memory = areas[j];
                areas[j] = areas[i];
                areas[i] = memory;
            }
        }
    }
}
// find intersecting points
bool getIntersectingPoint(const double points[][SIZE], double result[])
{
    double a, b, c, d, e, f, x, y, D;
    double x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = points[0][0];
    y1 = points[0][1];
    x2 = points[2][0];
    y2 = points[2][1];
    x3 = points[1][0];
    y3 = points[1][1];
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

// calculate area of triangle
double getTriangleArea(const double points[][SIZE])
{
    double x1, y1, x2, y2, x3, y3, side1, side2, side3, area, s;
    x1 = points[0][0];
    y1 = points[0][1];
    x2 = points[1][0];
    y2 = points[1][1];
    x3 = points[2][0];
    y3 = points[2][1];

    side1 = pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
    side2 = pow(pow(x2 - x3, 2) + pow(y2 - y3, 2), 0.5);
    side3 = pow(pow(x3 - x1, 2) + pow(y3 - y1, 2), 0.5);

    s = (side1 + side2 + side3) / 2;

    area = pow(s * (s - side1) * (s - side2) * (s - side3), 0.5);
    return area;
}
// calculate the areas of each triangle and store it in an array
void getAreas(const double points[][SIZE], double result[], double areas[])
{
    double trianglePoints[3][2];
    double area;
    int areaCount = 0;
    trianglePoints[0][0] = result[0];
    trianglePoints[0][1] = result[1];
    for (int i = 0; i < 4; i++)
    {
        trianglePoints[1][0] = points[i][0];
        trianglePoints[1][1] = points[i][1];
        for (int j = i + 1; j < 4; j++)
        {
            trianglePoints[2][0] = points[j][0];
            trianglePoints[2][1] = points[j][1];
            area = getTriangleArea(trianglePoints);
            if (area == 0)
            {
                continue;
            }
            else
            {
                areas[areaCount++] = area;
            }
        }
    }
    sortResult(areas);
}
// sort the array

int main()
{
    double points[4][SIZE] = {}, result[SIZE] = {}, areas[4] = {};
    std::cout << "Enter x1, y1, x2, y2, x3, y3, x4, y4: ";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> points[i][j];
        }
    }

    if (getIntersectingPoint(points, result))
    {
        getAreas(points, result, areas);
        std::cout << "The areas are ";
        for (int i = 0; i < 4; i++)
        {
            std::cout << areas[i] << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "There is no point of intersection" << std::endl;
    }
    return 0;
}
