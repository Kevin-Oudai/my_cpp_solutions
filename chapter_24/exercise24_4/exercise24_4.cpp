#include "../Graph.h"
#include <iostream>

int main()
{
    int edges[][2] = {
        {0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}
    };

    Graph<int> graph(5, edges, 5);
    Tree tree = graph.dfsWithStack(0);

    std::cout << "DFS search order using a stack: ";
    std::vector<int> order = tree.getSearchOrders();
    for (int i = 0; i < static_cast<int>(order.size()); i++)
        std::cout << order[i] << " ";
    std::cout << std::endl;

    return 0;
}
