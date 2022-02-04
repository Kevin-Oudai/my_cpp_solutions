#include <iostream>
#include "LinearEquation.h"

void display(LinearEquation l)
{
    if (l.isSolvable())
    {
        std::cout << "x is " << l.getX() << " and y is " << l.getY() << std::endl;
    }
    else
    {
        std::cout << "The equation has no solution." << std::endl;
    }
}

int main()
{
    LinearEquation l1(9.0, 4.0, 3, -5, -6, -21);
    LinearEquation l2(1, 2, 2, 4, 4, 5);

    display(l1);
    display(l2);
    return 0;
}