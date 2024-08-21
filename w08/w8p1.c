/*
*****************************************************************************
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>


// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr)
{
    int inputint, valid;

    do
    {
        scanf("%d", &inputint);
        valid = 1;

        if (inputint <= 0)
        {
            printf("ERROR: Enter a positive value: ");
            valid = 0;
        }

    } while (!valid);
    
    if (intPtr != NULL)
    {
        *intPtr = inputint;
    }

    return inputint;

}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePtr)
{
    double inputdbl;
    int valid;

    do
    {
        scanf("%lf", &inputdbl);
        valid = 1;

        if (inputdbl <= 0)
        {
            printf("ERROR: Enter a positive value: ");
            valid = 0;
        }

    } while (!valid);
    
    if (doublePtr != NULL)
    {
        *doublePtr = inputdbl;
    }

    return inputdbl;

}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int analyzeCount)
{
    printf("Cat Food Cost Analysis\n"
           "======================\n\n");
    
    printf("Enter the details for %d dry food bags of product data for analysis.\n"
           "NOTE: A 'serving' is %dg\n", analyzeCount, MAX_GRAMS);
    
    
}

// 4. Get user input for the details of cat food product
struct catFoodInfo getCatFoodInfo(const int sequence)
{
    
    struct catFoodInfo inputInfo = { 0 };
    
    printf("Cat Food Product #%d\n"
           "--------------------\n", sequence);
    
    printf("SKU           : ");
    inputInfo.sku = getIntPositive(NULL);
    
    printf("PRICE         : $");
    getDoublePositive(&inputInfo.price);
    
    printf("WEIGHT (LBS)  : ");
    inputInfo.weight = getDoublePositive(NULL);
    
    printf("CALORIES/SERV.: ");
    getIntPositive(&inputInfo.calories);
    
    return inputInfo;
    
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}



// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* pricePtr, const int calories, const double* weightPtr)
{

    printf("%07d %10.2lf %10.1lf %8d\n",
           sku, *pricePtr, *weightPtr, calories);
    
}

// 7. Logic entry point

void start(void)
{
    int analyzeNumber;
    struct catFoodInfo cfi[MAX_ANALYZE] = { {0} };
    
    
    openingMessage(MAX_ANALYZE);
    
    putchar('\n');
    
    for (analyzeNumber = 1; analyzeNumber < (MAX_ANALYZE + 1); analyzeNumber++)
    {
        cfi[analyzeNumber-1] = getCatFoodInfo(analyzeNumber);
        putchar('\n');
    }
   
    displayCatFoodHeader();
    
    for (analyzeNumber = 1; analyzeNumber < (MAX_ANALYZE + 1); analyzeNumber++)
    {
        displayCatFoodData(cfi[analyzeNumber - 1].sku, &cfi[analyzeNumber - 1].price, cfi[analyzeNumber - 1].calories, &cfi[analyzeNumber - 1].weight);
    }
    
 }
