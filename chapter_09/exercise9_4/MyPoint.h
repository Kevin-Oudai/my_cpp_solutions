#ifndef MYPOINT_H
#define MYPOINT_H

class MyPoint
{
public:
    MyPoint();
    MyPoint(double x, double y);
    double getX();
    double getY();
    double distance(MyPoint endPoint);

private:
    double x;
    double y;
};
#endif