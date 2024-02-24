#ifndef DEGREE_H_INCLUDED
#define DEGREE_H_INCLUDED

#include <iostream>

using namespace std;

#include <string>
#include <cstring>

enum class DegreeProgram { BIOLOGY, ETHICS, COMPSCI };								// Declare the enumerated class DegreeProgram
static const string degreeTypeStrings[] = { "BIOLOGY", "ETHICS", "COMPSCI" };		// Declare a parallel string array for DegreeProgram

#endif // DEGREE_H_INCLUDED
