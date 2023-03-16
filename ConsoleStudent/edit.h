#pragma once
#include <string>
using namespace std;
class edit{

private:
    string studentName;
    string studentSurname;
    int studentAge;

public:
    string GetStudentName();
    string GetStudentSurname();
    int GetStudentAge();

    void SetName(string name);
    void SetSurname(string surname);
    void SetAge(int age);

};

