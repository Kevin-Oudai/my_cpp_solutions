#include <iostream>
#include "CourseWithCustomCopyConstructor.h"

Course::Course(const std::string &courseName, int capacity)
{
    this->courseName = courseName;
}

Course::~Course()
{
    students.clear();
}

std::string Course::getCourseName() const
{
    return courseName;
}

void Course::addStudent(const std::string &name)
{
    students.push_back(name);
}

void Course::dropStudent(const std::string &name)
{
    // Left as an exercise
}

std::vector<std::string> Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return students.size();
}

Course::Course(const Course &course) // Copy constructor
{
    courseName = course.courseName;
    students = course.getStudents();
}
