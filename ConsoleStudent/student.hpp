#include <iostream>
#include <string>
using namespace std;

class Student {

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
