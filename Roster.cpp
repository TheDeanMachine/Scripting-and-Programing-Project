#include "Roster.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


Roster::Roster() {
}

Roster::~Roster() {

    for (int i = 0; i < ROSTER_SIZE; i++) {
        if (classRosterArray[i] != nullptr) {
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
            }
        }
    }


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    
    int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };

    if (degree == NETWORK) {
        classRosterArray[index++] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
    }
    else if (degree == SECURITY) {
        classRosterArray[index++] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
    }
    else if (degree == SOFTWARE) {
         classRosterArray[index++] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degree);
    }    
}

void Roster::remove(string studentID) {

    for (int i = 0; i < ROSTER_SIZE; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getID() == studentID) { //will only remove the student id passed into the function
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                return;
            }
        }
    }
    cout << studentID << "\t" << "Such a student with this ID was not found.";
}
    
void Roster::printAll() {
    for (int i = 0; i < ROSTER_SIZE; i++)
        if (classRosterArray[i] != nullptr) { //revision added for ptint all test
            classRosterArray[i]->print();
        }
}

void Roster::printAverageDaysInCourse(string studentID) {
    
    for (int i = 0; i < ROSTER_SIZE; i++) {
       if (classRosterArray[i]->getID() == studentID) {
            int daysInCourse = classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2];
            cout << studentID << " Average days in course: " << daysInCourse / ARRAY_SIZE << endl;
        }
    } 
}

void Roster::printInvalidEmails() {

    for (int i = 0; i < ROSTER_SIZE; i++) {
        string emailAdress = classRosterArray[i]->getEmail();
        bool hasChar1 = false;
        bool hasChar2 = false;
        bool hasChar3 = false;

        if (emailAdress.find('.') != string::npos ) {
                hasChar1 = true;
        }
        if (emailAdress.find('@') != string::npos) {
                hasChar2 = true;
        }
        if (emailAdress.find(' ') != string::npos) {
                hasChar3 = true;
        }

        if ((hasChar1 == false) || (hasChar2 == false) || (hasChar3 == true)) {
                cout << emailAdress << "\t Not a valid emailAddress" << endl;
        }
    }
}          

void Roster::printByDegreeProgram(Degree degree) {

    for (int i = 0; i < ROSTER_SIZE; ++i) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getDegreeProgram() == degree) {
                classRosterArray[i]->print();
            }
        }
    }
}

const string studentData[] = {
      "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Vadym,Feskin,vadym.feskin@gmail.com,30,35,40,45,SOFTWARE"
};

 void Roster::parseInData(const string array[]) {

    for (int i = 0; i < ROSTER_SIZE; i++) { 

        string userinfo = studentData[i]; 
        istringstream inSS(userinfo);
        string token;

        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        string ageStr;
        string daysInCourse1Str;
        string daysInCourse2Str;
        string daysInCourse3Str;
        string degreeStr;

        getline(inSS, studentID, ',');
        getline(inSS, firstName, ',');
        getline(inSS, lastName, ',');
        getline(inSS, emailAddress, ',');
        getline(inSS, ageStr, ',');
        getline(inSS, daysInCourse1Str, ',');
        getline(inSS, daysInCourse2Str, ',');
        getline(inSS, daysInCourse3Str, ',');
        getline(inSS, degreeStr, ',');

        int age = 0;
        int daysInCourse1 = 0;
        int daysInCourse2 = 0;
        int daysInCourse3 = 0;
        Degree degree = SOFTWARE; //default value

        age = stoi(ageStr.substr(0, ageStr.size()));
        daysInCourse1 = stoi(daysInCourse1Str.substr(0, daysInCourse1Str.size()));
        daysInCourse2 = stoi(daysInCourse2Str.substr(0, daysInCourse2Str.size()));
        daysInCourse3 = stoi(daysInCourse3Str.substr(0, daysInCourse3Str.size()));
        
        if (degreeStr == "SECURITY") {
            degree = SECURITY;
        }

        if (degreeStr == "NETWORK") {
            degree = NETWORK;
        }

        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
    } 
}

 Student** Roster::getClassRosterArray() {
     return classRosterArray;
 }

int main() {
    cout << "Course title: Scripting and Programming C867, Programming language: C++, Student ID: #001300492, Name: Vadym Feskin." << endl; // revision task f1
    cout << endl;

   Roster classRoster;
   classRoster.parseInData(studentData);
   
   classRoster.printAll();
   cout << endl;

   classRoster.printInvalidEmails();
   cout << endl;

   for (int i = 0; i < ROSTER_SIZE; i++) {
       classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getID());
   } 
   cout << endl;

   classRoster.printByDegreeProgram(SOFTWARE);
   cout << endl;
   //deleting
   classRoster.remove("A3");
   cout << endl;
 
   classRoster.remove("A3");
   cout << endl;

   classRoster.~Roster();
	
   return 0;
}