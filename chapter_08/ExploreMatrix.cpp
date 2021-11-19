// Exercise 8.7 - Explore Matrix

#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 4;
void fillMatrix(int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
}

void display(int matrix[][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void checkRows(int matrix[][size])
{

    bool allOnes = false;
    bool allZeroes = false;
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][0] == 0 && matrix[i][1] == 0 && matrix[i][2] == 0 && matrix[i][3] == 0)
        {
            std::cout << "All 0's on row " << i << std::endl;
            allZeroes = true;
        }
        if (matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1 && matrix[i][3] == 1)
        {
            std::cout << "All 1's on row " << i << std::endl;
            allOnes = true;
        }
    }
    if (!allOnes && !allZeroes)
    {
        std::cout << "No same numbers on a row" << std::endl;
    }
}

void checkColumns(int matrix[][size])
{

    bool allOnes = false;
    bool allZeroes = false;
    for (int i = 0; i < size; i++)
    {
        if (matrix[0][i] == 0 && matrix[1][i] == 0 && matrix[2][i] == 0 && matrix[3][i] == 0)
        {
            std::cout << "All 0's on column " << i << std::endl;
            allZeroes = true;
        }
        if (matrix[0][i] == 1 && matrix[1][i] == 1 && matrix[2][i] == 1 && matrix[3][i] == 1)
        {
            std::cout << "All 1's on column " << i << std::endl;
            allOnes = true;
        }
    }
    if (!allOnes && !allZeroes)
    {
        std::cout << "No same numbers on a column" << std::endl;
    }
}

void checkMajorDiagonals(int matrix[][size])
{
    bool allOnes = false;
    bool allZeroes = false;
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] == matrix[3][3] && matrix[3][3] == 0)
    {
        std::cout << "All 0's on a major diagonal" << std::endl;
        allZeroes = true;
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[2][2] == matrix[3][3] && matrix[3][3] == 1)
    {
        std::cout << "All 1's on a major diagonal" << std::endl;
        allOnes = true;
    }
    if (matrix[0][3] == matrix[1][2] && matrix[1][2] == matrix[2][1] && matrix[2][1] == matrix[3][0] && matrix[3][0] == 0)
    {
        std::cout << "All 0's on a major diagonal" << std::endl;
        allZeroes = true;
    }
    if (matrix[0][3] == matrix[1][2] && matrix[1][2] == matrix[2][1] && matrix[2][1] == matrix[3][0] && matrix[3][0] == 1)
    {
        std::cout << "All 1's on a major diagonal" << std::endl;
        allZeroes = true;
    }
    if (!allOnes && !allZeroes)
    {
        std::cout << "No same numbers on a major diagonal" << std::endl;
    }
}

void checkMatrix(int matrix[][size])
{
    checkRows(matrix);
    checkColumns(matrix);
    checkMajorDiagonals(matrix);
}

int main()
{
    srand(time(0));
    int matrix[size][size] = {};
    fillMatrix(matrix);
    display(matrix);
    checkMatrix(matrix);
    return 0;
}