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
#ifndef CLINIC_H
#define CLINIC_H

//////////////////////////////////////
// Module macro's (usable by any file that includes this header)
//////////////////////////////////////

// Display formatting options (Provided to student)
// !!! DO NOT MODIFY THESE MACRO'S !!!
#define FMT_FORM 1
#define FMT_TABLE 2

// C Strings: array sizes
#define NAME_LEN 15
#define PHONE_DESC_LEN 4
#define PHONE_LEN 10

//////////////////////////////////////
// Structures
//////////////////////////////////////

// Data type: Phone
// ToDo:
struct Phone
{
    char description[PHONE_DESC_LEN + 1];
    char number[PHONE_LEN + 1];
};

// Data type: Patient
// ToDo:
struct Patient
{
    int patientNumber;
    char name[NAME_LEN + 1];
    struct Phone phone;
};

// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
};


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData* data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! ALL the below functions need defining       !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// !!! DO NOT MODIFY THE BELOW PROTOTYPES !!!

// recieves an unmodifiable struct of patient, max number of patients and the format specifier
// Display's all patient data in the FMT_FORM | FMT_TABLE format
// returns nothing
void displayAllPatients(const struct Patient patient[], int max, int fmt);


// recieves an unmodifiable struct of patient and the format specifier
// Search for a patient record based on patient number or phone number
// returns nothing
void searchPatientData(const struct Patient patient[], int max);


// recieves an struct of patient and max number of patients
// Add a new patient record to the patient array
//returns nothing
void addPatient(struct Patient patient[], int max);


// recieves an struct of patient and max number of patients
// Edits a patient record from the patient array
// returns nothing
void editPatient(struct Patient patient[], int max);


// recieves an struct of patient and max number of patients
// Remove a patient record from the patient array
// returns nothing
void removePatient(struct Patient patient[], int max);


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////


// recieves an unmodifiable struct of patient and max number of patients
// Search and display patient record by patient number (form)
// returns nothing
void searchPatientByPatientNumber(const struct Patient patient[], int max);


// recieves an unmodifiable struct of patient and max number of patients
// Search and display patient records by phone number (tabular)
// returns nothing
void searchPatientByPhoneNumber(const struct Patient patient[], int max);


// recieves an unmodifiable struct of patient and max number of patients
// Get the next highest patient number
// returns a new patient number
int nextPatientNumber(const struct Patient patient[], int max);


// recieves a patient numbe, unmodifiable struct of patient and max number of patients
// Find the patient array index by patient number (returns -1 if not found)
// returns the index number or -1 if index not found
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////


// recieves a pointer to a struct named patient
// Get user input for a new patient record
// returns nothing
void inputPatient(struct Patient* patient);


// recieves a pointer to a struct named phone
// Get user input for phone contact information
//returns nothing
void inputPhoneData(struct Phone* phone);


#endif // !CLINIC_H

//END//

// #camelCaseForever !! //
// #goCamels !! //
