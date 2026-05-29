#include <iostream>
#include <random>
#include <string>
#include <vector>

std::string joinIndices(const std::vector<int> &indices)
{
    std::string out;
    for (size_t i = 0; i < indices.size(); i++)
    {
        if (i > 0)
        {
            out += ", ";
        }
        out += std::to_string(indices[i]);
    }
    return out;
}

int main()
{
    int n = 0;
    std::cout << "Enter the size for the matrix: ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Size must be positive." << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    std::mt19937 gen(static_cast<unsigned int>(std::random_device{}()));
    std::uniform_int_distribution<int> dist(0, 1);

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            matrix[r][c] = dist(gen);
        }
    }

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            std::cout << matrix[r][c];
        }
        std::cout << std::endl;
    }

    std::vector<int> rowsAllZero;
    std::vector<int> rowsAllOne;
    std::vector<int> colsAllZero;
    std::vector<int> colsAllOne;

    for (int r = 0; r < n; r++)
    {
        bool allZero = true;
        bool allOne = true;
        for (int c = 0; c < n; c++)
        {
            if (matrix[r][c] != 0)
            {
                allZero = false;
            }
            if (matrix[r][c] != 1)
            {
                allOne = false;
            }
        }
        if (allZero)
        {
            rowsAllZero.push_back(r);
        }
        if (allOne)
        {
            rowsAllOne.push_back(r);
        }
    }

    for (int c = 0; c < n; c++)
    {
        bool allZero = true;
        bool allOne = true;
        for (int r = 0; r < n; r++)
        {
            if (matrix[r][c] != 0)
            {
                allZero = false;
            }
            if (matrix[r][c] != 1)
            {
                allOne = false;
            }
        }
        if (allZero)
        {
            colsAllZero.push_back(c);
        }
        if (allOne)
        {
            colsAllOne.push_back(c);
        }
    }

    bool majorAllZero = true;
    bool majorAllOne = true;
    bool subAllZero = true;
    bool subAllOne = true;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] != 0)
        {
            majorAllZero = false;
        }
        if (matrix[i][i] != 1)
        {
            majorAllOne = false;
        }

        int j = n - 1 - i;
        if (matrix[i][j] != 0)
        {
            subAllZero = false;
        }
        if (matrix[i][j] != 1)
        {
            subAllOne = false;
        }
    }

    if (!rowsAllZero.empty())
    {
        std::cout << "All 0s on row " << joinIndices(rowsAllZero) << std::endl;
    }
    if (!rowsAllOne.empty())
    {
        std::cout << "All 1s on row " << joinIndices(rowsAllOne) << std::endl;
    }
    if (rowsAllZero.empty() && rowsAllOne.empty())
    {
        std::cout << "No same numbers on a row" << std::endl;
    }

    if (!colsAllZero.empty())
    {
        std::cout << "All 0s on column " << joinIndices(colsAllZero) << std::endl;
    }
    if (!colsAllOne.empty())
    {
        std::cout << "All 1s on column " << joinIndices(colsAllOne) << std::endl;
    }
    if (colsAllZero.empty() && colsAllOne.empty())
    {
        std::cout << "No same numbers on a column" << std::endl;
    }

    if (majorAllZero)
    {
        std::cout << "All 0s on the major diagonal" << std::endl;
    }
    else if (majorAllOne)
    {
        std::cout << "All 1s on the major diagonal" << std::endl;
    }
    else
    {
        std::cout << "No same numbers on the major diagonal" << std::endl;
    }

    if (subAllZero)
    {
        std::cout << "All 0s on the subdiagonal" << std::endl;
    }
    else if (subAllOne)
    {
        std::cout << "All 1s on the subdiagonal" << std::endl;
    }
    else
    {
        std::cout << "No same numbers on the subdiagonal" << std::endl;
    }

    return 0;
}
