#include "SoftwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

//full constructor
SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], Degree degree)
	: Student(studentID, firstName, lastName, emailAddress, age, daysInCourse) {
	degreeProgram = degree;
}

Degree SoftwareStudent::getDegreeProgram() {
	return degreeProgram;
}

//printing 
void SoftwareStudent::print() {
	cout<< getID() << "\t"
		<< "First Name: "<< getFName() << "\t"
		<< "Last Name: " << getLName() << "\t"
		<< "Age: "       << getAge() << "\t"
		<< "Days in course: { " << getDays()[0] << ", " << getDays()[1] << ", " << getDays()[2] << " }" << "\t"
		<< "Degree program: Software"  << endl;
}