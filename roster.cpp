#include "roster.h"

const string studentData[] =                                            // String [4] has been modified with my personal information.
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,BIOLOGY",           // This array of strings will be parsed via the parse() function.
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,ETHICS",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,COMPSCI",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,BIOLOGY",
    "A5,Daniel,Gallegos,dgal135@wgu.edu,25,5,23,11,COMPSCI"
};

Roster::Roster() {                                                      // Define the Roster constructor. This constructor calls the parse()
    parse(studentData[0]);                                              // function on each index of studentData[].
    parse(studentData[1]);
    parse(studentData[2]);
    parse(studentData[3]);
    parse(studentData[4]);
}

Student** Roster::getStudents() {                                   // When getStudents() is called, it should return the classRosterArray pointer.
    return Roster::classRosterArray;
}


void Roster::parse(string studentDataTable) {                       // This is the parse function definition.
    DegreeProgram deg = DegreeProgram::BIOLOGY;
    if (studentDataTable.back() == 'S') {                           // This tests whether the final char is S; only ETHICS matches this.
        deg = DegreeProgram::ETHICS;
    }
    else if (studentDataTable.back() == 'I') {                      // Tests for I as the final char; only COMPSCI matches this.
        deg = DegreeProgram::COMPSCI;
    }

    size_t rhs = studentDataTable.find(",");                        // Finds the first comma in the string.
    string stud_ID = studentDataTable.substr(0, rhs);               // Makes a substring, stud_ID, by concatenating the chars from beginning to first comma.

    size_t lhs = rhs + 1;
    rhs = studentDataTable.find(",", lhs);                          // Finds next comma in string.
    string f_Name = studentDataTable.substr(lhs, rhs - lhs);        // Makes a substring, f_Name, by concatenating the chars from the char after the first comma to the next comma.

    lhs = rhs + 1;                                                  // The process is repeated several more times to create substrings.
    rhs = studentDataTable.find(",", lhs);
    string l_Name = studentDataTable.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentDataTable.find(",", lhs);
    string e_Address = studentDataTable.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentDataTable.find(",", lhs);
    int age_Parsed = stoi(studentDataTable.substr(lhs, rhs - lhs));

    int days[3];
    for (int i = 0; i < 3; i++) {
        lhs = rhs + 1;
        rhs = studentDataTable.find(",", lhs);
        days[i] = stoi(studentDataTable.substr(lhs, rhs - lhs));
    }

    add(stud_ID, f_Name, l_Name, e_Address, age_Parsed, days[0], days[1], days[2], deg); // The substrings created above will be used in the add() function defined below.
}

void Roster::add(string studentID,                                  // This add() functions takes as its input the resulting substrings from parse() and creates a new Student object.
    string firstName, string lastName,                              // This process calls the paramater-full Student constructor and inputs substrings from parse().
    string emailAddress, int age,
    int daysInCourse1, int daysInCourse2,
    int daysInCourse3, DegreeProgram degreeprogram) {

    int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[++endIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

void Roster::remove(string studentID) {                             // This essentially removes a student from the roster. Their data is not deleted yet, however.
    bool success = false;
    for (int i = 0; i <= Roster::endIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            success = true;
            Student* temp = classRosterArray[i];
            classRosterArray[i] = classRosterArray[numStudents - 1];
            classRosterArray[numStudents - 1] = temp;

            Roster::endIndex--;
        }
    }
    if (success == true) {
        cout << "Student " << studentID << " was successfully removed." << endl << endl; // If a student has been removed, this is printed.
    }
    else if (success == false) {
        cout << "Student " << studentID << " was not found." << endl << endl; // This is printed if a student was not found.
    }
}

void Roster::printAll() {                                           // This loops across the array of students and prints out their data as per Print().
    for (int i = 0; i <= Roster::endIndex; i++) {
        Roster::classRosterArray[i]->Print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {           // This loops across the roster and prints out each student's average days in 3 courses.
    for (int i = 0; i <= Roster::endIndex; i++) {
        string f_NameString = Roster::getStudents()[i]->GetFirst();
        if (classRosterArray[i]->GetID() == studentID) {
            double averageDays = (classRosterArray[i]->GetDays()[0] + classRosterArray[i]->GetDays()[1] + classRosterArray[i]->GetDays()[2]) / 3.0;

            cout << f_NameString << "\'s average days in courses equals: ";
            cout << averageDays << "." << endl;
        }
    }
}

void Roster::printInvalidEmails() {                                 // This prints invalid emails along with who inputted each.
    for (int i = 0; i <= Roster::endIndex; i++) {
        string eMail = Roster::getStudents()[i]->GetEmail();
        string f_NameString = Roster::getStudents()[i]->GetFirst();
        if (eMail.find(' ') != string::npos || eMail.find('@') == string::npos || eMail.find('.') == string::npos) {
            cout << f_NameString << "\'s inputted email, " << eMail << ", is an invalid email address." << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {    // This prints out student data based on the inputted degree type.
    string degreeInput;
    if (degreeProgram == DegreeProgram::COMPSCI) {
        degreeInput = "COMPSCI";
    }
    else if (degreeProgram == DegreeProgram::ETHICS) {
        degreeInput = "ETHICS";
    }
    else {
        degreeInput = "BIOLOGY";
    }

    cout << endl << "Printing by degree type " << degreeInput << ":" << endl;
    for (int i = 0; i <= Roster::endIndex; i++) {
        if (Roster::classRosterArray[i]->GetDegPrgm() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
    cout << endl;
}

Roster::~Roster() {                                                 // This defines the Roster destructor. It loops across the array of students and deletes their data.
    for (int i = 0; i < numStudents; i++) {                         // Then it sets each student to the nullptr as before.
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
