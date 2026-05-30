#include <iostream>
#include "EightQueensSolver.h"

int main()
{
    int displayLimit;
    std::cout << "Enter number of solutions to display (0 for all): ";
    std::cin >> displayLimit;

    EightQueensSolver solver;
    solver.solve(displayLimit);

    std::cout << "Total solutions: " << solver.getSolutionCount() << std::endl;

    return 0;
}
