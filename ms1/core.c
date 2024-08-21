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


#define _CRT_SECURE_NO_WARNINGS

//System lib//
#include <stdio.h>
#include <ctype.h>

//header file//
#include "core.h"


//FUNCTIONS//

//clears the buffer//
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

//suspend//
void suspend(void)
{
printf("<ENTER> to continue..."); clearInputBuffer(); putchar('\n');
}

//gets a valid int input//
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



//gets only a positive int//
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



//checks range for input//
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
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
            rValid = 0;
        }
    //exit
    }while(!rValid);
    
    return range;
}



//gets and validates a single character//
char inputCharOption(const char* valid)
{
    char singleInput;
    int cValid, i;
    
    do
    {
        
        cValid = 1;
        scanf(" %c", &singleInput);
        
        for (i = 0 ; valid[i] != '\0' ; i++)
        {
            //validating character by character
            if(valid[i] == singleInput)
            {
                //flag
                cValid = 0;
            }
            
        }
        
        if(cValid == 1)
        {
            printf("ERROR: Character must be one of [qwErty]: ");
        }
    //exit
    }while(cValid);
    clearInputBuffer();
    
    return singleInput;
}



//gets and validates a C string//
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
        //assigning the array - POPULATING
        for (i = 0 ; tmpString[i] != '\0' ; i++)
        {
            cString[i] = tmpString[i];
        }
        //assigning the end byte
        cString[i] = '\0';
    }
    
}



//displays a formatted phone number//
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
        if(i != PHONE_LENGTH)
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

//END//
