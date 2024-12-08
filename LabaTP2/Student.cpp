#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student()
{
    cout << "Student default constructor called\n" << endl;
}

Student::Student(string fio, int groupNum, string sub)
{
    FIO = fio;
   groupNumber = groupNum;
    Subject = sub;
    cout << "Student constructor with parameters called\n" << endl;
}

Student::Student(const Student& other)
{
    FIO = other.FIO;
    groupNumber = other.groupNumber;
    Subject = other.Subject;
    cout << "Student copy-constructor called\n" << endl;
}

Student::~Student()
{
    cout << "Student default destructor called\n" << endl;
}

string Student::getFIO()
{
    return FIO;
}

void Student::setFIO(string fio)
{
    FIO = fio;
}

int Student::getgroupNumber()
{
    return groupNumber;
}

void Student::setgroupNumber(int groupNum)
{
    groupNumber = groupNum;
}

string Student::getSubj()
{
    return Subject;
}

void Student::setSubj(string sub)
{
    Subject = sub;
}

ostream& operator<<(ostream& os, const Student& obj)
{
    os << "FIO: " << obj.FIO << endl;
    os << "Group number: " << obj.groupNumber << endl;
    os << "Subjects and marks: " << obj.Subject << endl;
    return os;
}

istream& operator>>(istream& is, Student& obj) {
    cout << "Enter FIO: \n";
    is >> obj.FIO;
    cout << "Enter group number: \n";
    is >> obj.groupNumber;
    cout << "Enter Subjects and their marks: \n";
    is >> obj.Subject;

    return is;
}