#include <iostream>

const int SIZE = 3;

void sortRows(const double m[][SIZE], double result[][SIZE])
{
    double memory;
    for (int i = 0; i < SIZE; i++)
    {
        memory = m[i][0];
        for (int j = 0; j < SIZE; j++)
        {
            if (memory < m[i][j + 1])
            {
                result[i][j] = memory;
                memory = m[i][j + 1];
            }
            else if (j == 2)
            {
                result[i][j] = memory;
            }
            else
            {
                result[i][j] = m[i][j + 1];
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
    sortRows(m, result);
    displayMatrix(m);
    std::cout << "The row-sorted array is" << std::endl;
    displayMatrix(result);
    return 0;
}