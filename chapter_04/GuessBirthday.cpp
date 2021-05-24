// Listing 4.4 - GuessBirthday.cpp

#include <iostream>

int main()
{
    int day = 0; // Day to be determined
    char answer;

    // Prompt the user for Set1
    std::cout << "Is your birthday in Set1?" << std::endl;
    std::cout << " 1  3  5  7\n"
              << " 9 11 13 15\n"
              << "17 19 21 23\n"
              << "25 27 29 31" << std::endl;
    std::cout << "Enter N/n for No and Y/y for Yes: ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        day += 1;
    }

    // Prompt the user for Set2
    std::cout << "\nIs your birthday in Set2?" << std::endl;
    std::cout << " 2  3  6  7\n"
              << "10 11 14 15\n"
              << "18 19 22 23\n"
              << "26 27 30 31" << std::endl;
    std::cout << "Enter N/n for No and Y/y for Yes: ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        day += 2;
    }

    // Prompt the user for Set3
    std::cout << "\nIs your birthday in Set3?" << std::endl;
    std::cout << " 4  5  6  7\n"
              << "12 13 14 15\n"
              << "20 21 22 23\n"
              << "28 29 30 31" << std::endl;
    std::cout << "Enter N/n for No and Y/y for Yes: ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        day += 4;
    }

    // Prompt the user for Set4
    std::cout << "\nIs your birthday in Set4?" << std::endl;
    std::cout << " 8  9 10 11\n"
              << "12 13 14 15\n"
              << "24 25 26 27\n"
              << "28 29 30 31" << std::endl;
    std::cout << "Enter N/n for No and Y/y for Yes: ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        day += 8;
    }

    // Prompt the user for Set5
    std::cout << "\nIs your birthday in Set5?" << std::endl;
    std::cout << "16 17 18 19\n"
              << "20 21 22 23\n"
              << "24 25 26 27\n"
              << "28 29 30 31" << std::endl;
    std::cout << "Enter N/n for No and Y/y for Yes: ";
    std::cin >> answer;

    if (answer == 'Y' || answer == 'y')
    {
        day += 16;
    }

    std::cout << "Your birthday is " << day << std::endl;

    return 0;
}