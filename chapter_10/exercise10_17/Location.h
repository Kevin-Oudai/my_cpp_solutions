#ifndef LOCATION_H
#define LOCATION_H

class Location
{
public:
    Location();
    Location(int r, int c, double m);
    int getRow();
    int getCol();
    int getMaxValue();
    void setRow(int rowValue);
    void setCol(int colValue);
    void setMaxValue(double max);
    int row;
    int col;
    double maxValue;
};
#endif