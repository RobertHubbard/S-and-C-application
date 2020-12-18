

#ifndef student_h
#define student_h

#include <string>
#include "degree.h"
using namespace std;
using std::string;

class Student {
public:
    // constructor
    Student ();
    Student (string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
    
    // accessor functions
    string getStudentID() const;
    string getLastName() const;
    string getFirstName() const;
    string getEmailAddress() const;
    int getAge() const;
    int getDaysInCourse() const;
    Degree getDegreeProgram() const;
    
    // mutator functions
    void setStudentID(string studentID);
    void setLastName(string lastName);
    void setFirstName(string firstName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(Degree degreeProgram);
    
    void printStudent();
    
private:
    string studentID;
    string lastName;
    string firstName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    Degree degreeProgram;
};

#endif /* student_h */
