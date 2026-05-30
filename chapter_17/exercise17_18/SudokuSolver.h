#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

class SudokuSolver
{
public:
    SudokuSolver();

    void readPuzzle();
    bool solve();
    void printGrid() const;

private:
    int grid[9][9];

    bool solve(int row, int column);
    bool isValid(int row, int column, int value) const;
};

#endif
