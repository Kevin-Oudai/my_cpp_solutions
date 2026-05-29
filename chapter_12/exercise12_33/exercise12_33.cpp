#include <iostream>
#include <vector>

struct Point
{
    double x;
    double y;
};

double polygonArea(const std::vector<Point> &points)
{
    if (points.size() < 3)
    {
        return 0.0;
    }

    double sum = 0.0;
    const size_t n = points.size();
    for (size_t i = 0; i < n; i++)
    {
        const Point &p1 = points[i];
        const Point &p2 = points[(i + 1) % n];
        sum += (p1.x * p2.y) - (p2.x * p1.y);
    }
    return 0.5 * std::abs(sum);
}

int main()
{
    int count = 0;
    std::cout << "Enter the number of the points: ";
    std::cin >> count;

    if (count < 3)
    {
        std::cout << "A polygon needs at least 3 points." << std::endl;
        return 0;
    }

    std::vector<Point> points(count);
    std::cout << "Enter the coordinates of the points: ";
    for (int i = 0; i < count; i++)
    {
        std::cin >> points[i].x >> points[i].y;
    }

    double area = polygonArea(points);
    std::cout.setf(std::ios::fixed);
    std::cout.precision(3);
    std::cout << "The total area is " << area << std::endl;

    return 0;
}
