#include <iostream>
#include <cstdlib>
#include <ctime>

void displayMatrix(int matrix[][6])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int findSmallestRow(int matrix[][6])
{
    int smallest = 6;
    int index = 0;
    int newSmall;
    for (int i = 0; i < 6; i++)
    {
        newSmall = 0;
        for (int j = 0; j < 6; j++)
        {
            newSmall += matrix[i][j];
        }
        if (newSmall < smallest)
        {
            index = i;
            smallest = newSmall;
        }
    }
    return index;
}

int findSmallestColumn(int matrix[][6])
{
    int smallest = 6;
    int index = 0;
    int newSmall;
    for (int i = 0; i < 6; i++)
    {
        newSmall = 0;
        for (int j = 0; j < 6; j++)
        {
            newSmall += matrix[j][i];
        }
        if (newSmall < smallest)
        {
            index = i;
            smallest = newSmall;
        }
    }
    return index;
}

int main()
{
    srand(time(0));
    int matrix[6][6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            matrix[i][j] = rand() % 2;
        }
    }
    displayMatrix(matrix);
    int row = findSmallestRow(matrix);
    int col = findSmallestColumn(matrix);
    std::cout << "The smallest row's index: " << row << std::endl;
    std::cout << "The smallest column's index: " << col << std::endl;
    return 0;
}