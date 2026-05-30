#include <iostream>
#include "SudokuMultipleSolver.h"

int main()
{
    SudokuMultipleSolver solver;
    solver.readPuzzle();
    solver.displayAllSolutions();

    if (solver.getSolutionCount() == 0)
    {
        std::cout << "No solution" << std::endl;
    }
    else
    {
        std::cout << "Total solutions: " << solver.getSolutionCount() << std::endl;
    }

    return 0;
}
