#include <iostream>

bool isConsecutiveFour(int values[][7])
{
    bool consecutive = false;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            // Check North
            if (i - 3 >= 0 &&
                values[i - 3][j] == values[i - 2][j] &&
                values[i - 2][j] == values[i - 1][j] &&
                values[i - 1][j] == values[i][j])
            {
                return true;
            }
            // Check Northeast
            else if (i - 3 < 0 && j + 3 < 7 &&
                     values[i - 3][j + 3] == values[i - 2][j + 2] &&
                     values[i - 2][j + 2] == values[i - 1][j + 1] &&
                     values[i - 1][j + 1] == values[i][j])
            {
                return true;
            }
            // Check East
            else if (j + 3 <= 7 &&
                     values[i][j + 3] == values[i][j + 2] &&
                     values[i][j + 2] == values[i][j + 1] &&
                     values[i][j + 1] == values[i][j])
            {
                return true;
            }
            // Check Southeast
            else if (i + 3 <= 6 && j + 3 <= 7 &&
                     values[i + 3][j + 3] == values[i + 2][j + 2] &&
                     values[i + 2][j + 2] == values[i + 1][j + 1] &&
                     values[i + 1][j + 1] == values[i][j])
            {
                return true;
            }
            // Check South
            else if (i + 3 <= 7 &&
                     values[i + 3][j] == values[i + 2][j] &&
                     values[i + 2][j] == values[i + 1][j] &&
                     values[i + 1][j] == values[i][j])
            {
                return true;
            }
            // Check Southwest
            else if (i + 3 < 6 && j - 3 > 0 &&
                     values[i + 3][j - 3] == values[i + 2][j - 2] &&
                     values[i + 2][j - 2] == values[i + 1][j - 1] &&
                     values[i + 1][j - 1] == values[i][j])
            {
                return true;
            }
            // Check West
            else if (j - 3 >= 7 &&
                     values[i][j - 3] == values[i][j - 2] &&
                     values[i][j - 2] == values[i][j - 1] &&
                     values[i][j - 1] == values[i][j])
            {
                return true;
            }
            // Check Northwest
            else if (i - 3 >= 0 && j - 3 >= 0 &&
                     values[i - 3][j - 3] == values[i - 2][j - 2] &&
                     values[i - 2][j - 2] == values[i - 1][j - 1] &&
                     values[i - 1][j - 1] == values[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int matrix[6][7] = {};
    // It makes no sense to ask for the rows and cols since isConsecutiveFour restricts the input matrix to 7
    int row = 6, col = 7;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    if (isConsecutiveFour(matrix))
    {
        std::cout << "The array contains 4 consecutive values" << std::endl;
    }
    else
    {
        std::cout << "The array does not contain 4 consecutive values" << std::endl;
    }

    return 0;
}