#include <iostream>
#include <fstream>

int main()
{
    std::ofstream output;

    // Create a file
    output.open("scores.txt");

    // Write two lines
    output << "John"
           << " "
           << "T"
           << " "
           << "Smith"
           << " " << 90 << std::endl;
    output << "Eric"
           << " "
           << "K"
           << " "
           << "Jones"
           << " " << 85 << std::endl;

    output.close();

    std::cout << "Done" << std::endl;
    return 0;
}