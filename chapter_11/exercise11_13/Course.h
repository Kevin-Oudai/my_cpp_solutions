#ifndef COURSE_H
#define COURSE_H
#include <string>

class Course
{
public:
    Course(const std::string &courseName, int capacity);
    ~Course();
    Course(const Course &);
    std::string getCourseName() const;
    void addStudent(const std::string &name);
    void dropStudent(const std::string &name);
    std::string *getStudents() const;
    int getNumberOfStudents() const;
    void clear();

private:
    std::string courseName;
    std::string *students;
    int numberOfStudents;
    int capacity;
};
#endif