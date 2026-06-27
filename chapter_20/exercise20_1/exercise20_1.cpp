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

    list.remove("Russia");
    std::cout << "After removing Russia: ";
    printList(list);

    list.remove("America");
    std::cout << "After removing America: ";
    printList(list);

    list.remove("France");
    std::cout << "After removing France: ";
    printList(list);

    return 0;
}
