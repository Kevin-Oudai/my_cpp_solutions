#ifndef BMI_H
#define BMI_H

#include <string>

class BMI
{
public:
    BMI(const std::string &newName, int newAge, double newWeight, double newHeight);
    BMI(const std::string &newName, double newWeight, double newHeight);
    double getBMI() const;
    std::string getStatus() const;
    std::string getName() const;
    int getAge() const;
    double getWeight() const;
    double getHeight() const;

private:
    std::string name;
    int age;
    double weight;
    double height;
};

#endif