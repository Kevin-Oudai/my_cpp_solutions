#ifndef SUDOKUSOLUTIONCOUNTER_H
#define SUDOKUSOLUTIONCOUNTER_H

class SudokuSolutionCounter
{
public:
    SudokuSolutionCounter();
    void readPuzzle();
    void solve();
    int getSolutionCount() const;

private:
    int grid[9][9];
    int solutionCount;
    int displayedSolutions;

    void search(int row, int column);
    bool isValid(int row, int column, int value) const;
    void printGrid() const;
};

#endif
