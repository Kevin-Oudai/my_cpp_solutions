#include "../InheritedQueue.h"
#include <iostream>
#include <string>

int main()
{
    Queue<std::string> queue;
    queue.enqueue("New York");
    queue.enqueue("Boston");
    queue.enqueue("Denver");

    while (queue.getSize() > 0)
        std::cout << queue.dequeue() << " ";
    std::cout << std::endl;

    return 0;
}
