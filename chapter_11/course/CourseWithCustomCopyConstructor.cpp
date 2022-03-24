#include <iostream>
#include "CourseWithCustomCopyConstructor.h"

Course::Course(const std::string &courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new std::string[capacity];
}

Course::~Course()
{
    delete[] students;
}

std::string Course::getCourseName() const
{
    return courseName;
}

void Course::addStudent(const std::string &name)
{
    if (numberOfStudents >= capacity)
    {
        std::cout << "The maximum size of array exceeded" << std::endl;
        std::cout << "Program terminates now" << std::endl;
        exit(0);
    }
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const std::string &name)
{
    // Left as an exercise
}

std::string *Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

Course::Course(const Course &course) // Copy constructor
{
    courseName = course.courseName;
    numberOfStudents = course.numberOfStudents;
    capacity = course.capacity;
    students = new std::string[capacity];
}
