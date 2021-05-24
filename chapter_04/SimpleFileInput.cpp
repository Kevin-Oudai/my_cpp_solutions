// Listing 4.10 - SimpleFileInput.cpp

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream input;

    // Open a file
    input.open("numbers.txt");

    int score1, score2, score3;

    // Read data
    input >> score1;
    input >> score2;
    input >> score3;

    std::cout << "Total score is " << score1 + score2 + score3 << std::endl;

    // Close file
    input.close();

    std::cout << "Done" << std::endl;

    return 0;
}