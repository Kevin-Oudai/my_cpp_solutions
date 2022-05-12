// Exercise 5.34 - Revision of exercise 3.14 - Game: Prediction
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    // Variables
    int n1 = 0, n2 = 0, n3 = 0, g1, g2, g3;
    srand(time(0));

    // Input
    // Accept a guess
    std::cout << "Enter 3-digits separated by spaces: ";
    std::cin >> g1 >> g2 >> g3;

    // Process
    // Generate 3 non equal random digits
    while (n1 == n2 || n1 == n3 || n2 == n3)
    {
        n1 = rand() % 10;
        n2 = rand() % 10;
        n3 = rand() % 10;
    }

    std::cout << n1 << " " << n2 << " " << n3 << std::endl;

    // Output
    // Display for both digits matching
    if ((n1 == g1 && n2 == g2 && n3 == g3) ||
        (n1 == g2 && n2 == g3 && n3 == g1) ||
        (n1 == g3 && n2 == g1 && n3 == g2))
        std::cout << "100% match" << std::endl;
    // Display for one digit matching
    else if ((n1 == g1 || n2 == g2 || n3 == g3) ||
             (n1 == g2 || n2 == g3 || n3 == g1) ||
             (n1 == g3 || n2 == g1 || n3 == g2))
        std::cout << "at least 1 match" << std::endl;
    // Display for no matches
    else
        std::cout << "0% match" << std::endl;

    return 0;
}