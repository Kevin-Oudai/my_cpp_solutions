#include <iostream>

int main()
{
    double matrix[3][3], transpose[3][3];
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = count;
            std::cout << count << " ";
            count++;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transpose[i][j] = matrix[j][i];
            std::cout << transpose[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}