#include "../WeightedNineTailModel.h"
#include <iostream>

int main()
{
    WeightedNineTailModel model(3);
    std::vector<int> path = model.getShortestPath(0);

    std::cout << "Modified weighted nine-tail path length: " << static_cast<int>(path.size()) - 1 << std::endl;
    std::cout << "Modified weighted nine-tail cost: " << model.getCost(0) << std::endl;

    return 0;
}
