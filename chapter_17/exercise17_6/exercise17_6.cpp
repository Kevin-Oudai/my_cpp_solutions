#include <iostream>
#include "ThreeOverSeries.h"

int main()
{
    ThreeOverSeries series;
    for (int n = 1; n <= 15; n++)
    {
        std::cout << "f(" << n << ") = " << series.sum(n) << std::endl;
    }
    return 0;
}
