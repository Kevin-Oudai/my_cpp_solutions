// Exercise 6.32 - Algebra: solve quadratic equations
#include <iostream>
#include <cmath>

void solveQuadraticEquation(double a, double b, double c, double &discriminant, double &r1, double &r2)
{
    discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant > 0)
    {
        r1 = (-b + pow(discriminant, 0.5)) / (2 * a);
        r2 = (-b - pow(discriminant, 0.5)) / (2 * a);

        std::cout << "The roots are " << r1 << " and " << r2 << std::endl;
    }
    else if (discriminant == 0)
    {
        r1 = (-b + pow(discriminant, 0.5)) / (2 * a);

        std::cout << "The root is " << r1 << std::endl;
    }
    else
    {
        std::cout << "The equation has no real roots" << std::endl;
    }
}
int main()
{
    double a, b, c, r1, r2, discriminant;
    std::cout << "Enter a, b, c: ";
    std::cin >> a >> b >> c;
    solveQuadraticEquation(a, b, c, discriminant, r1, r2);
    return 0;
}