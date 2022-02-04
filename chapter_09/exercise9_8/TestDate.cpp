#include <iostream>
#include "Date.h"

int main()
{
    Date d1;
    Date d2(555550);

    std::cout << "Date 1: " << d1.getYear() << "_" << d1.getMonth() << "_" << d1.getDay() << std::endl;
    std::cout << "Date 2: " << d2.getYear() << "_" << d2.getMonth() << "_" << d2.getDay() << std::endl;
    return 0;
}