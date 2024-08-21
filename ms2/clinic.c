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

#define _CRT_SECURE_NO_WARNINGS
//system lib//
#include <stdio.h>
//string lib//
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
            printf("<<< Feature not yet available >>>\n\n");
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
    
            break;
        case 4:
            editPatient(patient, max);

            break;
        case 5:
                removePatient(patient, max);
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


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
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
        suspend();
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
        suspend();
    
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
    tmpPatientNum = inputInt();
    
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
        suspend();
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
    int i, valid = -1, tmpPatientNum, index;
    int selection;
    
    //getting the patient number which user want to remove//
    printf("Enter the patient number: ");
    
    //calling necessary function to get the input//
    tmpPatientNum = inputInt();
    
    //getting index number of the entered patient number//
    index = findPatientIndexByPatientNum(tmpPatientNum, patient, max);
    
    //iterating over the whole list of patients//
    for (i = 0 ; i < max ; i++)
    {
        //cheking if there was no index found
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
    
    //printing error message if index not found//
    if(!valid)
    {
        putchar('\n');
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
        suspend();
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
            suspend();
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
    int big = 0 , i;
    
    //iterating over the whole list of patients//
    for (i = 0; i < max; i++)
    {
        //setting the biggest number//
        big = patient[i].patientNumber;
    }
    
    //iterating over the whole list of patients//
    for(i = 0 ; i < max ; i++)
    {
        //comparing every number by the biggest//
        if (patient[i].patientNumber > big)
        {
            
            //assigning the big again//
            big = patient[i].patientNumber;
        }
        
    }
    // returning the big + 1//
    return big + 1;
    
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
        selection = inputInt();
    
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
            inputCString(phone->number, PHONE_LEN, PHONE_LEN);
            putchar('\n');
            
            }
    
}

//END//

// #camelCaseForever !! //
// #goCamels !! //
