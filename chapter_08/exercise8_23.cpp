#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2)
{
    double dis = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    return dis;
}

void calculateDistances(double distances[][20], double points[][2], int rows)
{
    double x1, y1, x2, y2;
    for (int i = 0; i < rows; i++)
    {
        x1 = points[i][0];
        y1 = points[i][1];
        for (int j = 0; j < rows; j++)
        {
            x2 = points[j][0];
            y2 = points[j][1];
            distances[i][j] = distance(x1, y1, x2, y2);
        }
    }
}

void findCentre(double distances[][20], double points[][2], double result[], int rows)
{
    int smallestIndex = 0;
    double smallestValue = 0;
    for (int i = 0; i < rows; i++)
    {
        smallestValue += distances[smallestIndex][i];
    }

    double total = 0;
    for (int i = 1; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            total += distances[i][j];
        }
        if (total < smallestValue)
        {
            smallestIndex = i;
            smallestValue = total;
        }
    }
    result[0] = points[smallestIndex][0];
    result[1] = points[smallestIndex][1];
    result[2] = smallestValue;
}

int main()
{
    double points[20][2] = {};
    double distances[20][20] = {};
    double result[3] = {};
    int rows;
    std::cout << "Enter the number of cities: ";
    std::cin >> rows;
    std::cout << "Enter the coordinates of the " << rows << " cities: ";
    for (int i = 0; i < rows; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }
    calculateDistances(distances, points, rows);
    findCentre(distances, points, result, rows);
    std::cout << "The central city is at (" << result[0] << ", " << result[1] << ")." << std::endl;
    std::cout << "The total distance to all other cities is " << result[2] << "." << std::endl;
    return 0;
}