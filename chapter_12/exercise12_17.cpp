// Codex Prompt: exercise12_17.cpp – 24 Game Solver
//
// Write a C++ program named `exercise12_17.cpp` that solves the "24 game":
// Given 4 numbers (integers between 1 and 13), determine if it's possible to insert the operations +, -, *, /
// and parentheses between them to make an expression that evaluates exactly to 24.
//
// Requirements:
// 1. Prompt the user to enter 4 integers between 1 and 13.
//    - Validate the input and store it in a vector.
//
// 2. Generate all permutations of the 4 numbers using `std::next_permutation()`.
//    - You can use `std::vector<int>` for storing each permutation.
//
// 3. Generate all 64 combinations of 3 operators from the set: +, -, *, /
//    - Store each operator combination in a `std::vector<char>`.
//
// 4. For each permutation of numbers and operator combination, try the 5 possible groupings using parentheses.
//    - Each grouping should be written using basic string concatenation and `std::to_string()`
//    - Example of one grouping:
//         ((a op1 b) op2 c) op3 d
//         a op1 (b op2 (c op3 d))
//         and so on (5 total groupings)
//
// 5. Use `EvaluateExpression.cpp` from the same folder (chapter_12) to evaluate each built expression string.
//    - If the result is 24 (you can use a tolerance like `abs(result - 24) < 1e-6`), print the expression and stop.
//    - Otherwise, keep trying all combinations.
//
// 6. If no expression results in 24, print "No solution found."
//
// Use a simple, procedural structure — do not use classes.
// You may write helper functions for things like generating permutations, operator combos, or building expressions if it makes the code clearer.
// Make sure the program compiles and runs using `g++ -std=c++17`.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

// Include EvaluateExpression.cpp but rename its main function to avoid conflicts
#define main evalMain
#include "EvaluateExpression.cpp"
#undef main

int main()
{
    std::vector<int> numbers;
    std::cout << "Enter 4 integers between 1 and 13: ";

    int value;
    while (numbers.size() < 4)
    {
        if (!(std::cin >> value) || value < 1 || value > 13)
        {
            std::cout << "Invalid input. Enter an integer between 1 and 13: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        numbers.push_back(value);
    }

    std::sort(numbers.begin(), numbers.end());

    // Generate all operator combinations
    std::vector<std::vector<char>> opCombos;
    const char ops[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 4; ++k)
                opCombos.push_back({ops[i], ops[j], ops[k]});

    do
    {
        for (const auto &opSet : opCombos)
        {
            int a = numbers[0];
            int b = numbers[1];
            int c = numbers[2];
            int d = numbers[3];

            std::vector<std::string> expressions = {
                "((" + std::to_string(a) + " " + opSet[0] + " " + std::to_string(b) + ") " + opSet[1] + " " + std::to_string(c) + ") " + opSet[2] + " " + std::to_string(d),
                "(" + std::to_string(a) + " " + opSet[0] + " (" + std::to_string(b) + " " + opSet[1] + " " + std::to_string(c) + ")) " + opSet[2] + " " + std::to_string(d),
                std::to_string(a) + " " + opSet[0] + " ((" + std::to_string(b) + " " + opSet[1] + " " + std::to_string(c) + ") " + opSet[2] + " " + std::to_string(d) + ")",
                std::to_string(a) + " " + opSet[0] + " (" + std::to_string(b) + " " + opSet[1] + " (" + std::to_string(c) + " " + opSet[2] + " " + std::to_string(d) + "))",
                "(" + std::to_string(a) + " " + opSet[0] + " " + std::to_string(b) + ") " + opSet[1] + " (" + std::to_string(c) + " " + opSet[2] + " " + std::to_string(d) + ")"};

            for (const auto &expr : expressions)
            {
                int result = evaluateExpression(expr);
                if (std::fabs(result - 24) < 1e-6)
                {
                    std::cout << expr << " = 24" << std::endl;
                    return 0;
                }
            }
        }
    } while (std::next_permutation(numbers.begin(), numbers.end()));

    std::cout << "No solution found." << std::endl;
    return 0;
}

