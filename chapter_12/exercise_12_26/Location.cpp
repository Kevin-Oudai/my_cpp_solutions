#include "Location.h"

Location::Location() : row(0), col(0), maxValue(0) {}

Location::Location(int r, int c, double max) : row(r), col(c), maxValue(max) {}

int Location::getRow() const
{
    return row;
}

int Location::getCol() const
{
    return col;
}

double Location::getMaxValue() const
{
    return maxValue;
}

void Location::setRow(int r)
{
    row = r;
}

void Location::setCol(int c)
{
    col = c;
}

void Location::setMaxValue(double max)
{
    maxValue = max;
}
