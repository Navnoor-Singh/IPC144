/*
*****************************************************************************
                          Workshop - #6 (P2)
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

#define MAX_ITEMS 10

int main(void)
{
    const double minMonthlyInc = 500.00;
    const double maxCost = 100;
    const double maxMonthlyInc = 400000.00;
    double monthlyInc, total, totalMonths, totalYears, monDiff;
    double itemCost[MAX_ITEMS] = { 0.0 };
    int itemPriority[MAX_ITEMS] = { 0 };
    char itemFinance[MAX_ITEMS] = { 0 };
    int itemCount, i, valid, print, forecastOption, priorityOption;
    
    
    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n\n");
    
    //getting monthly income from user...
    do{
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyInc);
        
        if(monthlyInc < minMonthlyInc)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", minMonthlyInc);
            valid = 0;
        }
        
        if(monthlyInc > maxMonthlyInc)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", maxMonthlyInc);
            valid = 0;
        }
        
        putchar('\n');
      } while (!valid);
    
    //getting number of items from user...
    do{
        valid = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemCount);
        
        if(itemCount <= 0 || itemCount > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and %d items.\n", MAX_ITEMS);
            valid = 0;
        }
        
        putchar('\n');
      } while (!valid);
    
    
    //get input from user...
    for (i = 0; i < itemCount ; i++)
      {
        printf("Item-%d Details:\n", i+1);
        
        //getting cost from the user...
        do{
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            
            if((itemCost[i]) < maxCost)
            {
                printf("      ERROR: Cost must be at least $%.2lf\n", maxCost);
                valid = 0;
            }
            
          } while (!valid);
        
       //getting priority from the user...
       do{
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            
            if(itemPriority[i] <= 0 || itemPriority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
                valid = 0;
            }
            
          } while (!valid);
        
       //getting finance options from the user...
       do{
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinance[i]);
            
            if(!((itemFinance[i] == 'n') || (itemFinance[i] == 'y')))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                valid = 0;
            }
            
          } while (!valid);
            putchar('\n');
    }
    
    //Summary table
        printf("Item Priority Financed        Cost\n"
               "---- -------- -------- -----------\n");
    for (i = 0 , total = 0; i < itemCount ; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemFinance[i], itemCost[i]);
        total += itemCost[i];
    }
        printf("---- -------- -------- -----------\n");
        printf("                      $%11.2lf\n\n", total);
    
    //main forecaster
    do{
        valid = 1;
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n"
               " 2. By priority\n"
               " 0. Quit/Exit\n"
               "Selection: ");
        scanf("%d", &forecastOption);
        putchar('\n');
        
        if(forecastOption > 2)
        {
            printf("ERROR: Invalid menu selection.\n");
            valid = 0;
        }
        
        if(forecastOption == 1)
            
        {
           printf("====================================================\n");
           printf("Filter:   All items\n");
           printf("Amount:   $%.2lf\n", total);
           
           //time logic
           totalYears = ((total / monthlyInc) / 12);
           totalMonths = (int)(total / monthlyInc) % 12;
           monDiff = (total / monthlyInc) - (int)(total / monthlyInc);
           
           if(monDiff > 0)
           {
               totalMonths++;
           }
           printf("Forecast: %d years, %d months\n", (int)totalYears, (int)totalMonths);
           
           
           for (i = 0 , print = 0; i < itemCount ; i++)
           {
               if(itemFinance[i] == 'y')
               {
                   print = 1;
               }
           }
            
           if(print == 1)
           {
               printf("NOTE: Financing options are available on some items.\n"
                      "      You can likely reduce the estimated months.\n");
           }
               printf("====================================================\n");
           valid = 0;
        }
        
    
        if(forecastOption == 2)
        {
            
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityOption);
            putchar('\n');
            do{
                valid = 1;
                
                if(priorityOption < 0 || priorityOption > 3)
                {
                    printf("ERROR: Invalid priority selection.\n");
                    valid = 0;
                }
                
                //First priority
                if(priorityOption == 1)
                {
                    printf("====================================================\n");
                    printf("Filter:   by priority (1)\n");
                    for(i = 0 , total = 0; i < itemCount ; i++)
                    {
                        if(itemPriority[i] == priorityOption)
                        {
                        total += itemCost[i];
                        }
                }
                    printf("Amount:   $%.2lf\n", total);
                    
                    
                    totalYears = ((total / monthlyInc)/ 12);
                    totalMonths = (int)(total / monthlyInc) % 12;
                    monDiff = (total / monthlyInc) - (int)(total / monthlyInc);
                    
                    if(monDiff > 0)
                    {
                        totalMonths++;
                    }
                    
                    printf("Forecast: %d years, %d months\n", (int)totalYears, (int)totalMonths);
        
                    valid = 1;
                }
                
                //Second priority
                if(priorityOption == 2)
                {
                    printf("====================================================\n");
                    printf("Filter:   by priority (2)\n");
                    for(i = 0 , total = 0; i < itemCount ; i++)
                    {
                        if(itemPriority[i] == priorityOption)
                        {
                        total += itemCost[i];
                        }
                    }
                    printf("Amount:   $%.2lf\n", total);
                    
                    
                    totalYears = ((total / monthlyInc)/ 12);
                    totalMonths = (int)(total / monthlyInc) % 12;
                    monDiff = (total / monthlyInc) - (int)(total / monthlyInc);
                    
                    if(monDiff > 0)
                    {
                        totalMonths++;
                    }
                    printf("Forecast: %d years, %d months\n", (int)totalYears, (int)totalMonths);
        
                    valid = 1;
                }
                
                // Third priority
                if(priorityOption == 3)
                {
                    printf("====================================================\n");
                    printf("Filter:   by priority (3)\n");
                    for(i = 0 , total = 0; i < itemCount ; i++)
                    {
                        if(itemPriority[i] == priorityOption)
                        {
                        total += itemCost[i];
                        }
                    }
                    printf("Amount:   $%.2lf\n", total);
                    
                    
                    totalYears = ((total / monthlyInc)/ 12);
                    totalMonths = (int)(total / monthlyInc) % 12;
                    monDiff = (total / monthlyInc) - (int)(total / monthlyInc);
                    
                    if(monDiff > 0)
                    {
                        totalMonths++;
                    }
                    
                    printf("Forecast: %d years, %d months\n", (int)totalYears, (int)totalMonths);
                    
                    valid = 1;
                }
                
                //note
                for (i = 0 , print = 0; i < itemCount ; i++)
                {
                    if(itemFinance[i] == 'y' && itemPriority[i] == priorityOption)
                    {
                        print = 1;
                    }
                }
                
                if(print == 1)
                {
                    printf("NOTE: Financing options are available on some items.\n"
                           "      You can likely reduce the estimated months.\n");
                }
                    printf("====================================================\n");
                
            }while(!valid);
            valid = 0;
        }
        //loop exit
        if(forecastOption == 0)
        {
            printf("Best of luck in all your future endeavours!\n");
            valid = 1;
        }
    
        putchar('\n');
      } while(!valid);

    return 0;
}


