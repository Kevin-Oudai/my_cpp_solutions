#include "Location.h"

Location::Location()
{
    row = 0;
    col = 0;
}

Location::Location(int r, int c, double m)
{
    row = r;
    col = c;
    maxValue = m;
}

int Location::getRow()
{
    return row;
}

int Location::getCol()
{
    return col;
}

int Location::getMaxValue()
{
    return maxValue;
}

void Location::setRow(int rowValue)
{
    row = rowValue;
}

void Location::setCol(int colValue)
{
    col = colValue;
}

void Location::setMaxValue(double max)
{
    maxValue = max;
}