#include "SecurityStudent.h"
#include <iostream>
#include <string>
using namespace std;

//full constructor
SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	: Student(studentID, firstName, lastName, emailAddress, age, daysInCourse) {
	degreeProgram = degree;
}

Degree SecurityStudent::getDegreeProgram() {
	return degreeProgram;
}

//printing 
void SecurityStudent::print() {
	cout<< getID() << "\t"
		<< "First Name: "<< getFName() << "\t"
		<< "Last Name: " << getLName() << "\t"
		<< "Age: "            << getAge() << "\t"
		<< "Days in course: { " << getDays()[0] << ", " << getDays()[1] << ", " << getDays()[2] << " }" << "\t"
		<< "Degree program: Security" << endl;
}