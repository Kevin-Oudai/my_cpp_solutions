#ifndef CIRCLE2D_H
#define CIRCLE2D_H

class Circle2D
{
public:
    Circle2D();
    Circle2D(double x, double y, double radius);
    double getArea() const;
    double getPerimeter() const;
    bool contains(double x, double y) const;
    bool contains(const Circle2D &circle) const;
    bool overlaps(const Circle2D &circle) const;
    double getRadius() const;

private:
    double x;
    double y;
    double radius;
};
#endif