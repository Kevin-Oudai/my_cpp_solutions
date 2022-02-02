#include <iostream>

const int SIZE = 3;
bool isPositive(const double m[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (m[i][j] < 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool isOne(const double m[][SIZE])
{
    for (int j = 0; j < SIZE; j++)
    {
        double total = 0;
        for (int i = 0; i < SIZE; i++)
        {
            total += m[i][j];
        }
        if (total == 1)
        {
            return true;
        }
    }
    return false;
}

bool isMarkovMatrix(const double m[][SIZE])
{
    if (isOne(m) && isPositive(m))
    {
        return true;
    }
    return false;
}

int main()
{
    double m[SIZE][SIZE];
    std::cout << "Enter a 3 by 3 matrix row by row: ";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> m[i][j];
        }
    }
    if (isMarkovMatrix(m))
    {
        std::cout << "It is a Markov matrix" << std::endl;
    }
    else
    {
        std::cout << "It is not a Markov matrix" << std::endl;
    }
    return 0;
}