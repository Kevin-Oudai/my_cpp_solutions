#include "../LinkedList.h"
#include <iostream>
#include <string>

template<typename T>
void printList(const LinkedList<T>& list)
{
    Iterator<T> current = list.begin();

    while (current != list.end())
    {
        std::cout << *current << " ";
        current++;
    }

    std::cout << std::endl;
}

int main()
{
    LinkedList<std::string> list;
    list.add("Beijing");
    list.add("Tokyo");
    list.add("New York");
    list.add("London");
    list.add("Paris");

    LinkedList<std::string> list2;
    list2.add("Beijing");
    list2.add("Shanghai");
    list2.add("Paris");
    list2.add("Berlin");
    list2.add("Rome");

    LinkedList<std::string> list1(list);
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);

    list1.addAll(list2);
    std::cout << "list is : ";
    printList(list);
    std::cout << "After list1.addAll(list2), list1 is ";
    printList(list1);

    list1 = list;
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    list1.removeAll(list2);
    std::cout << "After list1.removeAll(list2), list1 is ";
    printList(list1);

    list1 = list;
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    list1.retainAll(list2);
    std::cout << "After list1.retainAll(list2), list1 is ";
    printList(list1);

    list1 = list;
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    list1 = list1 + list2;
    std::cout << "After list1 = list1 + list2, list1 is ";
    printList(list1);

    list1 = list;
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    list1 = list1 - list2;
    std::cout << "After list1 = list1 - list2, list1 is ";
    printList(list1);

    list1 = list;
    std::cout << "list1: ";
    printList(list1);
    std::cout << "list2: ";
    printList(list2);
    list1 = list1 ^ list2;
    std::cout << "After list1 = list1 ^ list2, list1 is ";
    printList(list1);

    list1 = list;
    std::cout << list1[0] << std::endl;
    list1[0] = "Paris";
    std::cout << list1[0] << std::endl;

    return 0;
}
