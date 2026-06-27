#include "../GraphFileUtilities.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {1, 0}, {1, 3}, {3, 1}, {0, 2}, {2, 0}, {2, 4}, {4, 2}, {4, 5}, {5, 4}
    };

    Graph<int> graph(6, edges, 10);
    std::vector<int> path = graph.getPath(0, 5);

    std::cout << "Path from 0 to 5: ";
    printPath(path);

    return 0;
}
