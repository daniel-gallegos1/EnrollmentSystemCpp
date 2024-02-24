#include "student.h"

// Constructors:

Student::Student() {		                            // Default constructor
    SetStudentID("");                                   // All values are set to default values, such that:
    SetFirstName("");                                   // strings are set to empty strings - "" - and ints are set to 0.
    SetLastName("");
    SetEmail("");
    SetAge(0);
    const int days[] = { 0, 0, 0 };
    SetNumDays(days);
    SetDegree(DegreeProgram::BIOLOGY);                 // Enumerated data types cannot be left blank, so this is set to BIOLOGY.
}

Student::Student(string ID, string first, string last, string email, int age_private, int daysInCourses[], DegreeProgram degree_pgrm) { // This constructor is used in the add function to add new student objects to the classRosterArray
    SetStudentID(ID);
    SetFirstName(first);
    SetLastName(last);
    SetEmail(email);
    SetAge(age_private);
    SetNumDays(daysInCourses);
    SetDegree(degree_pgrm);
}

// Destructor:

Student::~Student() {}                                  // Memory is released in the Roster destructor, so this can be left empty.

// Mutators:

void Student::SetStudentID(string student_ID) {         // Definition for the SetStudentID() mutator function.
    this->ID = student_ID;
}

void Student::SetFirstName(string first_name) {         // Definition for the SetFirstName() mutator function.
    this->first = first_name;
}

void Student::SetLastName(string last_name) {           // Definition for the SetLastName() mutator function.
    this->last = last_name;
}

void Student::SetEmail(string email_address) {          // Definition for the SetEmail() mutator function.
    this->email = email_address;
}

void Student::SetAge(int age) {                         // Definition for the SetAge() mutator function.
    this->age_private = age;
}

void Student::SetNumDays(const int daysInCourses[]) {   // Definition for the SetNumDays() mutator function.
    for (int i = 0; i < daysInCourses_ArraySize; i++) {
        this->daysInCourses[i] = daysInCourses[i];
    }
}

void Student::SetDegree(DegreeProgram degree) {         // Definition for the SetDegree() mutator function.
    this->degree_pgrm = degree;
}

// Accessors:

string Student::GetID() const {                         // Definition for the GetID() accessor function.
    return this->ID;
}

string Student::GetFirst() const {                      // Definition for the GetFirst() accessor function.
    return this->first;
}

string Student::GetLast() const {                       // Definition for the GetLast() accessor function.
    return this->last;
}

string Student::GetEmail() const {                      // Definition for the GetEmail() accessor function.
    return this->email;
}

int Student::GetAge() const {                           // Definition for the GetAge() accessor function.
    return this->age_private;
}

const int* Student::GetDays() const {                   // Definition for the GetDays() accessor function. This returns a pointer to the array which points to the first element in the array.
    return this->daysInCourses;
}

DegreeProgram Student::GetDegPrgm() const {             // Definition for the GetDegPrgm() accessor function.
    //return degree_pgrm;
    return this->degree_pgrm;
}

// Print function:

void Student::Print() const {                           // Definition for the Print() function. This uses accessors and prints their values.
    cout << GetID() << '\t';
    cout << "First Name: " << GetFirst() << '\t';
    cout << "Last Name: " << GetLast() << '\t';
    cout << "Age: " << GetAge() << '\t';
    cout << "daysInCourse: {" << GetDays()[0] << ", " << GetDays()[1] << ", " << GetDays()[2] << "}\t";
    cout << "Degree Program: " << degreeTypeStrings[(int)GetDegPrgm()];
    cout << endl;
}
