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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
            case 1:
                viewAllAppointments(data);  // ToDo: You will need to create this function!
                suspend();
                break;
            case 2:
                viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
                suspend();
                break;
            case 3:
                addAppointment(data->appointments, data->maxAppointments,
                               data->patients, data->maxPatient);  // ToDo: You will need to create this function!
                suspend();
                break;
            case 4:
                removeAppointment(data->appointments, data->maxAppointments,
                                  data->patients, data->maxPatient);  // ToDo: You will need to create this function!
                suspend();
                break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// recieves an unmodifiable struct of patient, max number of patients and the format specifier
// Display's all patient data in the FMT_FORM | FMT_TABLE format
// returns nothing.

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, count;

    //displaying table header//
    displayPatientTableHeader();

    //iterating over the whole list of patients//
    for (i = 0, count = 0 ; i < max; i++)
    {
        //checking validity of patient number//
        if(patient[i].patientNumber > 0)
        {
            //displaying patient data with FORM type//
            displayPatientData(&patient[i], fmt);

            //keeping a count on the list//
            count++;
        }


    }

    //checking if the list is full//
    if((max - count) == max)
    {
            putchar('\n');
            printf("*** No records found ***");

    }

    putchar('\n');
}

// recieves an unmodifiable struct of patient and the format specifier
// Search for a patient record based on patient number or phone number
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    //loop started//
    do {
        printf("Search Options\n"
               "==========================\n"
               "1) By patient number\n"
               "2) By phone number\n"
               "..........................\n"
               "0) Previous menu\n"
               "..........................\n"
               "Selection: ");
        //getting an integer within given range//
        selection = inputIntRange(0, 2);

        putchar('\n');

        //switch started//
        switch (selection)
        {
        case 1:
                //searching patients by their unique patient numbers//
                searchPatientByPatientNumber(patient, max);
                suspend();

            break;
        case 2:
                //searching patients by their phone numbers//
                searchPatientByPhoneNumber(patient, max);
                suspend();

            break;
        }

    //loop exit//
    } while (selection);
}


// recieves an struct of patient and max number of patients
// Add a new patient record to the patient array
//returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i, emptyIndex = -1, count;

    //iterating over the whole list of patients, untill and empty index is found//
    for (i = 0, count = 0 ; i < max && emptyIndex == -1 ; i++)
    {

        //checking empty index numbers//
        if(!patient[i].patientNumber)
        {
            //assigning iterator as empty index number//
            emptyIndex = i;
        }
        if(patient[i].patientNumber)
        {
            //keeping a count of elements
            count++;
        }
    }

    //checking if the list is full//
    if((max - count) == 0)
    {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
    }

    else
    {
        //providing next patient number by calling necessary function//
        patient[emptyIndex].patientNumber =  nextPatientNumber(patient, max);

        //calling function to get user input//
        inputPatient(&patient[emptyIndex]);

        //displaying confirmation message//
        printf("*** New patient record added ***\n");
        putchar('\n');

    }

}



// recieves an struct of patient and max number of patients
// Edits a patient record from the patient array
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int i, valid = -1, tmpPatientNum, index;

    //getting the patient number which user want to edit//
    printf("Enter the patient number: ");

    //calling necessary function to get the input//
    tmpPatientNum = inputIntPositive();

    //getting index number of the entered patient number//
    index = findPatientIndexByPatientNum(tmpPatientNum, patient, max);

    //iterating over the whole list of patients//
    for (i = 0 ; i < max ; i++)
    {
        //cheking if there was no index found//
        if(index == -1)
        {
            //setting the flag off//
            valid = 0;
        }

        else
        {
            //setting the flag on//
            valid = 1;
        }
    }
    putchar('\n');

    //printing error message if index not found//
    if(!valid)
    {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    //if found, calling necessary function to edit data//
    else
    {
        menuPatientEdit(&patient[index]);
    }

}



