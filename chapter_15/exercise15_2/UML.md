# Exercise 15.2 UML

```text
Person
-------------------------------
- name: string
- address: string
- phoneNumber: string
- emailAddress: string
-------------------------------
+ toString() const: string

Student extends Person
-------------------------------
- classStatus: string
-------------------------------
+ toString() const: string

Employee extends Person
-------------------------------
- office: string
- salary: double
- dateHired: MyDate
-------------------------------
+ toString() const: string

Faculty extends Employee
-------------------------------
- officeHours: string
- rank: string
-------------------------------
+ toString() const: string

Staff extends Employee
-------------------------------
- title: string
-------------------------------
+ toString() const: string

MyDate
-------------------------------
- year: int
- month: int
- day: int
-------------------------------
+ toString() const: string
```
