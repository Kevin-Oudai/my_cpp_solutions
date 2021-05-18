#include <iostream>

int main()
{
    int num;
    std::cout << "Enter and integer: ";
    std::cin >> num;

    bool divFive = num % 5 == 0;
    bool divSix = num % 6 == 0;

    std::cout << "Is " << num << " divisible by 5 and 6?"
              << ((divFive && divSix) ? " true" : " false")
              << std::endl;

    std::cout << "Is " << num << " divisible by 5 or 6?"
              << ((divFive || divSix) ? " true" : " false") << std::endl;

    std::cout << "Is " << num << " divisible by 5 or 6, but not both?"
              << (((divFive && !divSix) || (!divFive && divSix)) ? " true" : " false")
              << std::endl;

    return 0;
}