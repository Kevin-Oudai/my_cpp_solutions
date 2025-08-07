// Exercise 6.33 - Algebra: solve 2 x 2 linear equations
#include <iostream>
#include <iomanip>

void solveEquation(double a, double b, double c, double d, double e, double f, double &x, double &y, bool &isSolvable)
{
    double D = a * d - b * c;
    isSolvable = D == 0 ? false : true;
    if (!isSolvable)
    {
        std::cout << "The equation has no solution" << std::endl;
    }
    else
    {
        x = (e * d - b * f) / D;
        y = (a * f - e * c) / D;
        std::cout << std::setprecision(1) << std::showpoint << std::fixed;
        std::cout << "x is " << x << " and y is " << y << std::endl;
    }
}
int main()
{
    double a, b, c, d, e, f, x, y, D;
    bool isSolvable;
    std::cout << "Enter a, b, c, d, e, f: ";
    std::cin >> a >> b >> c >> d >> e >> f;
    solveEquation(a, b, c, d, e, f, x, y, isSolvable);
    return 0;
}