// recieves an struct of patient and max number of patients
// Remove a patient record from the patient array
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int tmpPatientNum, index;
    int selection;

    //getting the patient number which user want to remove//
    printf("Enter the patient number: ");

    //calling necessary function to get the input//
    tmpPatientNum = inputIntPositive();

    //getting index number of the entered patient number//
    index = findPatientIndexByPatientNum(tmpPatientNum, patient, max);

    //printing error message if index not found//
    if(index == -1)
    {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }

    //if found, proceding to remove patient//
    else
    {
        putchar('\n');

        //displaying patient information before removing//
        displayPatientData(&patient[index], FMT_FORM);

        putchar('\n');

        //prompting user for confirmation//
        printf("Are you sure you want to remove this patient record? (y/n): ");

        //calling necessary function to get a single character for the confirmation//
        selection = !(inputCharOption("yn") == 'y');

        //checking if user pressed 'y'//
        if (!selection)
        {
            //setting the patient number to a safe empty space, hence removing it//
            patient[index].patientNumber =  0;

            //displaying confirmation//
            printf("Patient record has been removed!\n");
            putchar('\n');
        }

        //if user pressed 'n'//
        else
        {
            //displaying confirmation for aborting the process//
            printf("Operation aborted.\n");
            putchar('\n');
            suspend();
        }
    }

}





// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData *data)
{

    int i, returnPatientIdx;
    // bubble sort
    sortData(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&data->appointments->date, 1);

    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year > 0)
        {
            //getting patient info by his index number
            returnPatientIdx = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

            displayScheduleData(&data->patients[returnPatientIdx], &data->appointments[i], 1);
        }
    }
    putchar('\n');
}



// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData data[])
{
    //empty struct
    struct Date tmpDate = { 0 };
    
    int i, returnPatientIdx, returnDateCompare, count, monthDays;

    printf("Year        : ");
    tmpDate.year = inputIntRange(2022, 2042);

    printf("Month (1-12): ");
    tmpDate.month = inputIntRange(1, 12);

    if(tmpDate.month == 2)
    {

        if (!(tmpDate.year % 4))
        {
            printf("Day (1-%d)  : ", LEAP_FEB);
            tmpDate.day = inputIntRange(1, LEAP_FEB);
        }
        else
        {
            printf("Day (1-%d)  : ", NO_LEAP);
            tmpDate.day = inputIntRange(1, NO_LEAP);
            
        }
        
    }
    
    else
    {
        
        if( tmpDate.month == 4 || tmpDate.month == 6 || tmpDate.month == 9 || tmpDate.month == 11)
        {
            monthDays = 30;
            printf("Day (1-%d)  : ", monthDays);
            tmpDate.day = inputIntRange(1, monthDays);
        }
        else
        {
            monthDays = 31;
            printf("Day (1-%d)  : ", monthDays);
            tmpDate.day = inputIntRange(1, monthDays);
        }
        
    }

    putchar('\n');
    displayScheduleTableHeader(&tmpDate, 0);
    
    //flag for error message
    count = 0;

    for (i = 0; data->appointments[i].patientNumber != -1 && i < data->maxAppointments; i++)
    {
        returnDateCompare = dateCompare(&tmpDate, &data->appointments[i].date);
        
        if (!returnDateCompare)
        {
            // Get patient info from database by matching the patient number from appointment array
            returnPatientIdx = findPatientIndexByPatientNum(data->appointments[i].patientNumber, data->patients, data->maxPatient);

            displayScheduleData(&data->patients[returnPatientIdx], &data->appointments[i], 0);
            count++;
            
        }
        
    }
    
    if (count < 1)
    {
        printf("*** No records found ***\n");
    }
    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoins, int maxappoins, struct Patient* patients, int maxPatients)
{
    int patientNum, monthDays;
    struct Date inputDate;
    struct Time inputTime;
    int valid = 1;
    int index, result;

    // check if appointment array has space
    // if empty, display error message
    index = findNextEmptyIndex(appoins, maxappoins);
    if  (index == -1)
    {
        printf("ERROR: Appointment listing is FULL!\n\n");
        valid = 0;
    }
    else {

        printf("Patient Number: ");
        patientNum = inputIntPositive();
        
        // validate entered patient number by checking existing patient number
        result = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
        
        // display error message, if patientNum not found
        if (result == -1)
        {
            printf("ERROR: Patient record not found!\n");
            valid = 0;
        }
        
        //if everything's OK
        if (valid == 1) {
            
            //prompt for data
            do
            {
                printf("Year        : ");
                inputDate.year = inputIntRange(2022, 2042);

                printf("Month (1-12): ");
                inputDate.month = inputIntRange(1, 12);

                if(inputDate.month == 2)
                {
                    
                    
                    if (!(inputDate.year % 4))
                    {
                        printf("Day (1-%d)  : ", LEAP_FEB);
                        inputDate.day = inputIntRange(1, LEAP_FEB);
                    }
                    else
                    {
                        printf("Day (1-%d)  : ", NO_LEAP);
                        inputDate.day = inputIntRange(1, NO_LEAP);
                        
                    }
                }
                else
                {
                    if( inputDate.month == 4 || inputDate.month == 6 || inputDate.month == 9 || inputDate.month == 11)
                    {
                        monthDays = 30;
                        printf("Day (1-%d)  : ", monthDays);
                        inputDate.day = inputIntRange(1, monthDays);
                    }
                    else
                    {
                        monthDays = 31;
                        printf("Day (1-%d)  : ", monthDays);
                        inputDate.day = inputIntRange(1, monthDays);
                    }
                    
                }
                printf("Hour (0-23)  : ");
                inputTime.hour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                inputTime.min = inputIntRange(0, 59);
                // check if timeslot is already existing in the appointment array

            } while (checkExistingAppintment(appoins, maxappoins, inputDate, inputTime) == 1);
            // Enter the necessary information and confirm that the timeslot is a valid interval and is within the operational hours
                          
            // check if timeslot is withing operational hours and is a valid interval
            while(checkValidTimeslot(inputTime) == 0)
            {
                printf("Hour (0-23)  : ");
                inputTime.hour = inputIntRange(0, 23);
                printf("Minute (0-59): ");
                inputTime.min = inputIntRange(0, 59);
            }

        
        // adding the appointment
                appoins[index].patientNumber = patientNum;
                appoins[index].date.year = inputDate.year;
                appoins[index].date.month = inputDate.month;
                appoins[index].date.day = inputDate.day;
                appoins[index].time.hour = inputTime.hour;
                appoins[index].time.min = inputTime.min;
                printf("\n*** Appointment scheduled! ***\n");
            
        }
    }
    putchar('\n');
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoins, int maxappoins, struct Patient* patients, int maxPatients)
{
    struct Date inputDate;
    int i, patientNum, index, forflag = 0;
    
    printf("Patient Number: ");
    patientNum = inputIntPositive();
    
    
    index = findPatientIndexByPatientNum(patientNum, patients, maxPatients);
    //displaying error message if not found
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    
    else {
        
        //prompting for input
        printf("Year        : ");
        inputDate.year = inputIntPositive();
        printf("Month (1-12): ");
        inputDate.month = inputIntRange(1, 12);
        if (((inputDate.year % 4 == 0) && (inputDate.year % 100 != 0)) || (inputDate.year % 400 == 0))
        {
            printf("Day (1-29)  : ");
            inputDate.day = inputIntRange(1, 29);
        }
        else
        {
            printf("Day (1-28)  : ");
            inputDate.day = inputIntRange(1, 28);
        }
        putchar('\n');

        // show information about the patient for confirmation
        printf("Name  : %s\n", patients[index].name);
        printf("Number: %05d\n", patients[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patients[index].phone.number);
        printf(" (%s)\n", patients[index].phone.description);
        printf("Are you sure you want to remove this appointment (y,n): ");
        char option = inputCharOption("yn");
        
        // cancel removing the appointment
        if (option == 'n')
        {
            printf("Operation aborted.\n");
            
        }
        
        // remove the appointment
        else
        {
            for (i = 0; i < maxappoins && forflag == 0; i++)
            {
                if (appoins[i].patientNumber == patientNum &&
                    appoins[i].date.year == inputDate.year &&
                    appoins[i].date.month == inputDate.month &&
                    appoins[i].date.day == inputDate.day)
                {
                    appoins[i].date.year = 0;
                    forflag = 1;
                }
            }
            printf("\nAppointment record has been removed!\n");
        }
    }
   
    putchar('\n');
}




//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// recieves an unmodifiable struct of patient and max number of patients
// Search and display patient record by patient number (form)
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int index, tmpNumber;

    //getting the patient number which user want to remove//
    printf("Search by patient number: ");

    //calling necessary function to get the input//
    tmpNumber = inputIntPositive();

    putchar('\n');

    //getting index number of the entered patient number//
    index = findPatientIndexByPatientNum(tmpNumber, patient, max);

    //cheking if there was no index found
    if(index == -1)
    {
        //printing error message//
        printf("*** No records found ***\n");
    }

    //if found//
    else
    {
        //displating searched patient data in FORM FORMAT//
        displayPatientData(&patient[index], FMT_FORM);
    }

    putchar('\n');

}



