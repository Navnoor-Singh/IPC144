/*
*****************************************************************************
                          Workshop - #4 (P1)
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

int main(void)
{
    int count, loops;
    char loopType;
    
    /* code starts from here... */
    printf("+----------------------+\n"
           "Loop application STARTED\n"
           "+----------------------+");
    do{  // Main repeater..
    putchar('\n');
    putchar('\n');
    printf("D = do/while | W = while | F = for | Q = quit\n"
           "Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", &loopType, &loops);

    /* Main logic */
    
    switch (loopType)
    {
     case 'F' :
                    
            if(loops>=3 && loops<=20)
                {
                    printf("FOR     : ");
                    for (count = 0; count < loops; count++)
                    {
                        printf("%c", loopType);
                    }
                }
            else
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
                    
    break;
            
    case 'W' :
           if(loops>=3 && loops<=20)
                        
               {
                    count = 0;
                    printf("WHILE   : ");
                    while (count < loops)
                    {
                        printf("%c", loopType);
                        count++;
                    }
                }
                    
           else
                        
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                }
    break;
            
    case 'D' :
           if(loops>=3 && loops<=20)
               
               {   count = 0;
                   printf("DO-WHILE: ");
                   do
                   {
                       printf("%c", loopType);
                       count++;
                   } while (count < loops);
               }
                    
           else
               {
                   printf("ERROR: The number of iterations must be between 3-20 inclusive!");
               }
    break;
            
    case 'Q' :
           if(loops > 0 || loops < 0)
               {
                   printf("ERROR: To quit, the number of iterations should be 0!");
               }
    break;
                    
    default:
                   printf("ERROR: Invalid entered value(s)!");
   }
      
   /* Repeater logic */
   } while (!(loopType == 'Q') || (!(loops == 0)));
    putchar('\n');
    printf("+--------------------+\n"
           "Loop application ENDED\n"
           "+--------------------+\n\n");
   
    
    return 0;
    
}
