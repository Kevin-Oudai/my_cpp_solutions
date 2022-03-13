#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

class RegularPolygon
{
public:
    RegularPolygon();
    RegularPolygon(int numberOfSides, double sideLength);
    RegularPolygon(int numberOfSides, double sideLength, double xCord, double yCord);
    int getN() const;
    double getSide() const;
    double getX() const;
    double getY() const;
    void setN(int numberOfSides);
    void setSide(double sideLength);
    void setX(double xCord);
    void setY(double yCord);
    double getPerimeter() const;
    double getArea() const;

private:
    int n;       // stores the number of sides in the polygon
    double side; // stores the length of the side
    double x;    // x-coordinate of the center of the polygon
    double y;    // y-coordinate of the center of the polygon
};
#endif