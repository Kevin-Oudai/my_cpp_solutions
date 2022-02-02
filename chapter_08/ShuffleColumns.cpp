// Exercise 8.8 - Shuffle Columns
#include <iostream>
#include <cstdlib>
#include <ctime>

const int columnSize = 5;

void display(int m[3][columnSize])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < columnSize; j++)
        {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void shuffle(int m[3][columnSize])
{
    int randomCol, temp;
    for (int i = 0; i < columnSize; i++)
    {
        randomCol = rand() % 5;
        while (randomCol == i)
        {
            randomCol = rand() % 5;
        }
        for (int j = 0; j < 3; j++)
        {
            temp = m[j][i];
            m[j][i] = m[j][randomCol];
            m[j][randomCol] = temp;
        }
    }
    display(m);
}

int main()
{
    srand(time(0));
    int m[3][5] = {{1, 2, 3, 4, 5}, {3, 4, 5, 6, 7}, {5, 6, 7, 8, 9}};
    shuffle(m);
    return 0;
}