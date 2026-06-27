#include "Course.h"
#include <stdexcept>

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
        throw std::runtime_error("Course capacity exceeded");
    }

    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const std::string &name)
{
    // Left as an exercise in the original Course class.
}

std::string *Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}
