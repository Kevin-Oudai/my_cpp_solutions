#include <iostream>
#include "Course.h"

int main()
{
    Course course1("Data Structures", 10);
    Course course2("Database Systems", 15);

    course1.addStudent("Peter Jones");
    course1.addStudent("Brian Smith");
    course1.addStudent("Anne Kennedy");

    course2.addStudent("Peter Jones");
    course2.addStudent("Steve Smith");

    std::cout << "Number of students in course1: " << course1.getNumberOfStudents() << "\n";
    std::string *students = course1.getStudents();
    for (int i = 0; i < course1.getNumberOfStudents(); i++)
    {
        std::cout << students[i] << ", ";
    }
    std::cout << "\nNumber of students in course2: "
              << course2.getNumberOfStudents() << "\n";
    students = course2.getStudents();
    for (int i = 0; i < course2.getNumberOfStudents(); i++)
    {
        std::cout << students[i] << ", ";
    }

    return 0;
}