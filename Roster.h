#pragma once
#include "Student.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include <iostream>

//size of roster
const int ROSTER_SIZE = 5;

class Roster {
public:
    //constructor and destructor
    Roster();
    ~Roster();

    void add(string studentID, string firstName,  string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree );
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degree);
    void parseInData(const string array[]);
    Student** getClassRosterArray();

private:
    Student* classRosterArray[ROSTER_SIZE] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    int index = 0;
};
  