#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, std::string> capitals;
    capitals["Alabama"] = "Montgomery";
    capitals["Alaska"] = "Juneau";
    capitals["Arizona"] = "Phoenix";
    capitals["Arkansas"] = "Little Rock";
    capitals["California"] = "Sacramento";
    capitals["Colorado"] = "Denver";
    capitals["Connecticut"] = "Hartford";
    capitals["Delaware"] = "Dover";
    capitals["Florida"] = "Tallahassee";
    capitals["Georgia"] = "Atlanta";
    capitals["Hawaii"] = "Honolulu";
    capitals["Idaho"] = "Boise";
    capitals["Illinois"] = "Springfield";
    capitals["Indiana"] = "Indianapolis";
    capitals["Iowa"] = "Des Moines";
    capitals["Kansas"] = "Topeka";
    capitals["Kentucky"] = "Frankfort";
    capitals["Louisiana"] = "Baton Rouge";
    capitals["Maine"] = "Augusta";
    capitals["Maryland"] = "Annapolis";
    capitals["Massachusetts"] = "Boston";
    capitals["Michigan"] = "Lansing";
    capitals["Minnesota"] = "Saint Paul";
    capitals["Mississippi"] = "Jackson";
    capitals["Missouri"] = "Jefferson City";
    capitals["Montana"] = "Helena";
    capitals["Nebraska"] = "Lincoln";
    capitals["Nevada"] = "Carson City";
    capitals["New Hampshire"] = "Concord";
    capitals["New Jersey"] = "Trenton";
    capitals["New Mexico"] = "Santa Fe";
    capitals["New York"] = "Albany";
    capitals["North Carolina"] = "Raleigh";
    capitals["North Dakota"] = "Bismarck";
    capitals["Ohio"] = "Columbus";
    capitals["Oklahoma"] = "Oklahoma City";
    capitals["Oregon"] = "Salem";
    capitals["Pennsylvania"] = "Harrisburg";
    capitals["Rhode Island"] = "Providence";
    capitals["South Carolina"] = "Columbia";
    capitals["South Dakota"] = "Pierre";
    capitals["Tennessee"] = "Nashville";
    capitals["Texas"] = "Austin";
    capitals["Utah"] = "Salt Lake City";
    capitals["Vermont"] = "Montpelier";
    capitals["Virginia"] = "Richmond";
    capitals["Washington"] = "Olympia";
    capitals["West Virginia"] = "Charleston";
    capitals["Wisconsin"] = "Madison";
    capitals["Wyoming"] = "Cheyenne";

    std::string state;
    std::cout << "Enter a state: ";
    std::getline(std::cin, state);

    if (state.empty())
        state = "California";

    if (capitals.find(state) == capitals.end())
        std::cout << "The state was not found" << std::endl;
    else
        std::cout << "The capital of " << state << " is " << capitals[state] << std::endl;

    return 0;
}
