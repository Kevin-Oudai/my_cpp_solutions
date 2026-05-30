#include <iostream>
#include <vector>
#include "LargestBlockFinder.h"

int main()
{
    std::cout << "Enter the number of rows for the matrix: ";
    int n;
    std::cin >> n;

    std::vector<std::vector<int> > matrix(n, std::vector<int>(n, 0));
    std::cout << "Enter the matrix row by row:" << std::endl;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
            std::cin >> matrix[row][column];
    }

    LargestBlockFinder finder;
    BlockResult result = finder.findLargestBlock(matrix);

    if (result.getSize() == 0)
    {
        std::cout << "No square submatrix of 1s found." << std::endl;
    }
    else
    {
        std::cout << "The maximum square submatrix is at ("
            << result.getRow() << ", " << result.getColumn()
            << ") with size " << result.getSize() << std::endl;
    }

    return 0;
}
