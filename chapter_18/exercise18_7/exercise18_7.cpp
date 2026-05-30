#include <iostream>
#include "PrimePerformance.h"

int main()
{
    std::cout << "Use exercise limits? Enter 1 for yes, 0 for quick test: ";
    int choice;
    std::cin >> choice;

    PrimePerformance performance;
    performance.displayTable(choice == 1);

    return 0;
}
