#include <iostream>
#include "CircleWithDestructor.h"

int main()
{
    Circle *pCircle1 = new Circle();
    Circle *pCircle2 = new Circle();
    Circle *pCircle3 = new Circle();

    std::cout << "Number of circle objects created: "
              << Circle::getNumberOfObjects() << std::endl;

    std::cout << "Number of circle objects created: "
              << Circle::getNumberOfObjects() << std::endl;

    return 0;
}