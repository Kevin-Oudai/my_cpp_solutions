#include "solver.h"
#include "evaluator.h"

#include <algorithm>
#include <array>
#include <cmath>

TwentyFourSolver::TwentyFourSolver(const std::vector<int> &numbers)
    : nums(numbers), computed(false), solvable(false) {}

bool TwentyFourSolver::hasSolution() {
    if (!computed)
        compute();
    return solvable;
}

std::string TwentyFourSolver::getFirstSolution() {
    if (!computed)
        compute();
    return solution;
}

void TwentyFourSolver::compute() {
    computed = true;
    const char opsList[4] = {'+', '-', '*', '/'};
    std::array<int, 4> perm = {nums[0], nums[1], nums[2], nums[3]};
    std::sort(perm.begin(), perm.end());
    const double TARGET = 24.0;

    do {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    char op1 = opsList[i];
                    char op2 = opsList[j];
                    char op3 = opsList[k];

                    std::string a = std::to_string(perm[0]);
                    std::string b = std::to_string(perm[1]);
                    std::string c = std::to_string(perm[2]);
                    std::string d = std::to_string(perm[3]);

                    std::string expr = "( ( " + a + " " + op1 + " " + b + " ) " + op2 + " " + c + " ) " + op3 + " " + d;
                    double result = evaluate(expr);
                    if (std::fabs(result - TARGET) < 1e-6) {
                        solution = expr;
                        solvable = true;
                        return;
                    }

                    expr = "( " + a + " " + op1 + " ( " + b + " " + op2 + " " + c + " ) ) " + op3 + " " + d;
                    result = evaluate(expr);
                    if (std::fabs(result - TARGET) < 1e-6) {
                        solution = expr;
                        solvable = true;
                        return;
                    }

                    expr = a + " " + op1 + " ( ( " + b + " " + op2 + " " + c + " ) " + op3 + " " + d + " )";
                    result = evaluate(expr);
                    if (std::fabs(result - TARGET) < 1e-6) {
                        solution = expr;
                        solvable = true;
                        return;
                    }

                    expr = a + " " + op1 + " ( " + b + " " + op2 + " ( " + c + " " + op3 + " " + d + " ) )";
                    result = evaluate(expr);
                    if (std::fabs(result - TARGET) < 1e-6) {
                        solution = expr;
                        solvable = true;
                        return;
                    }

                    expr = "( " + a + " " + op1 + " " + b + " ) " + op2 + " ( " + c + " " + op3 + " " + d + " )";
                    result = evaluate(expr);
                    if (std::fabs(result - TARGET) < 1e-6) {
                        solution = expr;
                        solvable = true;
                        return;
                    }
                }
            }
        }
    } while (std::next_permutation(perm.begin(), perm.end()));
}
