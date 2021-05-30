// Exercise 4.18 - Random String
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    std::string randomString = "";

    srand(time(0));

    randomString += static_cast<char>('a' + (rand() % 26));
    randomString += static_cast<char>('a' + (rand() % 26));
    randomString += static_cast<char>('a' + (rand() % 26));
    randomString += static_cast<char>('a' + (rand() % 26));
    randomString += static_cast<char>('a' + (rand() % 26));
    randomString += static_cast<char>('a' + (rand() % 26));

    std::cout << "The random string is: " << randomString << std::endl;
    return 0;
}