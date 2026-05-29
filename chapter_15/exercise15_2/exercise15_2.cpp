#include <iostream>
#include "Faculty.h"
#include "Staff.h"
#include "Student.h"

void displayPerson(const Person &person)
{
    std::cout << person.toString() << std::endl;
}

int main()
{
    Person person("Kevin", "One Main Street", "555-0100", "kevin@example.com");
    Student student("Maya", "Two Main Street", "555-0101", "maya@example.com", "sophomore");
    Employee employee("Ari", "Three Main Street", "555-0102", "ari@example.com",
                      "A101", 52000, MyDate(2024, 6, 15));
    Faculty faculty("Dr. Lee", "Four Main Street", "555-0103", "lee@example.com",
                    "B202", 78000, MyDate(2020, 8, 20), "9-11 AM", "Professor");
    Staff staff("Jordan", "Five Main Street", "555-0104", "jordan@example.com",
                "C303", 45000, MyDate(2022, 3, 10), "Coordinator");

    displayPerson(person);
    displayPerson(student);
    displayPerson(employee);
    displayPerson(faculty);
    displayPerson(staff);

    return 0;
}
