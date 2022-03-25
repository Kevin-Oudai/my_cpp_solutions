#include <iostream>
#include <string>
#include "Course.h"

int main()
{
    Course course1("Mathematics", 2);
    course1.addStudent("Kevin Oudai");
    course1.addStudent("Venita Ganpat");
    course1.addStudent("Athena Oudai");
    course1.dropStudent("Venita Ganpat");
    std::string *group = course1.getStudents();
    for (int i = 0; i < course1.getNumberOfStudents(); i++)
    {
        std::cout << "Name: " << group[i] << std::endl;
    }

    return 0;
}