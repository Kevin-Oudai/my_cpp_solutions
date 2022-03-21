#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle();
    Circle(double);
    ~Circle(); // Destructor
    double getArea() const;
    double getRadius() const;
    void setRadius(double);
    static int getNumberOfObjects();

private:
    double radius;
    static int numberOfObjects;
};

#endif