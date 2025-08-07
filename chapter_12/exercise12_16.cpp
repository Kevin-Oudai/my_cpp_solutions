#include <iostream>
#include "ImprovedStack.h"
#include <string>
#include <vector>

int main()
{
    Stack<int> items;
    std::string input;
    std::cout << "Enter the expression to evaluate: ";
    while (std::cin >> input)
    {
        if (input == "+")
        {
            int item2 = items.pop();
            int item1 = items.pop();
            items.push(item1 + item2);
        }
        else if (input == "-")
        {
            int item2 = items.pop();
            int item1 = items.pop();
            items.push(item1 - item2);
        }
        else if (input == "*")
        {
            int item2 = items.pop();
            int item1 = items.pop();
            items.push(item1 * item2);
        }
        else if (input == "/")
        {
            int item2 = items.pop();
            int item1 = items.pop();
            items.push(item1 / item2);
        }
        else
        {
            items.push(atoi(input.c_str()));
        }
    }
    std::cout << "Result: " << items.peek() << std::endl;
    return 0;
}