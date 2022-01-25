#include <iostream>

const int SIZE = 2;
bool sameLine(const double points[][SIZE], int numberOfPoints)
{
    double state;
    for (int i = 2; i < numberOfPoints; i++)
    {
        state = (points[1][0] - points[0][0]) * (points[i][1] - points[0][1]) - (points[i][0] - points[0][0]) * (points[1][1] - points[0][1]);
        if (state != 0)
            return false;
    }
    return true;
}

int main()
{
    double points[5][2] = {};
    std::cout << "Enter five points: ";
    for (int i = 0; i < 5; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }
    if (sameLine(points, 5))
    {
        std::cout << "The five points are on the same line" << std::endl;
    }
    else
    {
        std::cout << "The five points are not on the same line" << std::endl;
    }
    return 0;
}