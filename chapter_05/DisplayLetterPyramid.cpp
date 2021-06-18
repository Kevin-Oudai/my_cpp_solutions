// Exercise 5.21 - Display letters in a pyramid pattern

#include <iostream>
#include <iomanip>

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < i; j++)
            {
                std::cout << std::setw(3) << " ";
            }
            for (int k = 97; k <= 105 - i; k++)
            {
                std::cout << std::setw(3) << static_cast<char>(k);
            }
            for (int l = 105 - i; l >= 97; l--)
            {
                std::cout << std::setw(3) << static_cast<char>(l);
            }

            std::cout << std::endl;
        }
        else
        {
            std::cout << " ";
            for (int j = 0; j < i; j++)
            {
                std::cout << std::setw(3) << " ";
            }
            for (int k = 97; k <= 105 - i; k++)
            {
                std::cout << std::setw(3) << static_cast<char>(k);
            }
            for (int l = 105 - i; l >= 97; l--)
            {
                std::cout << std::setw(3) << static_cast<char>(l);
            }
            std::cout << std::endl;
        }
    }
    return 0;
}