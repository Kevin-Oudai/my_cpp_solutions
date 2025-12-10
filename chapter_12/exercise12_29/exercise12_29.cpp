#include <iostream>
#include <vector>
#include <string>

bool validateLetters(const std::vector<std::vector<char>> &grid, int n)
{
    const char minChar = 'A';
    const char maxChar = static_cast<char>('A' + n - 1);
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] < minChar || grid[r][c] > maxChar)
            {
                std::cout << "Wrong input: the letters must be from " << minChar << " to " << maxChar << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool isLatinSquare(const std::vector<std::vector<char>> &grid, int n)
{
    // Check rows
    for (int r = 0; r < n; r++)
    {
        std::vector<bool> seen(n, false);
        for (int c = 0; c < n; c++)
        {
            int idx = grid[r][c] - 'A';
            if (seen[idx])
            {
                return false;
            }
            seen[idx] = true;
        }
    }

    // Check columns
    for (int c = 0; c < n; c++)
    {
        std::vector<bool> seen(n, false);
        for (int r = 0; r < n; r++)
        {
            int idx = grid[r][c] - 'A';
            if (seen[idx])
            {
                return false;
            }
            seen[idx] = true;
        }
    }

    return true;
}

int main()
{
    int n = 0;
    std::cout << "Enter number n: ";
    std::cin >> n;

    std::vector<std::vector<char>> grid(n, std::vector<char>(n, 'A'));
    std::cout << "Enter " << n << " rows of letters separated by spaces:" << std::endl;

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            std::string token;
            std::cin >> token;
            grid[r][c] = token.empty() ? 'A' : token[0];
        }
    }

    if (!validateLetters(grid, n))
    {
        return 0;
    }

    if (isLatinSquare(grid, n))
    {
        std::cout << "The input array is a Latin square" << std::endl;
    }
    else
    {
        std::cout << "The input array is not a Latin square" << std::endl;
    }

    return 0;
}
