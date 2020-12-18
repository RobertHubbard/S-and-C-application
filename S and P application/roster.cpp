
 
#include "roster.h"
#include "student.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Roster::Roster(){
    arrayCounter = 0;
}
Roster::~Roster(){
    for(int i = 0; i < maxSize; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
void Roster::add(string studentID, string lastName, string firstName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram){
    classRosterArray[arrayCounter] = new Student(studentID, lastName, firstName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    arrayCounter++;
}
void Roster::remove(string studentID){
    for(int i = 0; i < arrayCounter; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            for(int j = i; j < arrayCounter; j++){
                classRosterArray[j] = classRosterArray[j + 1];
            }
            arrayCounter--;
            cout << "Student with ID " << studentID << " has been removed." << endl << endl;
            return;
        }
    }
    cout << "Student with ID: " << studentID << " was not found." << endl << endl;
}
void Roster::printTableHeader(){
    cout << setw(4) << "ID" << setw(8) <<"First" << setw(10) << "Last" << setw(25) << "Email Address" << setw(6) << "Age" << setw(16) << "Days in Course" << "Degree Program" << endl;
}
void Roster::printAll(){
    printTableHeader();
    for(int i = 0; i < arrayCounter; i++){
        classRosterArray[i]->printStudent();
    }
    cout << endl;
}
void Roster::printAverageDaysInCourse(string studentID){
    for(int i = 0; i < arrayCounter; i++){
        if(classRosterArray[i]->getStudentID() == studentID){
            cout << "Student " << studentID << " Has an average of "
            << (float)classRosterArray[i]->getDaysInCourse() / 3.0 << " days left." << endl << endl;;
            return;
        }
    }
    cout << "Student with ID: " << studentID << " was not found." << endl << endl;
}
void Roster::printInvalidEmails(){
    // search for '.', '@', & no ' '.
    cout << "Invalid emails: " << endl;
    for (int i = 0; i < arrayCounter; i++){
        string email = classRosterArray[i]->getEmailAddress();
        if(email.find('.') == string::npos || email.find('@') == string::npos || email.find(' ') != string::npos){
        cout << '-' << email << endl;
        }
    }
    cout << endl;
}
void Roster::printByDegreeProgram(Degree degreeProgram){
    printTableHeader();
    for(int i = 0; i < arrayCounter; i++){
        if(classRosterArray[i]->getDegreeProgram() == degreeProgram){
        classRosterArray[i]->printStudent();
        }
    }
    cout << endl;
}
