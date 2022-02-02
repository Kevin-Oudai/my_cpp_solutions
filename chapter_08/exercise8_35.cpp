#include <iostream>

bool isValid(int matrix[][6], int row, int col)
{
    bool validRow = true;
    bool validCol = true;
    for (int i = 0; i < 6; i++)
    {
        if (matrix[row][i])
        {
            validRow = !validRow;
        }
    }
    for (int j = 0; j < 6; j++)
    {
        if (matrix[j][col])
        {
            validCol = !validCol;
        }
    }

    return (validRow || validCol);
}

int main()
{
    std::cout << "Enter a 6-by-6 matrix row by row: ";
    int matrix[6][6] = {};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (!isValid(matrix, i, j))
            {
                std::cout << "The first row and column where the parity is violated is at (" << i << ", " << j << ")." << std::endl;
                i = 6;
                break;
            }
        }
    }

    return 0;
}