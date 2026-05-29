#include "evaluator.h"

#include <cmath>
#include <sstream>
#include <stack>
#include <vector>

namespace {
int precedence(char op) {
    switch (op) {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

double applyOp(double a, double b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return std::fmod(a, b);
    case '^':
        return std::pow(a, b);
    default:
        return 0;
    }
}
} // namespace

double evaluate(const std::string &expression) {
    std::istringstream iss(expression);
    std::vector<std::string> tokens;
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    std::stack<double> values;
    std::stack<char> ops;

    for (const auto &tk : tokens) {
        if (tk == "(") {
            ops.push('(');
        } else if (tk == ")") {
            while (!ops.empty() && ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOp(a, b, op));
            }
            if (!ops.empty())
                ops.pop();
        } else if (tk.size() == 1 && isOperator(tk[0])) {
            char op = tk[0];
            while (!ops.empty() && ops.top() != '(' &&
                   ((op != '^' && precedence(ops.top()) >= precedence(op)) ||
                    (op == '^' && precedence(ops.top()) > precedence(op)))) {
                char topOp = ops.top();
                ops.pop();
                double b = values.top();
                values.pop();
                double a = values.top();
                values.pop();
                values.push(applyOp(a, b, topOp));
            }
            ops.push(op);
        } else {
            values.push(std::stod(tk));
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        double b = values.top();
        values.pop();
        double a = values.top();
        values.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}
