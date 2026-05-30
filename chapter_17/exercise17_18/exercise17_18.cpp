#include <iostream>
#include "SudokuSolver.h"

int main()
{
    SudokuSolver solver;
    solver.readPuzzle();

    if (solver.solve())
    {
        std::cout << "The solution is:" << std::endl;
        solver.printGrid();
    }
    else
    {
        std::cout << "No solution" << std::endl;
    }

    return 0;
}
