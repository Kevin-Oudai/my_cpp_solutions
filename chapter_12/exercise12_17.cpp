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

