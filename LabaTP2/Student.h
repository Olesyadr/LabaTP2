#ifndef LABATP2_STUDENT_H
#define LABATP2_STUDENT_H
#include <iostream>

class Student
{
private:
    std::string FIO;
    int groupNumber;
    std::string Subject;
public:
   Student();
   Student(std::string fio, int groupNum, std::string sub);
   Student(const Student& other);
    ~Student();
    std::string getFIO();
    void setFIO(std::string fio);
    int getgroupNumber();
    void setgroupNumber(int groupNum);
    std::string getSubj();
    void setSubj(std::string sub);
    friend std::ostream& operator<<(std::ostream& os, const Student& obj);
    friend std::istream& operator>>(std::istream& is,Student& obj);
};


#endif