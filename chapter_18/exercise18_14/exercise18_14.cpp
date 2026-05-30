#include <iostream>
#include "SudokuSolutionCounter.h"

int main()
{
    SudokuSolutionCounter solver;
    solver.readPuzzle();
    solver.solve();

    std::cout << "The total number of solutions is "
        << solver.getSolutionCount() << std::endl;

    return 0;
}
