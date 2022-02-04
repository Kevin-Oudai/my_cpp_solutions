#include <iostream>
#include "EvenNumber.h"

int main()
{
    EvenNumber e(16);
    std::cout << "e: " << e.getValue() << std::endl;
    std::cout << "Next even: " << e.getNext() << std::endl;
    std::cout << "Previous even: " << e.getPrevious() << std::endl;
    return 0;
}