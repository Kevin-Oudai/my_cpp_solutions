#include <iostream>

int main()
{
    double miles = 24.0;
    double timeInHours = 1.0 + 40.0 / 60 + 35.0 / (60 * 60);
    double distanceInKilometers = miles * 1.6;
    double speed = distanceInKilometers / timeInHours;
    std::cout << "The speed of runner was: " << speed << " km/h." << std::endl;
    return 0;
}