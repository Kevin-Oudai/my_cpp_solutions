#include <iostream>
#include "MyPoint.h"

int main()
{
    MyPoint p1;
    MyPoint p2(10, 30.5);

    std::cout << "Distance: " << p1.distance(p2) << std::endl;
    return 0;
}