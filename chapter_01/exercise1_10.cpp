#include <iostream>

int main()
{
    double KILOMETER_TO_MILE = 1.6;
    double km_distance = 14.0;
    double time = 91.0 / 120;
    double mile_distance = km_distance / KILOMETER_TO_MILE;
    double speed = mile_distance / time;
    std::cout << "The speed is: " << speed << " miles per hour." << std::endl;
    return 0;
}