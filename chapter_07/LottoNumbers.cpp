// Listing 7.2 - LottoNumbers.cpp

#include <iostream>

int main()
{
    bool isCovered[99];
    int number;

    for (int i = 0; i < 99; i++)
    {
        isCovered[i] = false;
    }

    std::cin >> number;
    while (number != 0)
    {
        isCovered[number - 1] = true;
        std::cin >> number;
    }

    bool allCovered = true;
    for (int i = 0; i < 99; i++)
    {
        if (!isCovered[i])
        {
            allCovered = false;
            break;
        }
    }

    if (allCovered)
        std::cout << "The tickets cover all numbers" << std::endl;
    else
        std::cout << "The tickets don't cover all numbers" << std::endl;

    return 0;
}