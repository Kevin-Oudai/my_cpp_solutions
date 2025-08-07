#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include <vector>

class TwentyFourSolver {
public:
    explicit TwentyFourSolver(const std::vector<int> &numbers);
    bool hasSolution();
    std::string getFirstSolution();

private:
    std::vector<int> nums;
    bool computed;
    bool solvable;
    std::string solution;

    void compute();
};

#endif // SOLVER_H
