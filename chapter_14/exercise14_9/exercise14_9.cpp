#include <iostream>
#include "EvenNumber.h"

int main()
{
    EvenNumber number(16);

    std::cout << "number: " << number.getValue() << std::endl;
    std::cout << "next even: " << number.getNext() << std::endl;
    std::cout << "previous even: " << number.getPrevious() << std::endl;

    std::cout << "++number: " << (++number).getValue() << std::endl;
    std::cout << "number++: " << (number++).getValue() << std::endl;
    std::cout << "after number++: " << number.getValue() << std::endl;

    std::cout << "--number: " << (--number).getValue() << std::endl;
    std::cout << "number--: " << (number--).getValue() << std::endl;
    std::cout << "after number--: " << number.getValue() << std::endl;

    return 0;
}
