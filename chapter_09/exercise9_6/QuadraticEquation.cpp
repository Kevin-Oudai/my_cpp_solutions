#include "QuadraticEquation.h"
#include <cmath>

QuadraticEquation::QuadraticEquation(double x, double y, double z)
{
    a = x;
    b = y;
    c = z;
}

double QuadraticEquation::getA()
{
    return a;
}

double QuadraticEquation::getB()
{
    return b;
}

double QuadraticEquation::getC()
{
    return c;
}

double QuadraticEquation::getDiscriminant()
{
    double D = std::pow(b, 2) - 4 * a * c;
    return D;
}

double QuadraticEquation::getRoot1()
{
    double D = getDiscriminant();
    if (D < 0)
    {
        return 0;
    }
    else
    {
        return ((-b + std::sqrt(D)) / (2 * a));
    }
}

double QuadraticEquation::getRoot2()
{
    double D = getDiscriminant();
    if (D < 0)
    {
        return 0;
    }
    else
    {
        return ((-b - std::sqrt(D)) / (2 * a));
    }
}
