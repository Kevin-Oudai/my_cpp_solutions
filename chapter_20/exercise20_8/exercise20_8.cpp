#include "../DoublyLinkedList.h"
#include <iostream>
#include <string>

template<typename T>
void printList(const DoublyLinkedList<T>& list)
{
    for (DoublyIterator<T> iterator = list.begin(); iterator != list.end(); iterator++)
        std::cout << *iterator << " ";
    std::cout << std::endl;
}

int main()
{
    DoublyLinkedList<std::string> list;
    list.add("America");
    list.add("Canada");
    list.add("Russia");
    list.add("France");
    list.add(2, "Germany");

    std::cout << "After insertion: ";
    printList(list);

    std::cout << "Removed at index 2: " << list.removeAt(2) << std::endl;
    std::cout << "After removal: ";
    printList(list);

    DoublyIterator<std::string> iterator = list.begin();
    iterator++;
    std::cout << "Iterator after ++: " << *iterator << std::endl;
    iterator--;
    std::cout << "Iterator after --: " << *iterator << std::endl;

    return 0;
}
