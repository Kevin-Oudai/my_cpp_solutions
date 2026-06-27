#include "../WeightedGraphFileUtilities.h"
#include <iostream>

int main()
{
    WeightedGraph<int> graph = createExercise25SampleGraph();
    MST tree = graph.getMinimumSpanningTreeAlternative(0);

    std::cout << "Alternative Prim MST total weight is " << tree.getTotalWeight() << std::endl;
    tree.printTree();

    return 0;
}
