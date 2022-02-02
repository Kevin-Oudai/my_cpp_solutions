// Listing 8.3 - FindNearestPoints.cpp
#include <iostream>
#include <cmath>

// Compute the distance between two points (x1, y1) and (x2, y2)
double getDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main()
{
    int number_of_points;
    std::cout << "Enter the number of points: ";
    std::cin >> number_of_points;
    // Each row in points represents a point
    double points[100][2];

    std::cout << "Enter " << number_of_points << " points: ";
    for (int i = 0; i < number_of_points; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
        std::cout << "(" << points[i][0] << ", " << points[i][1] << ")" << std::endl;
    }

    // p1 and p2 are the indices in the points array
    int p1 = 0, p2 = 1;                                                                                // Initial two points
    double shortestDistance = getDistance(points[p1][0], points[p1][1], points[p2][0], points[p2][1]); // Initialize shortestDistance

    // Compute distance for every two points
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = i + 1; j < number_of_points; j++)
        {
            double distance = getDistance(points[i][0], points[i][1], points[j][0], points[j][1]); // Find distance
            if (shortestDistance > distance)
            {
                p1 = i;                      // update p1
                p2 = j;                      // update p2
                shortestDistance = distance; // Update shortestDistance
            }
        }
    }

    // Display result
    for (int i = 0; i < number_of_points; i++)
    {
        for (int j = i + 1; j < number_of_points; j++)
        {
            double distance = getDistance(points[i][0], points[i][1], points[j][0], points[j][1]);
            if (distance == shortestDistance)
            {
                std::cout << "The closest two points are "
                          << "("
                          << points[i][0] << ", " << points[i][1]
                          << ") and (" << points[j][0] << ", "
                          << points[j][1] << ")" << std::endl;
            }
        }
    }
    std::cout << "Their distance is " << shortestDistance << std::endl;

    return 0;
}