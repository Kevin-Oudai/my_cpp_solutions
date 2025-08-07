// Codex Prompt: Exercise 12.19 – 24-Point Card Game (Modular Build)
//
// Build a complete C++ program in a single folder named `exercise12_19/` that solves the 24-point card game.
// The program should draw 4 random cards from a standard 52-card deck (excluding jokers), display their values and names,
// and prompt the user to enter an expression that evaluates to 24 using those 4 card values.
//
// If the user enters `0`, the program should show a valid solution if one exists.
// The program should use clean modular files with headers and reusable logic.
//
// The following files must be created:
//
// ─────────────────────────────────────────────
// evaluator.h / evaluator.cpp
// ─────────────────────────────────────────────
// - Contains a function `double evaluate(const std::string& expression)`
// - Supports space-separated infix expressions
// - Handles operators: + - * / % ^
// - Uses correct precedence: ^ > * / % > + -
// - Assumes valid expressions (no error handling required yet)
//
// ─────────────────────────────────────────────
// solver.h / solver.cpp
// ─────────────────────────────────────────────
// - Class: `TwentyFourSolver`
//   - Constructor: `TwentyFourSolver(const std::vector<int>& numbers)`
//   - Method: `bool hasSolution()`
//   - Method: `std::string getFirstSolution()`
// - Internally generates:
//   - All 4! permutations of input numbers
//   - All 64 combinations of 3 operators (+ - * /)
//   - 5 expression groupings using string concatenation
// - Calls `evaluate()` from evaluator to check if any expression evaluates to 24
//
// ─────────────────────────────────────────────
// main.cpp
// ─────────────────────────────────────────────
// - Contains the 24-point game:
//   - Randomly select 4 cards from a 52-card deck
//   - Map Ace = 1, Jack = 11, Queen = 12, King = 13
//   - Display card names (e.g. “King of Hearts”)
//   - Prompt user: “Enter an expression: ” or enter `0` to give up
//   - If not 0:
//       - Use `evaluate()` to compute result
//       - Confirm that only the given card values are used, once each
//       - If correct and equals 24 → print “Congratulations! You got it!”
//       - Else → print “Incorrect.”
//   - If 0 entered:
//       - Use `TwentyFourSolver` to get and print a correct expression
//       - If no solution exists, print “No 24 points”
//
// - The program should compile and run using:
//   g++ evaluator.cpp solver.cpp main.cpp -o runme && ./runme
//
// - Use `std::vector`, `std::stack`, `std::string`, `srand`, `rand`, etc. from STL
// - Stick to procedural or light OOP design (one class only)
// - Keep all files in one folder with matching includes (`#include "evaluator.h"`, etc.)
// - Keep code readable and structured for learning purposes

#include "evaluator.h"
#include "solver.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    const int NUMBER_OF_CARDS = 52;
    std::vector<int> deck(NUMBER_OF_CARDS);
    for (int i = 0; i < NUMBER_OF_CARDS; ++i) {
        deck[i] = i;
    }

    std::srand(std::time(0));
    for (int i = 0; i < NUMBER_OF_CARDS; ++i) {
        int j = i + std::rand() % (NUMBER_OF_CARDS - i);
        std::swap(deck[i], deck[j]);
    }

    std::string suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
    std::string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    std::vector<int> numbers(4);
    std::cout << "The cards are:\n";
    for (int i = 0; i < 4; ++i) {
        int card = deck[i];
        std::string suit = suits[card / 13];
        std::string rank = ranks[card % 13];
        numbers[i] = card % 13 + 1;
        std::cout << rank << " of " << suit << " (" << numbers[i] << ")\n";
    }

    std::cout << "Enter an expression: ";
    std::string expression;
    std::getline(std::cin, expression);

    if (expression == "0") {
        TwentyFourSolver solver(numbers);
        if (solver.hasSolution()) {
            std::cout << solver.getFirstSolution() << std::endl;
        } else {
            std::cout << "No 24 points" << std::endl;
        }
    } else {
        std::istringstream iss(expression);
        std::vector<int> remaining = numbers;
        std::string token;
        bool valid = true;
        while (iss >> token) {
            if (!token.empty() && std::isdigit(token[0])) {
                int val = std::stoi(token);
                auto it = std::find(remaining.begin(), remaining.end(), val);
                if (it != remaining.end()) {
                    remaining.erase(it);
                } else {
                    valid = false;
                    break;
                }
            }
        }
        if (!valid || !remaining.empty()) {
            std::cout << "Incorrect." << std::endl;
        } else {
            double result = evaluate(expression);
            if (std::fabs(result - 24.0) < 1e-6) {
                std::cout << "Congratulations! You got it!" << std::endl;
            } else {
                std::cout << "Incorrect." << std::endl;
            }
        }
    }
    return 0;
}
