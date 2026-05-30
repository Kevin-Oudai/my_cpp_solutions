#include <iostream>
#include <string>
#include "ReverseDisplayer.h"

int main()
{
    std::string text;
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    ReverseDisplayer displayer;
    displayer.reverseDisplay(text);
    std::cout << std::endl;

    return 0;
}
