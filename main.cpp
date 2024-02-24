
#include "roster.h"

int main()
{
    //cout << "Application: Visual Studio" << endl;
    cout << "Name: Daniel Gallegos" << endl;                                            // Prints my name.
    cout << "Programming Language Used: C++" << endl;                                   // Prints the programming language used.

    const int numStudents = 5;                                                          // This will be used in the loop below.

    Roster classRoster;                                                                 // Create a Roster object called classRoster.
                                                                                        // This will parse the student data table and add each student to classRoster.
    cout << endl << "Printing all students to the console:" << endl;
    classRoster.printAll();                                                             // Prints all requested student data.

    cout << endl << "Printing invalid emails to the console:" << endl;
    classRoster.printInvalidEmails();                                                   // Prints all invalid emails.

    cout << endl << "Printing each student's average days in courses:" << endl;
    for (int i = 0; i < numStudents; i++) {                                             // Loops across classRoster and prints each student's average days in 3 courses.
        classRoster.printAverageDaysInCourse(classRoster.getStudents()[i]->GetID());
    }

    // Let user choose which degree program to filter students by.
    DegreeProgram degreeInputDP;
    string degreeInput;
    cout << endl;
    cout << "Please type a degree program. Type 'COMPSCI', 'ETHICS', or 'BIOLOGY': ";
    cin >> degreeInput;

    while (degreeInput != "COMPSCI" && (degreeInput != "ETHICS" && degreeInput != "BIOLOGY")){
        cout << "Invalid degree type." << endl;
        cout << "Please type a degree program. Type 'COMPSCI', 'ETHICS', or 'BIOLOGY': ";
        cin >> degreeInput;
    }

    if (degreeInput == "COMPSCI") {
        degreeInputDP = DegreeProgram::COMPSCI;
    }
    else if (degreeInput == "ETHICS") {
        degreeInputDP = DegreeProgram::ETHICS;
    }
    else {
        degreeInputDP = DegreeProgram::BIOLOGY;
    }

    classRoster.printByDegreeProgram(degreeInputDP);                          // Prints requested data for all students enrolled in degreeInputDP.

    // Let the user determine which student to remove from the roster.
    string removeStudentID;

    cout << "Please type a student ID. Type 'A1', 'A2', 'A3', 'A4', or 'A5': ";
    cin >> removeStudentID;

    while (removeStudentID != "A1" && (removeStudentID != "A2" && (removeStudentID != "A3" && (removeStudentID != "A4" && removeStudentID != "A5")))){
        cout << "Invalid student ID type." << endl;
        cout << "Please type a valid student ID. Options include 'A1', 'A2', 'A3', 'A4', or 'A5': ";
        cin >> removeStudentID;
    }

    cout << endl;
    cout << "Attempting to remove student " << removeStudentID << "." << endl;
    classRoster.remove(removeStudentID);                                                // Removes student defined above.

    cout << "Displaying all students in Roster:" << endl;
    classRoster.printAll();                                                             // Prints all remaining students in classRoster.

    classRoster.remove(removeStudentID);                                                // Attempts to remove student defined above again. This will print, 'student not found.'

    cout << "Code has been executed. Destructors will now be implemented automatically upon exiting the program." << endl; // The program is executed and destructors are called to free memory.

    return 0;                                                                            // Main will return 0, ending the execution.
}

