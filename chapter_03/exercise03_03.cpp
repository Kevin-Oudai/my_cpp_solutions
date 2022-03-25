#include <iostream>
#include <iomanip>

int main()
{
    double a, b, c, d, e, f, x, y, D;
    std::cout << "Enter a, b, c, d, e, f: ";
    std::cin >> a >> b >> c >> d >> e >> f;

    D = a * d - b * c;
    if (D == 0)
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

    return 0;
}