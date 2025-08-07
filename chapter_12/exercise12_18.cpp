// Codex Prompt: exercise12_18.cpp – Convert Infix to Postfix
//
// Write a C++ program that defines the function:
//     std::string infixToPostfix(const std::string& expression);
// The function converts an infix arithmetic expression (space-separated tokens)
// into an equivalent postfix (Reverse Polish Notation) expression.
//
// Assume all tokens (numbers, operators, parentheses) are separated by single spaces.
// Use a stack to hold operators and parentheses.
// Operators: +, -, *, /
// Precedence: * and / have higher precedence than + and -
// All operators are left-associative.
//
// Suggested helper functions:
// - bool isOperator(const std::string& token)
// - int precedence(const std::string& op)
// - bool isLeftAssociative(const std::string& op)
// - std::vector<std::string> tokenize(const std::string& expression)
//
// Use only std::string, std::vector<std::string>, and std::stack<std::string>.
// Do not use regular expressions or third-party libraries.
//
// The final function should be self-contained, and able to be compiled and tested using C++17.
// A simple main() is provided for minimal testing.

#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool isOperator(const std::string& token)
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int precedence(const std::string& op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    return 0;
}

bool isLeftAssociative(const std::string& op)
{
    return op == "+" || op == "-" || op == "*" || op == "/";
}

std::vector<std::string> tokenize(const std::string& expression)
{
    std::vector<std::string> tokens;
    std::string current;
    for (char ch : expression)
    {
        if (ch == ' ')
        {
            if (!current.empty())
            {
                tokens.push_back(current);
                current.clear();
            }
        }
        else
        {
            current += ch;
        }
    }
    if (!current.empty())
        tokens.push_back(current);
    return tokens;
}

std::string infixToPostfix(const std::string& expression)
{
    std::vector<std::string> tokens = tokenize(expression);
    std::stack<std::string> opStack;
    std::vector<std::string> output;

    for (const auto& token : tokens)
    {
        if (isOperator(token))
        {
            while (!opStack.empty() && isOperator(opStack.top()) &&
                   (precedence(opStack.top()) > precedence(token) ||
                    (precedence(opStack.top()) == precedence(token) && isLeftAssociative(token))))
            {
                output.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }
        else if (token == "(")
        {
            opStack.push(token);
        }
        else if (token == ")")
        {
            while (!opStack.empty() && opStack.top() != "(")
            {
                output.push_back(opStack.top());
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == "(")
                opStack.pop();
        }
        else
        {
            output.push_back(token);
        }
    }

    while (!opStack.empty())
    {
        output.push_back(opStack.top());
        opStack.pop();
    }

    std::string result;
    for (std::size_t i = 0; i < output.size(); ++i)
    {
        if (i > 0)
            result += ' ';
        result += output[i];
    }

    return result;
}

int main()
{
    std::string expression;
    std::cout << "Enter infix expression: ";
    std::getline(std::cin, expression);
    std::cout << infixToPostfix(expression) << std::endl;
    return 0;
}

