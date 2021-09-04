// Listing 9.1 - TestCircle.cpp

#include <iostream>

class Circle
{
public:
    // The radius of this circle
    double radius;

    // Construct a default circle object
    Circle()
    {
        radius = 1;
    }

    // Construct a circle object
    Circle(double newRadius)
    {
        radius = newRadius;
    }

    // Return the area of this circle
    double getArea()
    {
        return radius * radius * 3.14159;
    }
}; // Must place a semicolon here

int main()
{
    Circle circle1(1.0);
    Circle circle2(25);
    Circle circle3(125);

    std::cout << "the area of the circle of radius " << circle1.radius << " is "
              << circle1.getArea() << std::endl;

    std::cout << "The area of the circle of radius " << circle2.radius << " is "
              << circle2.getArea() << std::endl;

    std::cout << "The area of the circle of radius " << circle3.radius << " is "
              << circle3.getArea() << std::endl;

    // Modify circle radius
    circle2.radius = 100;
    std::cout << "The area of the circle of radius " << circle2.radius << " is "
              << circle2.getArea() << std::endl;

    return 0;
}