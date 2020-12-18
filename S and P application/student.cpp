
 
#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student(){}
Student::Student (string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram){
    this->studentID = studentID;
    this->lastName = lastName;
    this->firstName = firstName;
    this->emailAddress = emailAddress;
    this->age = age;
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}
string Student::getStudentID() const{
    return studentID;
}
string Student::getLastName() const{
    return lastName;
}
string Student::getFirstName() const{
    return firstName;
}
string Student::getEmailAddress() const{
    return emailAddress;
}
int Student::getAge() const{
    return age;
}
int Student::getDaysInCourse() const{
    int totalDays = daysInCourse[0] + daysInCourse[1] + daysInCourse[2];
    return totalDays;
}
Degree Student::getDegreeProgram() const{
    return degreeProgram;
}


void Student::setStudentID(string studentID){
    this->studentID = studentID;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}
void Student::setEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3){
    daysInCourse[0] = daysInCourse1;
    daysInCourse[1] = daysInCourse2;
    daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(Degree degreeProgram){
    this->degreeProgram = degreeProgram;
}
    
void Student::printStudent(){
    // String parallell to Degree
    string degreeString[] = {"SECURITY","NETWORK","SOFTWARE"};

    cout << left << setw(4) << studentID << setw(8) << firstName << setw(10) << lastName << setw(25) << emailAddress << setw(6) << age << daysInCourse[0] << ", " << daysInCourse[1] << ", " << setw(8) << daysInCourse[2]  << degreeString[degreeProgram] << endl;
}
