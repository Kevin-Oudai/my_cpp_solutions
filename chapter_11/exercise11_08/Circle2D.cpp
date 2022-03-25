#include "Circle2D.h"
#include <cmath>

Circle2D::Circle2D()
{
    this->x = 0;
    this->y = 0;
    this->radius = 0;
}

Circle2D::Circle2D(double x, double y, double radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

double Circle2D::getArea() const
{
    double area = 3.14 * this->radius * this->radius;
    return area;
}

double Circle2D::getPerimeter() const
{
    double perimeter = 6.28 * this->radius;
    return perimeter;
}

bool Circle2D::contains(double x, double y) const
{
    double distance = std::sqrt(std::pow(this->x - x, 2) + std::pow(this->y - y, 2));
    if (distance < this->radius)
    {
        return true;
    }
    return false;
}

bool Circle2D::contains(const Circle2D &circle) const
{
    double distance = std::sqrt(std::pow(this->x - circle.x, 2) + std::pow(this->y - circle.y, 2));
    distance += circle.getRadius();
    if (distance < this->radius)
    {
        return true;
    }
    return false;
}

bool Circle2D::overlaps(const Circle2D &circle) const
{
    double distance = std::sqrt(std::pow(this->x - circle.x, 2) + std::pow(this->y - circle.y, 2));
    distance -= circle.getRadius();
    if (distance < this->radius + circle.getRadius())
    {
        return true;
    }
    return false;
}

double Circle2D::getRadius() const
{
    return this->radius;
}