// recieves an unmodifiable struct of patient and max number of patients
// Search and display patient records by phone number (tabular)
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, error = 0;
    char tmpPhonenum[PHONE_LEN + 1] = { 0 };

    //getting the patient number which user want to remove//
    printf("Search by phone number: ");

    //calling necessary function to get the input within bounds//
    inputCString(tmpPhonenum, PHONE_LEN, PHONE_LEN);

    putchar('\n');

    //displaying table header//
    displayPatientTableHeader();

    //iterating over the whole list of patients//
    for (i = 0 ; i < max ; i++)
    {
        //checking if the entered phone number exists//
        if((strcmp(tmpPhonenum, patient[i].phone.number)) == 0)
        {
            //displaying searched patient data in TABLE FORMAT//
            displayPatientData(&patient[i],FMT_TABLE);
            //counting for errors//
            error++;
        }

    }

    //checking for errors//
    if(error == 0)
    {
        putchar('\n');

        //displaying error message//
        printf("*** No records found ***\n");
    }
    putchar('\n');

}



// recieves an unmodifiable struct of patient and max number of patients
// Get the next highest patient number
// returns a new patient number

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, lastPNum = 0, lastPerson = 0;
    
    // find the largest patient number in the array and store in variable next
    for(i = 0; i < max; i++)
    {
        if(patient[i].patientNumber > lastPNum)
        {
            lastPNum = patient[i].patientNumber;
        }
    }
    lastPerson = lastPNum + 1; // add 1 to the largest patient number in the array

    return lastPerson;

}



// recieves a patient numbe, unmodifiable struct of patient and max number of patients
// Find the patient array index by patient number (returns -1 if not found)
// returns the index number or -1 if index not found

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
    int i, valid = -1;

    //iterating over the whole list of patients//
    for (i = 0 ; i < max ; i++)
    {
        //checking if the patient number matched with the entered patient number//
        if(patient[i].patientNumber == patientNumber)
        {
            valid = i;
        }
    }

    //returing -1 or the index number.
    return valid;

}


// check for empty record in appointments
int findNextEmptyIndex(struct Appointment* appoins, int maxappoins)
{
    int isFull = -1;
    int i;
    
    for (i = 0; i < maxappoins; i++)
    {
        if (appoins[i].patientNumber < 1)
        {
            isFull = i;
      
        }
    }

    return isFull;
}


