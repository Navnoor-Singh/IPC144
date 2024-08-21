/*
*****************************************************************************
                        Assignment 1 - Milestone 2
Full Name  : Navnoor Singh
Student ID#: 160821211
Email      : nsingh391@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//MACROS//
#define PHONE_LEN 10

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////
// recieves nothing
// Clear the standard input buffer
// returns nothing
void clearInputBuffer(void);

// recieves nothing
// Wait for user to input the "enter" key to continue
// returns nothing
void suspend(void);

// recieves nothing
// gets a valid int input
// returns an integer
int inputInt(void);

// recieves nothing
// gets only a positive int
// returns a positive integer
int inputIntPositive(void);

// recieves lower and upper bound
// checks range for input
// returns an integer within the range
int inputIntRange(int lBound, int uBound);

// recieves an unmodifiable string
// gets and validates a single character
// returns a char
char inputCharOption(const char* valid);

// recieves a pointer to a string, MIN and MAX
// gets and validates a C string
// returns nothing
void inputCString(char* cString, int min, int max);

// recieves a pointer to unmodifiable string
// displays a formatted phone number
// returns nothing
void displayFormattedPhone(const char* phoneString);



// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H

//END//

// #camelCaseForever !! //
// #goCamels !! //
