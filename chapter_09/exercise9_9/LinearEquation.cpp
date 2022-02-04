#include "LinearEquation.h"

LinearEquation::LinearEquation(double g, double h, double i, double j, double k, double l)
{
    a = g;
    b = h;
    c = i;
    d = j;
    e = k;
    f = l;
}

double LinearEquation::getA()
{
    return a;
}

double LinearEquation::getB()
{
    return b;
}

double LinearEquation::getC()
{
    return c;
}

double LinearEquation::getD()
{
    return d;
}

double LinearEquation::getE()
{
    return e;
}

double LinearEquation::getF()
{
    return f;
}

bool LinearEquation::isSolvable()
{
    if ((a * d - b * c) != 0)
    {
        return true;
    }
    return false;
}

double LinearEquation::getX()
{
    return (e * d - b * f) / (a * d - b * c);
}

double LinearEquation::getY()
{
    return (a * f - e * c) / (a * d - b * c);
}