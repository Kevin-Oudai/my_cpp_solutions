#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream input("scores.txt");

    // Read data
    std::string firstName;
    char mi;
    std::string lastName;
    int score;
    input >> firstName >> mi >> lastName >> score;
    std::cout << firstName << " " << mi << " " << lastName << " " << score << std::endl;
    input >> firstName >> mi >> lastName >> score;
    std::cout << firstName << " " << mi << " " << lastName << " " << score << std::endl;

    input.close();
    std::cout << "Done" << std::endl;

    return 0;
}