// Exercise 5.20 - Display pattern A using loops

#include <iostream>

int main()
{
    std::cout << "Enter an integer from 1 to 9: ";
    int number;
    int count = 0;
    std::cin >> number;

    while (count <= number)
    {
        if (count % number == 0)
        {
            for (int i = 1; i <= number; i++)
            {
                std::cout << i;
            }
            std::cout << "\n";
        }
        else
        {
            std::cout << 1;
            for (int i = 0; i < number - 2; i++)
            {
                std::cout << " ";
            }
            std::cout << number << std::endl;
        }

        count++;
    }
    return 0;
}