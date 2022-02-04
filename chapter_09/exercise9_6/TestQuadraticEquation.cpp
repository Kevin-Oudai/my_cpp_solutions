#include <iostream>
#include "QuadraticEquation.h"

int main()
{
    double a, b, c;
    std::cout << "Enter the value for a, b and c: ";
    std::cin >> a >> b >> c;
    QuadraticEquation q(a, b, c);
    double d = q.getDiscriminant();
    if (d > 0)
    {
        std::cout << "The two roots are " << q.getRoot1() << " and " << q.getRoot2() << "." << std::endl;
    }
    else if (d == 0)
    {
        std::cout << "The two roots are equal. It has a value of " << q.getRoot1() << "." << std::endl;
    }
    else
    {
        std::cout << "The equation has no real roots." << std::endl;
    }

    return 0;
}