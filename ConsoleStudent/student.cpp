#include "student.hpp"


string Student::GetStudentName() {
    return studentName;
}

string Student::GetStudentSurname() {
    return studentSurname;
}

int Student::GetStudentAge() {
    return studentAge;
}


void Student::SetName(string name) {
    studentName = name;
}

void Student::SetSurname(string surname) {
    studentSurname = surname;
}

void Student::SetAge(int age) {
    studentAge = age;
}
