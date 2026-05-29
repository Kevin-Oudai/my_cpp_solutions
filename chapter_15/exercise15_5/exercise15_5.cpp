#include <iostream>
#include <string>
#include "GenericStack.h"

int main()
{
    GenericStack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "Integer stack size: " << numbers.getSize() << std::endl;
    std::cout << "Integer stack top: " << numbers.peek() << std::endl;
    std::cout << "Integer stack pop: " << numbers.pop() << std::endl;
    std::cout << "Integer stack size after pop: " << numbers.getSize() << std::endl;

    GenericStack<std::string> words;
    words.push("inheritance");
    words.push("polymorphism");

    std::cout << "String stack top: " << words.peek() << std::endl;
    std::cout << "String stack pop: " << words.pop() << std::endl;

    return 0;
}
