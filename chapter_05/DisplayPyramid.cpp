// Exercise 5.19 - Display pyramid

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Enter the number of lines: \n";
    int number;
    std::cin >> number;
    int count = 1;

    while (count <= number)
    {
        for (int i = 0; i < number - count; i++)
        {
            std::cout << std::setw(3) << " ";
        }
        for (int j = count; j >= 1; j--)
            std::cout << std::setw(3) << j;
        for (int k = 2; k <= count; k++)
            std::cout << std::setw(3) << k;
        std::cout << "\n";
        count++;
    }
    return 0;
}