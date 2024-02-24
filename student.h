#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "degree.h"                                     // Include the degree.h header file to access the enumerated data type DegreeProgram

class Student {											// Student class declaration
public:
    const static int daysInCourses_ArraySize = 3;       // Set the size of the int array of days in courses to be constant

    Student();                                          // Declare the default Student constructor
    Student(string ID, string first, string last, string email, int age_private, int daysInCourses[], DegreeProgram degree_pgrm); // Declare the constructor which will be called to add student objects to Roster
    ~Student();                                         // Declare the destructor - however, this can be empty since memory will be deallocated in the Roster destructor

    void SetStudentID(string student_ID);			    // Mutator  | Sets the student's ID
    void SetFirstName(string first_name);			    // Mutator  | Sets the student's first name
    void SetLastName(string last_name);			        // Mutator  | Sets the student's last name
    void SetEmail(string email_address);			    // Mutator  | Sets the student's email
    void SetAge(int age);							    // Mutator  | Sets the student's age
    void SetNumDays(const int days_array[]);	        // Mutator  | Sets an array of days to complete courses
    void SetDegree(DegreeProgram degree);			    // Mutator  | Sets the student's degree program
    string GetID() const;							    // Accessor | Gets the student's ID
    string GetFirst() const;						    // Accessor | Gets the student's first name
    string GetLast() const;							    // Accessor | Gets the student's last name
    string GetEmail() const;						    // Accessor | Gets the student's email address
    int GetAge() const;								    // Accessor | Gets the student's age
    const int* GetDays() const;							// Accessor | Gets the array of days in courses
    DegreeProgram GetDegPrgm() const;					// Accessor | Gets the student's degree program

    void Print() const;								    // Prints specific student data

private:											    // Declares private variables which will be used in function definitions
    string ID;
    string first;
    string last;
    string email;
    int age_private;
    int daysInCourses[daysInCourses_ArraySize];
    DegreeProgram degree_pgrm;
};

#endif // STUDENT_H_INCLUDED
