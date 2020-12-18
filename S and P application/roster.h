
#ifndef roster_h
#define roster_h

#include "student.h"
class Roster {
    public:
        Roster();
        ~Roster();
        void add(string studentID, string lastName, string firstName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
        void remove(string studentID);
        void printAll();
        void printTableHeader();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(Degree degreeProgram);
    private:
        const int maxSize = 5;
        int arrayCounter;
        Student* classRosterArray[5];
};


#endif /* roster_h */
