#include <iostream>
#include "CourseWithCustomCopyConstructor.h"

int main()
{
    Course course1("C++ Programming", 10);
    Course course2(course1);

    course1.addStudent("Peter Pan");
    course2.addStudent("Lisa Ma");

    std::cout << "students in course1: "
              << course1.getStudents()[0] << std::endl;
    std::cout << "students in course2: "
              << course2.getStudents()[0] << std::endl;

    return 0;
}