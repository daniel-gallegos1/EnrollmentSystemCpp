#ifndef ROSTER_H_INCLUDED
#define ROSTER_H_INCLUDED


#include "student.h"                                        // Include the student.h header file to access the Student class.
                                                            // Since student.h includes degree.h, subsequent files which call roster.h will also have access to those header files.
class Roster {											    // Declare the Roster class.
public:
    Roster();                                               // Declare the constructor.
    Student** getStudents();                                // Declare a pointer that itself points to a pointer.
    void parse(string studentDataTable);                    // Declare the parse function. This will parse the student data table.
    void add(string studentID,                              // Here and below, declare other functions necessary for the implementation of this application.
        string firstName, string lastName,
        string emailAddress, int age,
        int daysInCourse1, int daysInCourse2,
        int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    ~Roster();                                              // Declare the destructor. This will release dynamically allocated memory.

private:                                                    // Below are private variables necessary for function definitions in roster.cpp.
    int endIndex = -1;
    const static int numStudents = 5;
    Student* classRosterArray[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};

#endif // ROSTER_H_INCLUDED
