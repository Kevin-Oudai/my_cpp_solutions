#include "SudokuMultipleSolver.h"
#include <iostream>

SudokuMultipleSolver::SudokuMultipleSolver()
{
    solutionCount = 0;
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void SudokuMultipleSolver::readPuzzle()
{
    std::cout << "Enter a Sudoku puzzle row by row, using 0 for blanks:" << std::endl;
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            std::cin >> grid[row][column];
        }
    }
}

void SudokuMultipleSolver::displayAllSolutions()
{
    solutionCount = 0;
    search(0, 0);
}

int SudokuMultipleSolver::getSolutionCount() const
{
    return solutionCount;
}

void SudokuMultipleSolver::search(int row, int column)
{
    if (row == 9)
    {
        solutionCount++;
        std::cout << "Solution " << solutionCount << ":" << std::endl;
        printGrid();
        std::cout << std::endl;
        return;
    }

    int nextRow = column == 8 ? row + 1 : row;
    int nextColumn = column == 8 ? 0 : column + 1;

    if (grid[row][column] != 0)
    {
        search(nextRow, nextColumn);
        return;
    }

    for (int value = 1; value <= 9; value++)
    {
        if (isValid(row, column, value))
        {
            grid[row][column] = value;
            search(nextRow, nextColumn);
            grid[row][column] = 0;
        }
    }
}

bool SudokuMultipleSolver::isValid(int row, int column, int value) const
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == value || grid[i][column] == value)
        {
            return false;
        }
    }

    int boxRow = row / 3 * 3;
    int boxColumn = column / 3 * 3;
    for (int r = boxRow; r < boxRow + 3; r++)
    {
        for (int c = boxColumn; c < boxColumn + 3; c++)
        {
            if (grid[r][c] == value)
            {
                return false;
            }
        }
    }
    return true;
}

void SudokuMultipleSolver::printGrid() const
{
    for (int row = 0; row < 9; row++)
    {
        for (int column = 0; column < 9; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}
