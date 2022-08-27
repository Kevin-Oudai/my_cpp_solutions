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
    const int NUMBER_OF_POINTS = 8;

    // Each row in points represents a point
    double points[NUMBER_OF_POINTS][2];

    std::cout << "Enter " << NUMBER_OF_POINTS << " points: ";
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        std::cin >> points[i][0] >> points[i][1];
    }

    // p1 and p2 are the indices in the points array
    int p1 = 0, p2 = 1;                                                                                // Initial two points
    double shortestDistance = getDistance(points[p1][0], points[p1][1], points[p2][0], points[p2][1]); // Initialize shortestDistance

    // Compute distance for every two points
    for (int i = 0; i < NUMBER_OF_POINTS; i++)
    {
        for (int j = i + 1; j < NUMBER_OF_POINTS; j++)
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
    std::cout << "The closest two points are "
              << "("
              << points[p1][0] << ", " << points[p1][1]
              << ") and (" << points[p2][0] << ", "
              << points[p2][1] << ")" << std::endl;

    return 0;
}