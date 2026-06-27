#include "../GraphFileUtilities.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 0}, {0, 2}, {2, 3}, {3, 2}
    };

    Graph<int> graph(4, edges, 8);
    std::vector<int> cycle = graph.getACycle();

    std::cout << "A cycle is ";
    printPath(cycle);

    return 0;
}
