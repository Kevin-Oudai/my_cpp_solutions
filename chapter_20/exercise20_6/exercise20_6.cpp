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
    list.add("Tokyo");
    list.add("Beijing");
    list.add("Paris");
    list.add("London");
    list.add("New York");

    std::cout << "Original list: ";
    printList(list);

    list.sort();
    std::cout << "Sorted list: ";
    printList(list);

    return 0;
}
