/*
Codex Task:
Write a C++ program that detects if a 2D grid contains four consecutive equal numbers in a row in any of the following directions:
1. Horizontal (→)
2. Vertical (↓)
3. Diagonal down-right (↘)
4. Diagonal up-right (↗)

Specifications:
- Implement a function with the signature:
    bool isConsecutiveFour(const std::vector<std::vector<int>>& values)
- The function should:
    - Return true if there are four equal integers consecutively in any direction.
    - Return false otherwise.
    - Assume the input vector is non-empty and rectangular (all rows have the same number of columns).
    - Use camelCase descriptive variable names.
- Approach:
    - Get rowCount and colCount from the vector dimensions.
    - Define the four direction steps: { {0,1}, {1,0}, {1,1}, {-1,1} }.
    - For each cell (row, col), check each direction.
    - Ensure indices stay within bounds before comparing.
    - If four equal numbers are found in sequence, return true.
    - If the loops finish without finding a sequence, return false.
- In main():
    - Prompt the user to enter rowCount and colCount.
    - Prompt the user to enter all values into a 2D vector.
    - Call isConsecutiveFour() and display whether the sequence exists.
*/

#include <iostream>
#include <vector>

bool isConsecutiveFour(const std::vector<std::vector<int>>& values)
{
    int rowCount = static_cast<int>(values.size());
    int colCount = static_cast<int>(values[0].size());
    const int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (int row = 0; row < rowCount; ++row)
    {
        for (int col = 0; col < colCount; ++col)
        {
            for (const auto& direction : directions)
            {
                int currentValue = values[row][col];
                int newRow = row;
                int newCol = col;
                int count = 1;

                for (int step = 1; step < 4; ++step)
                {
                    newRow += direction[0];
                    newCol += direction[1];

                    if (newRow < 0 || newRow >= rowCount || newCol < 0 || newCol >= colCount)
                    {
                        break;
                    }

                    if (values[newRow][newCol] != currentValue)
                    {
                        break;
                    }

                    ++count;
                }

                if (count == 4)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    int rowCount;
    int colCount;
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rowCount >> colCount;

    std::vector<std::vector<int>> values(rowCount, std::vector<int>(colCount));
    std::cout << "Enter the values: \n";
    for (int row = 0; row < rowCount; ++row)
    {
        for (int col = 0; col < colCount; ++col)
        {
            std::cin >> values[row][col];
        }
    }

    if (isConsecutiveFour(values))
    {
        std::cout << "The array contains four consecutive numbers." << std::endl;
    }
    else
    {
        std::cout << "The array does not contain four consecutive numbers." << std::endl;
    }

    return 0;
}

