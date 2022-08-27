#include <iostream>
#include <stack>
#include <string>

int main()
{
    char input;
    bool valid = true;
    std::stack<char> stack;
    while (std::cin >> input)
    {
        if (input == '[' || input == '{' || input == '(')
        {
            stack.push(input);
        }
        else if ((input == ']' && stack.top() == '[') || (input == '}' && stack.top() == '{') || (input == ')' && stack.top() == '('))
        {
            stack.pop();
        }
    }
    if (stack.empty())
    {
        std::cout << "valid" << std::endl;
    }
    else
    {
        std::cout << "invalid" << std::endl;
    }

    return 0;
}