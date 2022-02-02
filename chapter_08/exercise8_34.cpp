#include <iostream>

const int SIZE = 2;

void getRightmostLowestPoint(const double points[][SIZE], int numberOfPoints, double rightMostPoint[])
{
    double rightMost = points[0][0];
    double lowest = points[0][1];
    for (int i = 1; i < numberOfPoints; i++)
    {
        if (rightMost <= points[i][0] && lowest >= points[i][1])
        {
            rightMost = points[i][0];
            lowest = points[i][1];
        }
        else if (rightMost == points[i][0] && lowest > points[i][1])
        {
            rightMost = points[i][0];
            lowest = points[i][1];
        }
        else
        {
            continue;
        }
    }
    rightMostPoint[0] = rightMost;
    rightMostPoint[1] = lowest;
}

int main()
{
    std::cout << "Enter 6 points: ";
    double points[6][SIZE] = {}, result[2] = {};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            std::cin >> points[i][j];
        }
    }
    getRightmostLowestPoint(points, 6, result);
    std::cout << "The rightmost lowest point is (" << result[0] << ", " << result[1] << ")." << std::endl;

    return 0;
}