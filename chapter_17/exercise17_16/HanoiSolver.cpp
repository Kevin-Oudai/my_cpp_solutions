#include "HanoiSolver.h"
#include <iostream>

HanoiSolver::HanoiSolver()
{
    moveCount = 0;
}

void HanoiSolver::moveDisks(int n, char fromTower, char toTower, char auxTower)
{
    if (n == 1)
    {
        std::cout << "Move disk " << n << " from " << fromTower
                  << " to " << toTower << std::endl;
        moveCount++;
    }
    else
    {
        moveDisks(n - 1, fromTower, auxTower, toTower);
        std::cout << "Move disk " << n << " from " << fromTower
                  << " to " << toTower << std::endl;
        moveCount++;
        moveDisks(n - 1, auxTower, toTower, fromTower);
    }
}

int HanoiSolver::getMoveCount() const
{
    return moveCount;
}
