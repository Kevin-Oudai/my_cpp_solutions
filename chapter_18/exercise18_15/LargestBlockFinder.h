#ifndef LARGESTBLOCKFINDER_H
#define LARGESTBLOCKFINDER_H

#include <vector>

class BlockResult
{
public:
    BlockResult();
    BlockResult(int row, int column, int size);
    int getRow() const;
    int getColumn() const;
    int getSize() const;

private:
    int row;
    int column;
    int size;
};

class LargestBlockFinder
{
public:
    BlockResult findLargestBlock(const std::vector<std::vector<int> >& matrix) const;

private:
    int minimum(int first, int second, int third) const;
};

#endif
