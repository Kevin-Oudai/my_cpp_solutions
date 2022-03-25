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
    if (numberOfStudents + 1 > this->capacity)
    {
        std::string *newList = new std::string[this->capacity + 1];
        for (int i = 0; i < numberOfStudents; i++)
        {
            newList[i] = this->students[i];
        }
        this->students = newList;
    }

    students[numberOfStudents++] = name;
}

void Course::dropStudent(const std::string &name)
{
    std::string *newList = new std::string[this->capacity];
    int studentCount = 0;
    for (int i = 0; i < numberOfStudents; i++)
    {
        if (name == students[i])
        {
            continue;
        }
        else
        {
            newList[studentCount++] = this->students[i];
        }
    }
    this->students = newList;
    this->numberOfStudents = studentCount;
}

std::string *Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

void Course::clear()
{
    delete[] students;
    this->students = new std::string[capacity];
}

Course::Course(const Course &course)
{
    this->courseName = course.getCourseName();
    this->numberOfStudents = course.getNumberOfStudents();
    this->capacity = course.capacity;
    this->students = new std::string[this->capacity];
}