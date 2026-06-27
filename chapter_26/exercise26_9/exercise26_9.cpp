#include "../ShortestPathWithAVL.h"
#include "../../chapter_25/WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    WeightedGraph<int> graph = createExercise25SampleGraph();
    ShortestPathTree tree = getShortestPathUsingAVL(graph, 0);

    std::cout << "AVL-assisted shortest path from 0 to 1: ";
    printPath(tree.getPath(1));
    std::cout << "Cost: " << tree.getCost(1) << std::endl;

    return 0;
}
