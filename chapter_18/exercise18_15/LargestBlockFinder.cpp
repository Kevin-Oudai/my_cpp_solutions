#include "LargestBlockFinder.h"

BlockResult::BlockResult()
{
    row = 0;
    column = 0;
    size = 0;
}

BlockResult::BlockResult(int rowValue, int columnValue, int sizeValue)
{
    row = rowValue;
    column = columnValue;
    size = sizeValue;
}

int BlockResult::getRow() const
{
    return row;
}

int BlockResult::getColumn() const
{
    return column;
}

int BlockResult::getSize() const
{
    return size;
}

int LargestBlockFinder::minimum(int first, int second, int third) const
{
    int result = first;
    if (second < result)
        result = second;
    if (third < result)
        result = third;
    return result;
}

BlockResult LargestBlockFinder::findLargestBlock(const std::vector<std::vector<int> >& matrix) const
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return BlockResult();

    int rows = static_cast<int>(matrix.size());
    int columns = static_cast<int>(matrix[0].size());
    std::vector<std::vector<int> > sizes(rows, std::vector<int>(columns, 0));

    int bestSize = 0;
    int bestRow = 0;
    int bestColumn = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix[row][column] == 1)
            {
                if (row == 0 || column == 0)
                    sizes[row][column] = 1;
                else
                    sizes[row][column] = 1 + minimum(sizes[row - 1][column],
                        sizes[row][column - 1], sizes[row - 1][column - 1]);

                if (sizes[row][column] > bestSize)
                {
                    bestSize = sizes[row][column];
                    bestRow = row - bestSize + 1;
                    bestColumn = column - bestSize + 1;
                }
            }
        }
    }

    return BlockResult(bestRow, bestColumn, bestSize);
}
