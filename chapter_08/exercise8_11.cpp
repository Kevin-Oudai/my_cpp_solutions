// Exercise 8.11: Game - nine heads and tails
#include <iostream>

const int row = 3, col = 3;

void displayArray(bool results[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (results[i][j]) ? std::cout << "T " : std::cout << "F ";
        }
        std::cout << std::endl;
    }
}

void reverseArray(bool results[row][col])
{
    bool temp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp = results[i][j];
            results[i][j] = results[row - 1 - i][col - 1 - j];
            results[row - 1 - i][col - 1 - j] = temp;
        }
    }
    displayArray(results);
}

void fillArray(int number, bool results[row][col])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            results[i][j] = number % 2;
            number /= 2;
        }
    }
    reverseArray(results);
}

int main()
{
    bool results[row][col] = {0};
    int number;
    std::cout << "Enter a number between 0 and 511: ";
    std::cin >> number;
    fillArray(number, results);
    return 0;
}