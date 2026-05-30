#include "EightQueensSolver.h"
#include <cmath>
#include <iostream>

EightQueensSolver::EightQueensSolver()
{
    solutionCount = 0;
    displayLimit = 0;
    for (int i = 0; i < 8; i++)
    {
        queens[i] = -1;
    }
}

void EightQueensSolver::solve(int displayLimit)
{
    this->displayLimit = displayLimit;
    solutionCount = 0;
    search(0);
}

int EightQueensSolver::getSolutionCount() const
{
    return solutionCount;
}

void EightQueensSolver::search(int row)
{
    if (row == 8)
    {
        solutionCount++;
        if (displayLimit == 0 || solutionCount <= displayLimit)
        {
            printBoard();
        }
        return;
    }

    for (int column = 0; column < 8; column++)
    {
        if (isSafe(row, column))
        {
            queens[row] = column;
            search(row + 1);
            queens[row] = -1;
        }
    }
}

bool EightQueensSolver::isSafe(int row, int column) const
{
    for (int i = 0; i < row; i++)
    {
        if (queens[i] == column || std::abs(queens[i] - column) == row - i)
        {
            return false;
        }
    }
    return true;
}

void EightQueensSolver::printBoard() const
{
    std::cout << "Solution " << solutionCount << std::endl;
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            std::cout << (queens[row] == column ? "Q " : ". ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
