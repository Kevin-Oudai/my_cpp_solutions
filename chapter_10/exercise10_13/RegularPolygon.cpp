#include "RegularPolygon.h"
#include <cmath>

RegularPolygon::RegularPolygon()
{
    n = 3;
    side = 1;
    x = 0;
    y = 0;
}

RegularPolygon::RegularPolygon(int numberOfSides, double sideLength)
{
    n = numberOfSides;
    side = sideLength;
    x = 0;
    y = 0;
}

RegularPolygon::RegularPolygon(int numberOfSides, double sideLength, double xCord, double yCord)
{
    n = numberOfSides;
    side = sideLength;
    x = xCord;
    y = yCord;
}

int RegularPolygon::getN() const
{
    return n;
}

double RegularPolygon::getSide() const
{
    return side;
}

double RegularPolygon::getX() const
{
    return x;
}

double RegularPolygon::getY() const
{
    return y;
}

void RegularPolygon::setN(int numberOfSides)
{
    n = numberOfSides;
}

void RegularPolygon::setSide(double sideLength)
{
    side = sideLength;
}

void RegularPolygon::setX(double xCord)
{
    x = xCord;
}

void RegularPolygon::setY(double yCord)
{
    y = yCord;
}

double RegularPolygon::getPerimeter() const
{
    return n * side;
}

double RegularPolygon::getArea() const
{
    return (n * side * side) / (4 * tan(3.141592654 / n));
}