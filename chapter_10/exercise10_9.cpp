#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

std::string stateInfo[50][2] = {
    {"Alabama", "Montgomery"},
    {"Alaska", "Juneau"},
    {"Arizona", "Phoenix"},
    {"Arkansas", "Little Rock"},
    {"California", "Sacramento"},
    {"Colorado", "Denver"},
    {"Connecticut", "Hartford"},
    {"Delaware", "Dover"},
    {"Florida", "Tallahassee"},
    {"Georgia", "Atlanta"},
    {"Hawaii", "Honolulu"},
    {"Idaho", "Boise"},
    {"Illinois", "Springfield"},
    {"Indiana", "Indianapolis"},
    {"Iowa", "Des Moines"},
    {"Kansas", "Topeka"},
    {"Kentucky", "Frankfort"},
    {"Louisiana", "Baton Rouge"},
    {"Maine", "Augusta"},
    {"Maryland", "Annapolis"},
    {"Massachusetts", "Boston"},
    {"Michigan", "Lansing"},
    {"Minnesota", "Saint Paul"},
    {"Mississippi", "Jackson"},
    {"Missouri", "Jefferson City"},
    {"Montana", "Helena"},
    {"Nebraska", "Lincoln"},
    {"Nevada", "Carson City"},
    {"New Hampshire", "Concord"},
    {"New Jersey", "Trenton"},
    {"New Mexico", "Santa Fe"},
    {"New York", "Albany"},
    {"North Carolina", "Raleigh"},
    {"North Dakota", "Bismarck"},
    {"Ohio", "Columbus"},
    {"Oklahoma", "Oklahoma City"},
    {"Oregon", "Salem"},
    {"Pennsylvania", "Harrisburg"},
    {"Rhode Island", "Providence"},
    {"South Carolina", "Columbia"},
    {"South Dakota", "Pierre"},
    {"Tennessee", "Nashville"},
    {"Texas", "Austin"},
    {"Utah", "Salt Lake City"},
    {"Vermont", "Montpelier"},
    {"Virginia", "Richmond"},
    {"Washington", "Olympia"},
    {"West Virginia", "Charleston"},
    {"Wisconsin", "Madison"},
    {"Wyoming", "Cheyenne"},
};

int main()
{
    int count = 0, correct = 0, item;

    srand(time(0));

    std::string answer;
    while (count < 10)
    {
        item = rand() % 50;
        std::cout << "What is the capital of " << stateInfo[item][0] << "?";
        std::getline(std::cin, answer);
        if (stateInfo[item][1].compare(answer) == 0)
        {
            std::cout << "Your answer is correct." << std::endl;
            correct++;
        }
        else
        {
            std::cout << "The capital of " << stateInfo[item][0] << " is " << stateInfo[item][1] << "." << std::endl;
        }
        count++;
    }
    std::cout << "You got " << correct << " answers correct." << std::endl;

    return 0;
}