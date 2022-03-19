#include <iostream>
#include "Rectangle2D.h"

int main()
{
    Rectangle2D r1(2, 2, 5.5, 4.9);
    Rectangle2D r2(4, 5, 10.5, 3.2);
    Rectangle2D r3(3, 5, 2.3, 5.4);

    (r1.contains(3, 3)) ? std::cout << "R1 contains the point (3, 3)." << std::endl
                        : std::cout << "R1 does not contain the point (3, 3)." << std::endl;
    (r1.contains(r2)) ? std::cout << "R1 contains R2" << std::endl
                      : std::cout << "R1 does not contain R2" << std::endl;
    (r1.overlaps(r3)) ? std::cout << "R1 overlaps R3" << std::endl
                      : std::cout << "R1 does not overlap R3" << std::endl;
    return 0;
}