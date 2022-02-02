#include <iostream>
#include <ctime>
#include <cstdlib>

void displayMatrix(int matrix[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isValid(int matrix[][9], int row, int col)
{
    bool validRow = false;
    bool validCol = false;
    for (int i = 0; i < 9; i++)
    {
        if (matrix[row][i])
        {
            validRow = !validRow;
        }
    }
    for (int j = 0; j < 9; j++)
    {
        if (matrix[j][col])
        {
            validCol = !validCol;
        }
    }

    return (validRow && validCol);
}

bool checkOdds(int matrix[][9])
{

    for (int i = 0; i < 9; i++)
    {
        if (!isValid(matrix, i, i))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    srand(time(0));
    int matrix[9][9] = {};
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
    displayMatrix(matrix);
    bool allOdd = checkOdds(matrix);
    if (allOdd)
    {
        std::cout << "There is an odd number of ones in each row and column." << std::endl;
    }

    return 0;
}