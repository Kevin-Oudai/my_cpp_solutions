/*
Codex Task: Exercise 12.21 — Brute‑force 24‑game ratio

Goal
Create a single file named `exercise12_21.cpp` that brute‑forces ALL 4‑card hands from a 52‑card deck
and computes the ratio: noSolutionCount / solutionCount.

Constraints
- Use ONLY basic headers: <iostream>, <vector>.
- No maps/sets/tuples/algorithms beyond simple loops.
- Use camelCase descriptive variables.
- Reuse my solver via:  #include "solver.h"  (class TwentyFourSolver with ctor(vector<int>) and bool hasSolution()).
- At the top of the output file, include this prompt as a block comment.

Requirements
1) Build a deck: ranks 1..13, four copies each (suits ignored other than multiplicity).
2) Enumerate every 4‑card hand with four nested loops i<j<k<l (total 52C4 = 270,725).
3) For each hand: vector<int> handValues{ deck[i], deck[j], deck[k], deck[l] }.
4) TwentyFourSolver solver(handValues); if (solver.hasSolution()) ++solutionCount; else ++noSolutionCount.
5) After loops, print:
     Total hands (should be 270725)
     Solutions
     No solutions
     Ratio (no/yes) as double
6) Keep the programme simple and self‑contained.

Deliverable
- Full source of `exercise12_21.cpp` that compiles with:
    g++ -std=c++17 solver.cpp exercise12_21.cpp -O2 -o runme && ./runme
*/

#include <iostream>
#include <vector>

#include "solver.h"

int main() {
    std::vector<int> deck;
    deck.reserve(52);
    for (int rank = 1; rank <= 13; ++rank) {
        for (int copy = 0; copy < 4; ++copy) {
            deck.push_back(rank);
        }
    }

    int solutionCount = 0;
    int noSolutionCount = 0;

    for (int i = 0; i < 52 - 3; ++i) {
        for (int j = i + 1; j < 52 - 2; ++j) {
            for (int k = j + 1; k < 52 - 1; ++k) {
                for (int l = k + 1; l < 52; ++l) {
                    std::vector<int> handValues{deck[i], deck[j], deck[k], deck[l]};
                    TwentyFourSolver solver(handValues);
                    if (solver.hasSolution()) {
                        ++solutionCount;
                    } else {
                        ++noSolutionCount;
                    }
                }
            }
        }
    }

    int totalHands = solutionCount + noSolutionCount;
    double ratio = static_cast<double>(noSolutionCount) / static_cast<double>(solutionCount);

    std::cout << "Total hands (should be 270725): " << totalHands << std::endl;
    std::cout << "Solutions: " << solutionCount << std::endl;
    std::cout << "No solutions: " << noSolutionCount << std::endl;
    std::cout << "Ratio (no/yes): " << ratio << std::endl;

    return 0;
}

