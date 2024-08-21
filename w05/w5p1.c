/*
*****************************************************************************
                          Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022

#include <stdio.h>

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int monthNumber, yearNumber;
    
    printf("General Well-being Log\n"
           "======================\n");
    
    //main logic...
    do{
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &yearNumber, &monthNumber);
        
        if(yearNumber < MIN_YEAR || yearNumber > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %4d and %4d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        
        if((monthNumber < JAN) || (monthNumber > DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        
      }while(((yearNumber < MIN_YEAR || yearNumber > MAX_YEAR) || (((monthNumber < JAN) || (monthNumber > DEC)))));
    
    printf("\n*** Log date set! ***\n\n");
    
    //month selector...
     switch (monthNumber)
     {
         case 1 :
             printf("Log starting date: %d-JAN-01\n", yearNumber);
             break;
             
         case 2 :
             printf("Log starting date: %d-FEB-01\n", yearNumber);
             break;
             
         case 3 :
             printf("Log starting date: %d-MAR-01\n", yearNumber);
             break;
             
         case 4 :
             printf("Log starting date: %d-APR-01\n", yearNumber);
             break;
             
         case 5 :
             printf("Log starting date: %d-MAY-01\n", yearNumber);
             break;
             
         case 6 :
             printf("Log starting date: %d-JUN-01\n", yearNumber);
             break;
             
         case 7 :
             printf("Log starting date: %d-JUL-01\n", yearNumber);
             break;
             
         case 8 :
             printf("Log starting date: %d-AUG-01\n", yearNumber);
             break;
             
         case 9 :
             printf("Log starting date: %d-SEP-01\n", yearNumber);
             break;
             
         case 10 :
             printf("Log starting date: %d-OCT-01\n", yearNumber);
             break;
             
         case 11 :
             printf("Log starting date: %d-NOV-01\n", yearNumber);
             break;
             
         case 12 :
             printf("Log starting date: %d-DEC-01\n", yearNumber);
             break;
             
         default :
             break;
             
     }
    
    return 0;
}
