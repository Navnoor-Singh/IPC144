/*
*****************************************************************************
                        Assignment 1 - Milestone 3
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


// MS#3 Additional macro's:
// ToDo:
#define LEAP_FEB 29
#define NO_LEAP 28
#define HOUR_START 10
#define START_MIN 0
#define HOUR_END 14
#define END_MIN 0
#define INTERVAL 30


//////////////////////////////////////
// Structures
//////////////////////////////////////

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

// ------------------- MS#3 -------------------

// Data type: Time
// ToDo:
struct Time
{
    int hour;
    int min;
};


// Data type: Date
// ToDo:
struct Date
{
    int year;
    int month;
    int day;
};


// Data type: Appointment
// ToDo:
struct Appointment
{
    int patientNumber;
    struct Date date;
    struct Time time;
};



// ClinicData type: Provided to student
// !!! DO NOT MODIFY THIS DATA TYPE !!!
struct ClinicData
{
    struct Patient* patients;
    int maxPatient;
    struct Appointment* appointments;
    int maxAppointments;
};



//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// Display's the patient table header (table format)
void displayPatientTableHeader(void);

// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt);

// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords);

// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField);


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// Menu: Main
void menuMain(struct ClinicData* data);

// Menu: Patient Management
void menuPatient(struct Patient patient[], int max);

// Menu: Patient edit
void menuPatientEdit(struct Patient* patient);

// Menu: Appointment Management
void menuAppointment(struct ClinicData* data);

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt);

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max);

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max);

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max);

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max);


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data);

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData* data);

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* apps, int maxApps, struct Patient* patients, int maxPatients);

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment appoints[], int appointMax,
                       struct Patient patients[], int patientMax);

//data comapare
int dateCompare(struct Date* firstDate, struct Date* secondDate);

//time compare
int timeCompare(struct Time* firstTime, struct Time* secondTime);

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max);

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max);

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max);

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient);

// Get user input for phone contact information
void inputPhoneData(struct Phone* phone);




//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// recieves a constant character, Patient array and max number of elements.
// Import patient data from file into a Patient array (returns # of records read)
// returns integer for number of files read

int importPatients(const char* datafile, struct Patient patients[], int max);


// recieves a constant character, Appointment array and max number of elements.
// Import appointment data from file into an Appointment array (returns # of records read)
// returns integer for number of files read
int importAppointments(const char* datafile, struct Appointment appoints[], int max);

// recieves an array with it's length
// sorts elements of an array in ascending order
// returns nothing
void sortData(struct Appointment appoints[], int max);

//recieves pointer to a struct Appointment and max size
int findNextEmptyIndex(struct Appointment* appoins, int maxappoins);

int checkExistingAppintment(struct Appointment* apps, int maxApps, struct Date inputDate , struct Time inputTime);

int checkValidTimeslot( struct Time inputTime);


////////////////////////////////
///#camelCaseForever
///#goCamels
///////////////////////////////

#endif // !CLINIC_H
