#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cmath>
#include "ImprovedStack.h"

// Split an expression into numbers, operators, and parentheses
std::vector<std::string> split(const std::string &expression);

// Evaluate an expression and return the result
int evaluateExpression(const std::string &expression);

// Perform an operation
void processAnOperator(Stack<int> &operandStack, Stack<char> &operatorStack);

int main()
{
    std::string expression;
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    std::cout << expression << " = " << evaluateExpression(expression) << std::endl;

    return 0;
}

std::vector<std::string> split(const std::string &expression)
{
    std::vector<std::string> v;
    std::string numberString;

    for (unsigned i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
        {
            numberString.append(1, expression[i]);
        }
        else
        {
            if (numberString.size() > 0)
            {
                v.push_back(numberString);
                numberString.erase();
            }
            if (!isspace(expression[i]))
            {
                std::string s;
                s.append(1, expression[i]);
                v.push_back(s);
            }
        }
    }

    // Store the last numeric string
    if (numberString.size() > 0)
    {
        v.push_back(numberString);
    }

    return v;
}

// Evaluate an expression
int evaluateExpression(const std::string &expression)
{
    // Create operandStack to store operands
    Stack<int> operandStack;

    // Create operatorStack to store operators
    Stack<char> operatorStack;

    // Extract operands and operators
    std::vector<std::string> tokens = split(expression);

    // Phase 1: Scan tokens
    for (unsigned i = 0; i < tokens.size(); i++)
    {
        if (tokens[i][0] == '+' || tokens[i][0] == '-')
        {
            // Process all +, -, *, / in the top of the operator stack
            while (!operatorStack.empty() && (operatorStack.peek() == '+' || operatorStack.peek() == '-' || operatorStack.peek() == '*' || operatorStack.peek() == '/'))
            {
                processAnOperator(operandStack, operatorStack);
            }

            // Push the + or - operator into the operator stack
            operatorStack.push(tokens[i][0]);
        }
        else if (tokens[i][0] == '*' || tokens[i][0] == '/' || tokens[i][0] == '%')
        {
            // Process all *, / in the top of the operator stack
            while (!operatorStack.empty() && (operatorStack.peek() == '*' || operatorStack.peek() == '/' || operatorStack.peek() == '%'))
            {
                processAnOperator(operandStack, operatorStack);
            }

            // Push the * or / operator into the operator stack
            operatorStack.push(tokens[i][0]);
        }
        else if (tokens[i][0] == '^')
        {
            while (!operatorStack.empty() && (operatorStack.peek() == '^'))
            {
                processAnOperator(operandStack, operatorStack);
            }
            operatorStack.push(tokens[i][0]);
        }
        else if (tokens[i][0] == '(')
        {
            operatorStack.push('('); // Push '(' to stack
        }
        else if (tokens[i][0] == ')')
        {
            // Process all the operators in the stack until seeing '('
            while (operatorStack.peek() != '(')
            {
                processAnOperator(operandStack, operatorStack);
            }
            operatorStack.pop(); // Pop the '(' symbol from the stack
        }
        else
        {
            // An operand scanned. Push an operand to the stack as integer
            operandStack.push(atoi(tokens[i].c_str()));
        }
    }

    // Phase 2: process all the remaining operators in the stack
    while (!operatorStack.empty())
    {
        processAnOperator(operandStack, operatorStack);
    }

    // Return the result
    return operandStack.pop();
}

// Process one operator: Take an operator from operatorStack and
// apply it on the operands in the operandStack
void processAnOperator(
    Stack<int> &operandStack, Stack<char> &operatorStack)
{
    char op = operatorStack.pop();
    int op1 = operandStack.pop();
    int op2 = operandStack.pop();
    if (op == '+')
    {
        operandStack.push(op2 + op1);
    }
    else if (op == '-')
    {
        operandStack.push(op2 - op1);
    }
    else if (op == '*')
    {
        operandStack.push(op2 * op1);
    }
    else if (op == '/')
    {
        operandStack.push(op2 / op1);
    }
    else if (op == '%')
    {
        operandStack.push(op2 % op1);
    }
    else if (op == '^')
    {
        operandStack.push(std::pow(op2, op1));
    }
}