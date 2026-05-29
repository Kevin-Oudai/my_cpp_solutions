#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> findLargestBlock(const std::vector<std::vector<int>> &m)
{
    if (m.empty() || m[0].empty())
    {
        return {0, 0, 0};
    }

    const int rows = static_cast<int>(m.size());
    const int cols = static_cast<int>(m[0].size());
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    int bestSize = 0;
    int bestRow = 0;
    int bestCol = 0;

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            if (m[r][c] == 1)
            {
                if (r == 0 || c == 0)
                {
                    dp[r][c] = 1;
                }
                else
                {
                    dp[r][c] = 1 + std::min({dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1]});
                }

                if (dp[r][c] > bestSize)
                {
                    bestSize = dp[r][c];
                    bestRow = r - bestSize + 1;
                    bestCol = c - bestSize + 1;
                }
            }
        }
    }

    return {bestRow, bestCol, bestSize};
}

int main()
{
    int n = 0;
    std::cout << "Enter the number of rows for the matrix: ";
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    std::cout << "Enter the matrix row by row:" << std::endl;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            std::cin >> matrix[r][c];
        }
    }

    std::vector<int> result = findLargestBlock(matrix);
    int row = result[0];
    int col = result[1];
    int size = result[2];

    if (size == 0)
    {
        std::cout << "No square submatrix of 1s found." << std::endl;
    }
    else
    {
        std::cout << "The maximum square submatrix is at (" << row << ", " << col << ") with size " << size << std::endl;
    }

    return 0;
}
