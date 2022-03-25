#include "Rectangle2D.h"
#include <cmath>

Rectangle2D::Rectangle2D()
{
    this->x = 0;
    this->y = 0;
    this->width = 1;
    this->height = 1;
}

Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

double Rectangle2D::getX() const
{
    return this->x;
}

double Rectangle2D::getY() const
{
    return this->y;
}

void Rectangle2D::setX(double x)
{
    this->x = x;
}

void Rectangle2D::setY(double y)
{
    this->y = y;
}

double Rectangle2D::getWidth() const
{
    return this->width;
}

double Rectangle2D::getHeight() const
{
    return this->height;
}

double Rectangle2D::getArea() const
{
    return this->width * this->height;
}

double Rectangle2D::getPerimeter() const
{
    return 2 * (this->width + this->height);
}

bool Rectangle2D::contains(double x, double y) const
{
    double distance = std::sqrt(std::pow(this->x - x, 2) + std::pow(this->y - y, 2));
    if (distance < (this->width) / 2 && distance < (this->height) / 2)
    {
        return true;
    }
    return false;
}

bool Rectangle2D::contains(const Rectangle2D &r)
{
    double lowerX1, lowerX2, upperX1;
    double upperX2, lowerY1, lowerY2, upperY1, upperY2;
    bool Xinside, Yinside;

    lowerX1 = this->x - this->width / 2.0;
    upperX1 = this->x + this->width / 2.0;
    lowerY1 = this->y - this->height / 2.0;
    upperY1 = this->y + this->height / 2.0;

    lowerX2 = r.getX() - r.getWidth() / 2.0;
    upperX2 = r.getX() + r.getWidth() / 2.0;
    lowerY2 = r.getY() - r.getHeight() / 2.0;
    upperY2 = r.getY() + r.getHeight() / 2.0;

    // Checks if the boundaries of the smaller rectangle are inside the larger rectangle
    Xinside = lowerX1 <= lowerX2 && lowerX1 <= upperX2 && upperX1 >= lowerX2 && upperX1 >= upperX2;
    Yinside = lowerY1 <= lowerY2 && lowerY1 <= upperY2 && upperY1 >= lowerY2 && upperY1 >= upperY2;

    if (Xinside && Yinside)
        return true;
    return false;
}

bool Rectangle2D::overlaps(const Rectangle2D &r)
{
    double lowerX1, lowerX2, upperX1;
    double upperX2, lowerY1, lowerY2, upperY1, upperY2;
    bool Xinside, Yinside, Youtside, Xoutside;

    lowerX1 = this->x - this->width / 2.0;
    upperX1 = this->x + this->width / 2.0;
    lowerY1 = this->y - this->height / 2.0;
    upperY1 = this->y + this->height / 2.0;

    lowerX2 = r.getX() - r.getWidth() / 2.0;
    upperX2 = r.getX() + r.getWidth() / 2.0;
    lowerY2 = r.getY() - r.getHeight() / 2.0;
    upperY2 = r.getY() + r.getHeight() / 2.0;

    // Checks if the boundaries of the smaller rectangle are inside the larger rectangle
    Xinside = lowerX1 <= lowerX2 && lowerX1 <= upperX2 && upperX1 >= lowerX2 && upperX1 >= upperX2;
    Yinside = lowerY1 <= lowerY2 && lowerY1 <= upperY2 && upperY1 >= lowerY2 && upperY1 >= upperY2;

    // Checks if the boundaries of the smaller rectangle are outside of the larger rectangle
    Xoutside = (lowerX1 > lowerX2 && lowerX1 > upperX2) || (upperX1 < lowerX2 && upperX1 < upperX2);
    Youtside = (lowerY1 > lowerY2 && lowerY1 > upperY2) || (upperY1 < lowerY2 && upperY1 < upperY2);

    if (Xinside && Youtside || Xoutside && Yinside)
        return true;
    return false;
}