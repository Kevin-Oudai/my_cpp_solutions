#include <iostream>

const int SIZE = 3;

void sortColumns(const double m[][SIZE], double result[][SIZE])
{
    double memory;
    for (int i = 0; i < SIZE; i++)
    {
        memory = m[0][i];
        for (int j = 0; j < SIZE; j++)
        {
            if (memory < m[j + 1][i])
            {
                result[j][i] = memory;
                memory = m[j + 1][i];
            }
            else if (j == 2)
            {
                result[j][i] = memory;
            }
            else
            {
                result[j][i] = m[j + 1][i];
            }
        }
    }
}

void displayMatrix(double matrix[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    double m[SIZE][SIZE] = {}, result[SIZE][SIZE] = {};

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cin >> m[i][j];
        }
    }
    std::cout << "Hi" << std::endl;
    sortColumns(m, result);
    displayMatrix(m);
    std::cout << "The column-sorted array is" << std::endl;
    displayMatrix(result);
    return 0;
}