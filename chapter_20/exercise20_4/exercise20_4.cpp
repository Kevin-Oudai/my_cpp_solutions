#include "../LinkedList.h"
#include <iostream>
#include <string>

template<typename T>
void printList(const LinkedList<T>& list)
{
    for (Iterator<T> iterator = list.begin(); iterator != list.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;
}

int main()
{
    LinkedList<std::string> list;
    list.add("America");
    list.add("Canada");
    list.add("Russia");
    list.add("France");

    std::cout << "Original list: ";
    printList(list);

    std::string oldValue = list.set(2, "Germany");
    std::cout << "Replaced value: " << oldValue << std::endl;
    std::cout << "After set: ";
    printList(list);

    return 0;
}
