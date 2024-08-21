/*
*****************************************************************************
                          Workshop - #6 (P1)
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
#define MAX_ITEMS 10

#include <stdio.h>

int main(void)
{
    const double minMonthlyInc = 500.00;
    const double maxCost = 100;
    const double maxMonthlyInc = 400000.00;
    double monthlyInc, total;
    double itemCost[MAX_ITEMS] = { 0.0 };
    int itemPriority[MAX_ITEMS] = { 0 };
    char itemFinance[MAX_ITEMS] = { 0 };
    int itemCount, i, true;
    
    
    printf("+--------------------------+\n"
           "+   Wish List Forecaster   |\n"
           "+--------------------------+\n\n");
    
    //getting monthly income from user...
    do{
        true = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthlyInc);
        
        if(monthlyInc < minMonthlyInc)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
            true = 0;
        }
        
        if(monthlyInc > maxMonthlyInc)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
            true = 0;
        }
        
        putchar('\n');
    } while (!true);
    
    //getting number of items from user...
    do{
        true = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &itemCount);
        
        if(itemCount <= 0 || itemCount > MAX_ITEMS)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
            true = 0;
        }
        
        putchar('\n');
    } while (!true);
    
    
    //get input from user...
    for (i = 0; i < itemCount ; i++)
    {
        printf("Item-%d Details:\n", i+1);
        
        //getting cost from the user...
        do{
            true = 1;
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            
            if((itemCost[i]) < maxCost)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
                true = 0;
            }
            
        } while (!true);
        
        //getting priority from the user...
        do{
            true = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);
            
            if(itemPriority[i] <= 0 || itemPriority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
                true = 0;
            }
            
        } while (!true);
        
        //getting finance options from the user...
        do{
            true = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinance[i]);
            
            if(!((itemFinance[i] == 'n') || (itemFinance[i] == 'y')))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
                true = 0;
            }
            
        } while (!true);
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
        printf("Best of luck in all your future endeavours!\n");
    return 0;
}
