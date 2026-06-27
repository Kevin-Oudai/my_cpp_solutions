#include "../Graph.h"
#include <iostream>

int main()
{
    int cyclicEdges[][2] = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 0}, {0, 2}
    };
    int acyclicEdges[][2] = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}
    };

    Graph<int> cyclicGraph(3, cyclicEdges, 6);
    Graph<int> acyclicGraph(3, acyclicEdges, 4);

    std::cout << "First graph contains a cycle: " << (cyclicGraph.containsCyclic() ? "true" : "false") << std::endl;
    std::cout << "Second graph contains a cycle: " << (acyclicGraph.containsCyclic() ? "true" : "false") << std::endl;

    return 0;
}
