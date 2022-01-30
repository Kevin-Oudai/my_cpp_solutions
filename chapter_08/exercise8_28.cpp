#include <iostream>

const int SIZE = 3;

bool equals(const int m1[][SIZE], const int m2[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int m1[SIZE][SIZE] = {}, m2[SIZE][SIZE] = {};
    std::cout << "Enter m1: ";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> m1[i][j];
        }
    }

    std::cout << "Enter m2: ";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> m2[i][j];
        }
    }

    if (equals(m1, m2))
    {
        std::cout << "Two arrays are strictly identical" << std::endl;
    }
    else
    {
        std::cout << "Two arrays are not strictly identical" << std::endl;
    }
    return 0;
}