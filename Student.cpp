#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

// default constructor
Student::Student() {
}

//full constructor
Student::Student( string ID, string fName, string lName, string eMail, int numYears, int courseDays[] ) {
	studentID = ID;
	firstName = fName;
	lastName = lName;
	emailAddress = eMail;
	age = numYears;
	for (int i = 0; i < ARRAY_SIZE; i++) 
		daysInCourse[i] = courseDays[i];
	//Degree type is unknown
}

//destructor
Student::~Student() { 
}


//setter
void Student::setID(string setID) {
	studentID = setID;
}
	
void Student::setFName(string setFName) {
	firstName = setFName;
} 
	
void Student::setLName(string setLName) {
	lastName = setLName;
}

void Student::setEMail(string setEMail) {
	emailAddress = setEMail;
}
	
void Student::setAge(int setAge) {
	age = setAge;
}
	
void Student::setDays(int courseDays[]) {
	for (int i = 0; i < ARRAY_SIZE; i++)
	daysInCourse[i] = courseDays[i];
}


//getter	
string Student::getID() {
	return studentID;
}

string Student::getFName() {
	return firstName;
}

string Student::getLName() {
	return lastName;
}

string Student::getEmail() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDays() {
	return daysInCourse;
}