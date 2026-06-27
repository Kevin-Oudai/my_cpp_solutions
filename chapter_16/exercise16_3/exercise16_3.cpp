#include "Course.h"
#include <iostream>
#include <stdexcept>

int main()
{
    Course course("C++", 2);

    try
    {
        course.addStudent("Peter Jones");
        course.addStudent("Brian Smith");
        course.addStudent("Anne Kennedy");
    }
    catch (const std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "Number of students in course " << course.getCourseName()
              << ": " << course.getNumberOfStudents() << std::endl;

    std::string *students = course.getStudents();
    for (int i = 0; i < course.getNumberOfStudents(); i++)
    {
        std::cout << students[i] << std::endl;
    }

    return 0;
}
