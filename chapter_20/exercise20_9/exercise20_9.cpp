#include "../InheritedStack.h"
#include <iostream>
#include <string>

int main()
{
    Stack<std::string> stack;
    stack.push("Georgia");
    stack.push("Indiana");
    stack.push("Oklahoma");

    std::cout << stack.pop() << std::endl;
    std::cout << "Stack's size is " << stack.getSize() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;

    return 0;
}
