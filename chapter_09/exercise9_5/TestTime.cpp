#include <iostream>
#include "Time.h"

void displayTime(Time t)
{
    std::cout << t.getHours() << ":" << t.getMinutes() << ":" << t.getSecond() << std::endl;
}

int main()
{
    Time t1;
    Time t2(555550);
    displayTime(t1);
    displayTime(t2);
    return 0;
}