#ifndef FAN_H
#define FAN_H

class Fan
{
public:
    Fan();
    int getSpeed();
    bool getState();
    double getRadius();
    void setSpeed(int newSpeed);
    void setState(bool state);
    void setRadius(double newRadius);

private:
    int speed;
    bool on;
    double radius;
};
#endif