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
