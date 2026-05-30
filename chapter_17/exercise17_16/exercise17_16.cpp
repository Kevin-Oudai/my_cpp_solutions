#include <iostream>
#include "HanoiSolver.h"

int main()
{
    int numberOfDisks;
    std::cout << "Enter number of disks: ";
    std::cin >> numberOfDisks;

    HanoiSolver solver;
    solver.moveDisks(numberOfDisks, 'A', 'B', 'C');
    std::cout << "Number of moves: " << solver.getMoveCount() << std::endl;

    return 0;
}
