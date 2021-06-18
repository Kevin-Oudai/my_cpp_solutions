// Listing 5.8 - MultiplicationTable.cpp
#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "       Multiplication Table\n";
    std::cout << "--------------------------------\n";

    std::cout << "  | ";
    for (int j = 1; j <= 9; j++)
    {
        std::cout << std::setw(3) << j;
    }
    std::cout << "\n";

    for (int i = 1; i <= 9; i++)
    {
        std::cout << i << " | ";
        for (int j = 1; j <= 9; j++)
        {
            std::cout << std::setw(3) << i * j;
        }
        std::cout << "\n";
    }
    return 0;
}