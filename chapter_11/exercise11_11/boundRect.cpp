#include <iostream>
#include "Rectangle2D.h"

const int SIZE = 2;
Rectangle2D getRectangle(const double points[][SIZE])
{
    double averageX = 0;
    double averageY = 0;
    for (int i = 0; i < 5; i++)
    {
        averageX += points[i][0];
        averageY += points[i][1];
    }
    averageX /= 5;
    averageY /= 5;
    double maxX = 0;
    double maxY = 0;
    for (int i = 0; i < 5; i++)
    {
        if (maxX < averageX - points[i][0])
        {
            maxX = averageX - points[i][0];
        }
        if (maxY < averageY - points[i][1])
        {
            maxY = averageY - points[i][1];
        }
    }
    maxX *= 2;
    maxY *= 2;
    Rectangle2D r(averageX, averageY, maxX, maxY);
    return r;
}

int main()
{
    double points[5][SIZE];
    std::cout << "Enter five points: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }
    Rectangle2D rect = getRectangle(points);
    std::cout << "The bounding rectangle's center (" << rect.getX() << ", " << rect.getY() << "), width "
              << rect.getWidth() << ", height " << rect.getHeight() << std::endl;
    return 0;
}