#include <iostream>
#include <random>
#include <vector>

int main()
{
    const int SIZE = 5;
    std::vector<std::vector<int>> matrix(SIZE, std::vector<int>(SIZE, 0));

    std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<int> dist(0, 1);

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            matrix[r][c] = dist(gen);
        }
    }

    std::vector<int> rowOnes(SIZE, 0);
    std::vector<int> colOnes(SIZE, 0);

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            if (matrix[r][c] == 1)
            {
                rowOnes[r]++;
                colOnes[c]++;
            }
        }
    }

    int minRowOnes = SIZE + 1;
    int minColOnes = SIZE + 1;
    for (int r = 0; r < SIZE; r++)
    {
        if (rowOnes[r] < minRowOnes)
        {
            minRowOnes = rowOnes[r];
        }
    }
    for (int c = 0; c < SIZE; c++)
    {
        if (colOnes[c] < minColOnes)
        {
            minColOnes = colOnes[c];
        }
    }

    for (int r = 0; r < SIZE; r++)
    {
        for (int c = 0; c < SIZE; c++)
        {
            std::cout << matrix[r][c];
        }
        std::cout << std::endl;
    }

    std::cout << "The smallest row's index: ";
    bool first = true;
    for (int r = 0; r < SIZE; r++)
    {
        if (rowOnes[r] == minRowOnes)
        {
            if (!first)
            {
                std::cout << ", ";
            }
            std::cout << r;
            first = false;
        }
    }
    std::cout << std::endl;

    std::cout << "The smallest column's index: ";
    first = true;
    for (int c = 0; c < SIZE; c++)
    {
        if (colOnes[c] == minColOnes)
        {
            if (!first)
            {
                std::cout << ", ";
            }
            std::cout << c;
            first = false;
        }
    }
    std::cout << std::endl;

    return 0;
}