//check for existing appintment for date and time
int checkExistingAppintment(struct Appointment* appoins, int maxappoins, struct Date inputDate , struct Time inputTime)
{
    int isExist = 0, forflag = 0;
    int i;
    
    for (i = 0; i < maxappoins && forflag == 0; i++)
    {
        if (appoins[i].date.year == inputDate.year &&
            appoins[i].date.month == inputDate.month &&
            appoins[i].date.day == inputDate.day &&
            appoins[i].time.hour == inputTime.hour &&
            appoins[i].time.min == inputTime.min)
        {
            isExist = 1;
            forflag = 1;
        }
   
    }
    if (isExist == 1) {
        printf("\nERROR: Appointment timeslot is not available!\n\n");
    }
    return isExist;
}



//check for valid timeslot operational hours
int checkValidTimeslot(struct Time inputTime)
{
    int input = inputTime.hour * 60 + inputTime.min;
    int valid = 1;
    
    if (input % INTERVAL != 0 || input < HOUR_START * 60 + START_MIN || input > HOUR_END * 60 + END_MIN)
    {
        printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %d minute intervals.\n\n",
            HOUR_START, START_MIN, HOUR_END, END_MIN, INTERVAL);
        valid = 0;

    }
    return valid;
}


// Compare the appointment date (by year, month and day) and return an int to indicate the result
int dateCompare(struct Date* firstDate, struct Date* secondDate)
{
    int dateCompareResult;

    // if the date (by year, month, and day) from the first structure exceeds that of the second structure.
    if ((firstDate->year > secondDate->year)||
       ((firstDate->year == secondDate->year) && (firstDate->month > secondDate->month)) ||
       ((firstDate->year == secondDate->year) && (firstDate->month == secondDate->month) && (firstDate->day > secondDate->day)))
    {
        // Set return to 1
        dateCompareResult = 1;
    }

    // if the date from 1st struct = 2nd struct
    else if ((firstDate->year == secondDate->year) &&
             (firstDate->month == secondDate->month) &&
             (firstDate->day == secondDate->day))
    {
        // Set return to 0
        dateCompareResult = 0;
        
    }
    
    // if the date from 1st struct < 2nd struct
    else
    {
        // Set return to -1
        dateCompareResult = -1;

    }

    return dateCompareResult;
}

// Compare the appointment time (by hour and min) and return an int to indicate the result
int timeCompare(struct Time* firstTime, struct Time* secondTime)
{
    int timeCompareResult;

   
    // if the time (by hour and minute) from the first structure exceeds that of the second structure
    if ((firstTime->hour > secondTime->hour) ||
        ((firstTime->hour == secondTime->hour) && (firstTime->min > secondTime->min)))
    {
        // Set return to 1
        timeCompareResult = 1;
    }

    // if the time from 1st struct = 2nd struct
    else if ((firstTime->hour == secondTime->hour) && (firstTime->min == secondTime->min))
    {
        // Set return to 0
        timeCompareResult = 0;
    }
    
    // if the time from 1st struct < 2nd struct
    else
    {
        // Set return to -1
        timeCompareResult = -1;
    }

    return timeCompareResult;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// recieves a pointer to a struct named patient
// Get user input for a new patient record
// returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{

    //prompting for user input//
    printf("Patient Data Input\n"
           "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    //calling necessary function to get a C string for NAME//
    inputCString(patient->name, 1, NAME_LEN);

    putchar('\n');

    //calling necessary function for getting new PHONE NUMBER//
    inputPhoneData(&patient->phone);

}



// recieves a pointer to a struct named phone
// Get user input for phone contact information
//returns nothing

// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection;

    //prompting options for PHONE NUMBER options
    printf("Phone Information\n"
           "-----------------\n"
           "How will the patient like to be contacted?\n"
           "1. Cell\n"
           "2. Home\n"
           "3. Work\n"
           "4. TBD\n"
           "Selection: ");

        //getting selected option input via function//
        selection = inputIntPositive();

        putchar('\n');

        //if TBD//
        if (selection == 4)

                {
                    //copying content of new string to the existing//
                    strcpy(phone->description, "TBD");
                    phone->number[0] = 0;
                }

        else {
                //if CELL
                if (selection == 1)
                {
                    //copying content of new string to the existing//
                    strcpy(phone->description, "CELL");
                }

                //if HOME
                if (selection == 2)
                {
                    //copying content of new string to the existing//
                    strcpy(phone->description, "HOME");
                }

                //if WORK
                if (selection == 3)
                {
                    //copying content of new string to the existing//
                    strcpy(phone->description, "WORK");
                }

            //prompting the selected option//
            printf("Contact: %s\n", phone->description);
            printf("Number : ");

            //calling necessary function to get a C string for PHONE NUMBER//
            inputNumber(phone->number, PHONE_LEN, PHONE_LEN);
            putchar('\n');

            }

}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = NULL;

    int i = 0;

    // Open the file
    fp = fopen(datafile, "r");

    if (fp != NULL)
    {

        // Read and assign the first 3 fields into the array of struct
        while (i < max && fscanf(fp, "%d|%[^|]|%[^|]|",
                                     &patients[i].patientNumber,
                                     patients[i].name,
                                     patients[i].phone.description)==3)
        {
            // Set the phone number to empty if the description is "TBD"
            if (!strcmp(patients[i].phone.description, "TBD"))
            {
                strcpy(patients[i].phone.number, "");
            }

            // Otherwise read and assign the phone number into the array of struct
            else
            {
                fscanf(fp, "%[^\n]", patients[i].phone.number);
            }

            i++;
        }

        // Check if the file close successfully
        if (fclose(fp) == EOF)
        {
            printf("<<< ERROR:  FAILED TO CLOSE FILE >>>\n");
        }

        // Reset file pointer to a safe empty state
        fp = NULL;

    }
    else
    {
        printf("<<< ERROR:  FAILED TO OPEN FILE >>>\n");
    }

    return i;
}


// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoins[], int max)
{
    FILE* fp = NULL;

    int i = 0;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {

        // Read and assign the data into the array of struct
        while (i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d",
                                                  &appoins[i].patientNumber,
                                                  &appoins[i].date.year,
                                                  &appoins[i].date.month,
                                                  &appoins[i].date.day,
                                                  &appoins[i].time.hour,
                                                  &appoins[i].time.min) == 6)
        {
            i++;
        }

        // Check if the file close successfully
        if (fclose(fp) == EOF)
        {
            printf("<<< ERROR:  FAILED TO CLOSE FILE >>>\n");
        }

        // Reset file pointer to a safe empty state
        fp = NULL;

    }
    else
    {
        printf("<<< ERROR:  FAILED TO OPEN FILE >>>\n");
    }

    return i;
}


// recieves an array with it's length
// sorts elements of an array in ascending order
// returns nothing
void sortData(struct Appointment appoins[], int max)
{
    struct Appointment arranged;
    int i, j;
    
    for (i = 0; i < max; i++)
    {
        //converting everything into minutes
        appoins[i].time.min = (appoins[i].date.year * 12 * 30 * 24 * 60) + (appoins[i].date.month * 30 * 24 * 60)
            + (appoins[i].date.day * 24 * 60) + (appoins[i].time.hour * 60) + (appoins[i].time.min);
    }
    for (i = 0; i < max - 1; i++)
    {
        for (j = i + 1; j < max; j++)
        {
            if (appoins[j].time.min < appoins[i].time.min)
            {
                //swapping
                arranged = appoins[j];
                appoins[j] = appoins[i];
                appoins[i] = arranged;
            }
        }
    }
    for (i = 0; i < max; i++)
    {
        //expanding everything again
        appoins[i].time.min = (appoins[i].time.min) - (appoins[i].date.year * 12 * 30 * 24 * 60) - (appoins[i].date.month * 30 * 24 * 60)
            - (appoins[i].date.day * 24 * 60) - (appoins[i].time.hour * 60);
    }
}


////////////////////////////////
///#camelCaseForever
///#goCamels
///////////////////////////////
