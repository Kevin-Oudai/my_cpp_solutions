// Listing 4.9 SimpleFileOutput.cpp

#include <iostream>
#include <fstream>

int main()
{
    std::ofstream output;

    // Create a file
    output.open("numbers.txt");

    // Write numbers
    output << 95 << " " << 56 << " " << 34;

    // Close File
    output.close();

    std::cout << "Done" << std::endl;

    return 0;
}