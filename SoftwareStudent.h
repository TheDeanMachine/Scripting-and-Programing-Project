#pragma once
#include "Student.h"
#include <iostream>

class SoftwareStudent : public Student {
public:

	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree);
	
	Degree getDegreeProgram();
	void print();

private:
	Degree degreeProgram;
};