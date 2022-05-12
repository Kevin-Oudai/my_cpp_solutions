// Exercise 6.16 - Display matrix of 0s and 1s

#include <iostream>
#include <cstdlib>
#include <ctime>

void printMatrix(int n)
{
    int digit = rand() % 2;
    for (int i = 1; i <= n * n; i++)
    {
        std::cout << digit << " ";
        if (i % n == 0)
        {
            std::cout << std::endl;
        }
        digit = rand() % 2;
    }
}

int main()
{
    srand(time(0));
    for (int i = 1; i <= 10; i++)
    {
        printMatrix(i);
        std::cout << "*********************" << std::endl;
    }
    return 0;
}