#include "../TailModels.h"
#include <iostream>

int main()
{
    TailModel model(3, true);
    int start = 0;
    std::vector<int> path = model.getShortestPath(start);

    std::cout << "Shortest path length with diagonal flips: " << static_cast<int>(path.size()) - 1 << std::endl;
    std::cout << "Start: ";
    model.printNode(start);
    std::cout << std::endl << "Target: ";
    model.printNode(model.getTarget());
    std::cout << std::endl;

    return 0;
}
