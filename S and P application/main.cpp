
#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char * argv[]) {
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Robert,Hubbard,rhubb30@my.wgu.edu,30, 51, 55, 59,SOFTWARE"};
    
    Roster classRoster;
    Degree degreeProgram;
    
    // Parse data from the string to add students
    // to classRoster
    for(int i = 0; i < 5; i++){
        int j = 0;
        stringstream ss(studentData[i]);
        string subStr[9];

        while(ss.good()){
            getline(ss, subStr[j], ',');
            j++;
        }
        // cast subStr to correct data types
        string studentID = subStr[0];
        string firstName = subStr[1];
        string lastName = subStr[2];
        string emailAddress = subStr[3];
        int age = stoi(subStr[4]);
        int daysInCourse1 = stoi(subStr[5]);
        int daysInCourse2 = stoi(subStr[6]);
        int daysInCourse3 = stoi(subStr[7]);
        string temp = subStr[8];
        
        if (subStr[8] == "SECURITY"){
            degreeProgram = SECURITY;
            }
        else if(subStr[8] == "NETWORK"){
            degreeProgram = NETWORK;
        }
        else if(subStr[8] == "SOFTWARE"){
            degreeProgram = SOFTWARE;
        }else{
            cerr << "ERROR: INCORRECT DATA" << endl;
            return 1;
        }
        
        classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1,
        daysInCourse2, daysInCourse3, degreeProgram);
    }
    // Student Info
    cout << "Course: C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 01157174" << endl;
    cout << "Name: Robert Hubbard" << endl << endl;
    // Converted pseudo code
    classRoster.printAll();
    classRoster.printInvalidEmails();
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    return 0;
}
