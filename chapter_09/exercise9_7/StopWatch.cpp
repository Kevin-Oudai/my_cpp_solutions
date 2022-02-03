#include <ctime>
#include "StopWatch.h"

StopWatch::StopWatch()
{
    startTime = time(0);
}

void StopWatch::start()
{
    startTime = time(0);
}

void StopWatch::stop()
{
    endTime = time(0);
}

int StopWatch::getStartTime()
{
    return startTime;
}

int StopWatch::getEndTime()
{
    return endTime;
}

int StopWatch::getElapsedTime()
{
    return (endTime - startTime) * 1000;
}