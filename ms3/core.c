/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Navnoor Singh
patient ID#: 160821211
Email      : nsingh391@myseneca.ca
Section    : ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other patient or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// recieves nothing
// gets a valid int input
// returns an integer

int inputInt(void)
{
    int input, isValid;
    char nLine;

    do {
        
        isValid = 1;
        
        scanf("%d%c", &input, &nLine);
        
        //checking for newline
        if(nLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
            isValid = 0;
        }
    
        if (nLine == '\n')
        {
            isValid = 1;
        }
        
    //exit
    }while(!isValid);
        
    return input;
}


// recieves nothing
// gets only a positive int
// returns a positive integer

int inputIntPositive(void)
{
    
    int posInput, posValid;
    
    do
    {
        posValid = 1;
        
        //calling neccesary function
        posInput = inputInt();
        
        //checking if the number is > 0
        if(posInput < 0)
        {
            printf("ERROR! Value must be > 0: ");
            posValid = 0;
        }
    //exit
    }while(!posValid);
    
    return posInput;
    
}


// recieves lower and upper bound
// checks range for input
// returns an integer within the range

int inputIntRange(int lBound, int uBound)
{
    int range, rValid;

    do
    {
        rValid = 1;
       
        //calling neccesary function
        range = inputInt();
        
        //checking upper and lower bounds
        if(range < lBound || range > uBound)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lBound, uBound);
            rValid = 0;
        }
    //exit
    }while(!rValid);
    
    return range;
}


// recieves an unmodifiable string
// gets and validates a single character
// returns a char

char inputCharOption(const char* valid)
{
    char singleInput, bufferEnd = '\0';
    int  isCharMatched;
    char* match;

    do
    {
        //getting input char from usier and the following char
        isCharMatched = 0;
        scanf("%c%c", &singleInput, &bufferEnd);
        //if the following char isnt a newline character clear input buffer
        if (bufferEnd != '\n')
        {
            clearInputBuffer();
        }
        else
        {
            //if following character was a newline check if input character is inside the valid string
            match = strrchr(valid, singleInput);
            if (match != NULL)
            {
                //if the return of strrchr is anything but NULL set flag for matching char to 1
                isCharMatched = 1;
            }

        }
        //if there was no match print error message
        if (!isCharMatched)
        {
            printf("ERROR: Character must be one of [%s]: ", valid);
        }
        
        //keep looping untill a character matches the valid list
    } while (!isCharMatched);

    //return the character if its in the valid list
    return singleInput;
}



// recieves a pointer to a string, MIN and MAX
// gets and validates a C string
// returns nothing

void inputCString(char* cString, int min, int max)
{
    int i, outOfBounds;
    char tmpString[499 + 1] = { 0 };
    
    do
    {
        outOfBounds = 0;
        
        scanf("%500[^\n]%*c", tmpString);
        
        for (i = 0; tmpString[i] != '\0' ; i++);
        
        //checking if the range is out of bounds
        if(i > max || i < min)
        {
            outOfBounds = 1;
            
            //if the min,max are exactly the same
            if( min == max )
            {
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            
            //if the range is less than the min
            else if(i < min)
            {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
            
            //if the range is more than the max
            else if(i > max)
            {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
        }
        
        else
        {
            outOfBounds = 0;
        }
        
    //exit
    }while(outOfBounds);
    
    //checking is the address is NULL
    if(cString != NULL)
    {
        strcpy(cString, tmpString);
    }
    
}


void inputNumber(char* cString, int min, int max)
{
    int i, outOfBounds;
    char tmpString[499 + 1] = { 0 };
    
    do
    {
        outOfBounds = 0;
        
        scanf("%500[^\n]%*c", tmpString);
        
        for (i = 0; tmpString[i] != '\0' ; i++);
        
        //checking if the range is out of bounds
        if(i > max || i < min)
        {
            outOfBounds = 1;
            
            //if the min,max are exactly the same
            if( min == max )
            {
                printf("Invalid %d-digit number! Number: ", max);
            }
            
            //if the range is less than the min
            else if(i < min)
            {
                printf("Invalid %d-digit number! Number: ",max);
            }
            
            //if the range is more than the max
            else if(i > max)
            {
                printf("Invalid %d-digit number! Number: ", max);
            }
        }
        
        else
        {
            outOfBounds = 0;
        }
        
    //exit
    }while(outOfBounds);
    
    //checking is the address is NULL
    if(cString != NULL)
    {
        strcpy(cString, tmpString);
    }
    
}



// recieves a pointer to unmodifiable string
// displays a formatted phone number
// returns nothing

void displayFormattedPhone(const char* phoneString)
{
    int isValid = 1, i;

    //checking if the address is NULL
    if(phoneString == NULL)
    {
        isValid = 0;
    }
        
    else
    {
        for (i = 0; phoneString[i] != '\0' ; i++)
        {
            //checking if the character is a digit
            if(!isdigit(phoneString[i]))
            {
                isValid = 0;
            }
            
        }
        
        //checking the length of the number
        if(strlen(phoneString) != PHONE_LEN)
        {
            isValid = 0;

        }
    }
    
    //logic
    if(isValid)
    {
        printf("(%.3s)%.3s-%.4s", phoneString, phoneString + 3, phoneString + 6);
    }
    else
    {
        printf("(___)___-____");
    }
    
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////




//writedata


    
