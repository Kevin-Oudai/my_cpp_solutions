#include <iostream>
#include "GcdTimer.h"

int main()
{
    std::cout << "Enter start and end Fibonacci indexes (40 45 for the exercise): ";
    int startIndex;
    int endIndex;
    std::cin >> startIndex >> endIndex;

    if (startIndex < 1 || endIndex < startIndex)
    {
        std::cout << "Invalid index range" << std::endl;
        return 0;
    }

    GcdTimer timer;
    timer.displayTable(startIndex, endIndex);

    return 0;
}
