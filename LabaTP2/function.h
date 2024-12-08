#ifndef LABATP2_FUNCTIONS_H
#define LABATP2_FUNCTIONS_H
#include "Student.h"
#include "Exception.h"

void Menu()
{
    std::cout << "\nMenu:\n"
        "1. Add Student\n"
        "2. Add Student by index\n"
        "3. Remove Student\n"
        "4. Print Students\n"
        "5. Edit Student\n"
        "6. Sort Student\n"
        "7. Check Student\n"
        "8. Exit\n"
        "Enter a command:\n";
}

void addFlight(Student*& studs, int& cnt)
{
    Student stud;
    std::cin >> stud;
    cnt++;
    Student* temp = new Student[cnt];
    for (int i = 0; i < cnt - 1; i++)
    {
        Student copy_stud(studs[i]);
        temp[i] = copy_stud;
    }
    delete[] studs;
    temp[cnt - 1] = stud;
    studs = temp;

}

void addStudentByIndex(Student*& studs, int& cnt)
{
    int index;
    if (!cnt)
        throw Exception("There is no place for the object!\n");
    std::cout << "Enter index from 0 to " << cnt - 1 << ":\n";
    std::cin >> index;
    if (0 > index >= cnt)
        throw Exception("It is impossible to insert into this position!\n");
    Student stud;
    std::cin >> stud;
    studs[index] = stud;
}

void removeStudent(Student*& studs, int& cnt)
{
    if (!cnt)
        throw Exception("There is no place for the object!\n");
    int index;
    std::cout << "Enter stud index to remove:\n";
    std::cin >> index;
    if (0 > index || index >= cnt)
        throw Exception("There is no such stud!\n");
    Student* temp = new Student[cnt - 1];
    for (int i = 0; i < index; i++)
    {
        temp[i] = studs[i];
    }
    for (int i = index + 1; i < cnt; i++)
    {
        temp[i - 1] = studs[i];
    }
    delete[] studs;
    studs = temp;
    cnt--;
}

void printStudent(Student*& studs, int& cnt)
{
    if (!cnt)
        throw Exception("The list of studs is empty!\n");
    std::cout << "There are " << cnt << " studs:\n";
    for (int i = 0; i < cnt; i++) {
        std::cout << i + 1 << ". \n" << studs[i] << "\n";
    }
}

void editStudent(Student*& studs, int& cnt)
{
    if (!cnt)
        throw Exception("The list of studs is empty!\n");
    int index;
    std::cout << "Enter stud index to edit from 0 to " << cnt - 1 << ":\n";
    std::cin >> index;
    if (0 > index || index >= cnt)
        throw Exception("There is no such stud!\n");
    Student stud;
    std::cin >> stud;
    studs[index] = stud;
}



#endif