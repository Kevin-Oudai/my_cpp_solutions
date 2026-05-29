#ifndef LOCATION_H
#define LOCATION_H

class Location
{
public:
    Location();
    Location(int r, int c, double max);

    int getRow() const;
    int getCol() const;
    double getMaxValue() const;

    void setRow(int r);
    void setCol(int c);
    void setMaxValue(double max);

private:
    int row;
    int col;
    double maxValue;
};

#endif
