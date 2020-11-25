#pragma once
#include "Degree.h"
#include <iostream>

//Days in course array size
const int ARRAY_SIZE = 3;

class Student {  //base class 
public:

	//constructor and destructor
	Student();
	Student(string ID, string fName, string lName, string eMail, int numYears, int courseDays[]); 
	~Student();

	//setter
	void setID(string studentID);
	void setFName(string firstName);
	void setLName(string lastName);
	void setEMail(string emailAddress);
	void setAge(int age);
	void setDays(int daysInCourse[]);

	//getter
	string getID();
	string getFName();
	string getLName();
	string getEmail();
	int getAge();
	int* getDays();
	virtual Degree getDegreeProgram() = 0;

	//virtual print function
	virtual void print() = 0;

private:
	//attribute
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[ARRAY_SIZE];
	//Degree type is unknown
};