#ifndef STOPWATCH_H
#define STOPWATCH_H

class StopWatch
{
public:
    StopWatch();
    void start();
    void stop();
    int getStartTime();
    int getEndTime();
    int getElapsedTime();

private:
    int startTime, endTime;
};
#endif