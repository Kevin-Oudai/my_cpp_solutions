#include "../GraphFileUtilities.h"
#include <iostream>

int main()
{
    writeExercise24_2File("Exercise24_2.txt");
    std::cout << "Created Exercise24_2.txt" << std::endl;
    Graph<int> graph = readGraphFromFile("Exercise24_2.txt");
    std::cout << "The number of vertices is " << graph.getSize() << std::endl;
    graph.printEdges();

    return 0;
}
