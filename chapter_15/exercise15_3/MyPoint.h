#ifndef MYPOINT_H
#define MYPOINT_H

class MyPoint
{
public:
    MyPoint();
    MyPoint(double x, double y);

    double getX() const;
    double getY() const;
    double distance(const MyPoint &endPoint) const;

private:
    double x;
    double y;
};

#endif
