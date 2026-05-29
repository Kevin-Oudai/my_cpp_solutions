#include <iostream>
#include "ThreeDPoint.h"

int main()
{
    ThreeDPoint first;
    ThreeDPoint second(10, 30, 25.5);

    std::cout << "The distance between ("
              << first.getX() << ", " << first.getY() << ", " << first.getZ()
              << ") and ("
              << second.getX() << ", " << second.getY() << ", " << second.getZ()
              << ") is " << first.distance(second) << std::endl;

    return 0;
}
