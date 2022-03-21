#include <iostream>
#include "Course.h"

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