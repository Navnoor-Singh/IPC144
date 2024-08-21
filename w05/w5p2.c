/*
*****************************************************************************
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

#include <stdio.h>

int main(void)
{
    const int JAN = 1;
    const int DEC = 12;
    int monthNumber, yearNumber, loopCount;
    double morningRating, eveningRating, morningTotal, eveningTotal;
    
    
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
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
        
      }while(((yearNumber < MIN_YEAR || yearNumber > MAX_YEAR) || (((monthNumber < JAN) || (monthNumber > DEC)))));
    
    printf("\n*** Log date set! ***\n\n");
    
    //repeater...
    
    for (loopCount = 0 , morningTotal = 0 , eveningTotal = 0; loopCount < LOG_DAYS; loopCount++)
    {
        
        //month selector...
        switch (monthNumber)
        {
            case 1 :
                printf("%d-JAN-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 2 :
                printf("%d-FEB-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 3 :
                printf("%d-MAR-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 4 :
                printf("%d-APR-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 5 :
                printf("%d-MAY-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 6 :
                printf("%d-JUN-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 7 :
                printf("%d-JUL-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 8 :
                printf("%d-AUG-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 9 :
                printf("%d-SEP-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 10 :
                printf("%d-OCT-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 11 :
                printf("%d-NOV-0%d\n", yearNumber, loopCount+1);
                break;
                
            case 12 :
                printf("%d-DEC-0%d\n", yearNumber, loopCount+1);
                break;
                
            default :
                break;
        }
        
        // ratings logic...
        do{
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if((morningRating < 0) || (morningRating > 5))
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            
        }while(((morningRating < 0) || (morningRating > 5)));
        morningTotal += morningRating;
        
        do{
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if((eveningRating < 0) || (eveningRating > 5))
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
            
        } while(((eveningRating < 0) || (eveningRating > 5)));
        
        eveningTotal += eveningRating;
        putchar('\n');
    }
    
    // Summary...
    
    printf("Summary\n"
           "=======\n");
    printf("Morning total rating: %.3lf\n", morningTotal);
    printf("Evening total rating:  %.3lf\n", eveningTotal);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", (morningTotal + eveningTotal));
    printf("Average morning rating:  %.1lf\n", (morningTotal/loopCount));
    printf("Average evening rating:  %.1lf\n", (eveningTotal/loopCount));
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", (((morningTotal/loopCount) + (eveningTotal/loopCount)) / 2));
    
    return 0;
}
