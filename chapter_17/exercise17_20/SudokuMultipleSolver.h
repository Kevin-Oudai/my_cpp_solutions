#ifndef SUDOKUMULTIPLESOLVER_H
#define SUDOKUMULTIPLESOLVER_H

class SudokuMultipleSolver
{
public:
    SudokuMultipleSolver();

    void readPuzzle();
    void displayAllSolutions();
    int getSolutionCount() const;

private:
    int grid[9][9];
    int solutionCount;

    void search(int row, int column);
    bool isValid(int row, int column, int value) const;
    void printGrid() const;
};

#endif
