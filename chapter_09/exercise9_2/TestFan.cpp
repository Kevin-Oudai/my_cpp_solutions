#include <iostream>
#include "Fan.h"

void displayFan(Fan fan)
{
    std::cout << "Speed: " << fan.getSpeed() << std::endl;
    std::cout << "Radius: " << fan.getRadius() << std::endl;
    std::cout << "State: " << (fan.getState() ? "ON" : "OFF") << std::endl;
}
int main()
{
    Fan fan1;
    Fan fan2;

    fan1.setSpeed(3);
    fan1.setRadius(10);
    fan1.setState(true);
    displayFan(fan1);

    fan2.setSpeed(2);
    fan2.setRadius(5);
    displayFan(fan2);
    return 0;
}