#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>

class Course
{
public:
    Course(const std::string &courseName, int capacity);
    ~Course();              // Destructor
    Course(const Course &); // Copy constructor
    std::string getCourseName() const;
    void addStudent(const std::string &name);
    void dropStudent(const std::string &name);
    std::vector<std::string> getStudents() const;
    int getNumberOfStudents() const;

private:
    std::string courseName;
    std::vector<std::string> students;
};
#endif