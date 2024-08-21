/*
*****************************************************************************
                        Assignment 1 - Milestone 1
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
//MACROS//
#define PHONE_LENGTH 10

//PROTOTYPES//

//clearbuffer...
void clearInputBuffer(void);

//suspend...
void suspend(void);

//getting input int...
int inputInt(void);

//getting only positive int...
int inputIntPositive(void);

//checking input range...
int inputIntRange(int lBound, int uBound);

//validation of single characters...
char inputCharOption(const char* valid);

//validation of C strings...
void inputCString(char* cString, int min, int max);

//displaying formatted phone...
void displayFormattedPhone(const char* phoneString);

//END//
