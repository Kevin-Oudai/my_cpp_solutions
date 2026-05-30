#include <iostream>
#include <string>
#include "PermutationDisplayer.h"

int main()
{
    std::string text;
    std::cout << "Enter a string: ";
    std::cin >> text;

    PermutationDisplayer displayer;
    displayer.displayPermutation(text);

    return 0;
}
