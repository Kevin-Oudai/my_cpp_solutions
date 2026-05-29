#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle();
    Circle(double newRadius);

    double getArea() const;
    double getRadius() const;
    void setRadius(double newRadius);

    bool operator<(const Circle &secondCircle) const;
    bool operator<=(const Circle &secondCircle) const;
    bool operator==(const Circle &secondCircle) const;
    bool operator!=(const Circle &secondCircle) const;
    bool operator>(const Circle &secondCircle) const;
    bool operator>=(const Circle &secondCircle) const;

private:
    double radius;
};

#endif
