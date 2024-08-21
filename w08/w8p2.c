/*
*****************************************************************************
                          Workshop - #8 (P2)
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
#include "w8p2.h"

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
struct CatFoodInfo getCatFoodInfo(const int sequence)
{
    
    struct CatFoodInfo inputInfo = { 0 };
    
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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* cnvrtLbs, double* cnvrtdKg)
{
    double convertedKg;
    
    convertedKg = *cnvrtLbs / LBS_TO_KG;
    
    if(cnvrtdKg != NULL)
    {
        *cnvrtdKg = convertedKg;
    }
    
    return convertedKg;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* cnvrtLbs, int* cnvrtdG)
{
    int convertedG;
    
    convertedG = convertLbsKg(cnvrtLbs, 0) * 1000;
    
    
    if(cnvrtdG != NULL)
    {
        *cnvrtdG = convertedG;
    }
    
    return convertedG;
}

// 10. convert lbs: kg and g
void convertLbs(const double* cnvrtLbs, double* cnvrtdKg, int* cnvrtdG)
{
    convertLbsKg(cnvrtLbs, cnvrtdKg);
    convertLbsG(cnvrtLbs, cnvrtdG);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int srvingSizeG, const int totalG, double* numberOfServings)
{
    double noOfServings;
    
    noOfServings = (double)totalG / (double)srvingSizeG;
    
    if(numberOfServings != NULL)
    {
        *numberOfServings = noOfServings;
    }
    
    return noOfServings;
    
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* pPrice, const double* totalServings, double* calculatedResult)
{
    double costPerServe;
    
    costPerServe = *pPrice / *totalServings;
    
    if(calculatedResult != NULL)
    {
        *calculatedResult = costPerServe;
    }
    
    return costPerServe;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* pPrice, const double* totalCalories, double* cpcResult)
{
    double costPerCal;
    
    costPerCal = *pPrice / *totalCalories;
    
    if(cpcResult != NULL)
        
    {
        *cpcResult = costPerCal;
    }
    
    return costPerCal;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catfoodinfo)
{
    struct ReportData rprtdata = { 0 };
    
    rprtdata.sku = catfoodinfo.sku;
    
    rprtdata.pPrice = catfoodinfo.price;
    
    rprtdata.calPerServing = catfoodinfo.calories;
    
    rprtdata.weightLbs = catfoodinfo.weight;
    
    rprtdata.weightKgs = convertLbsKg(&catfoodinfo.weight, NULL);
    
    rprtdata.weightGs = convertLbsG(&catfoodinfo.weight, NULL);
    
    rprtdata.totalServings = calculateServings(MAX_GRAMS, rprtdata.weightGs, NULL);
    
    rprtdata.costPerServing = calculateCostPerServing(&rprtdata.pPrice, &rprtdata.totalServings, NULL);
    
    double totalCal = rprtdata.totalServings * rprtdata.calPerServing;
    
    rprtdata.costCalPerServings = calculateCostPerCal(&rprtdata.pPrice, &totalCal, NULL);
    
    return rprtdata;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", MAX_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rprtdata, const int finalOption)
{

    
    printf("%07d %10.2lf %10.1lf % 10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
           rprtdata.sku,
           rprtdata.pPrice,
           rprtdata.weightLbs,
           rprtdata.weightKgs,
           rprtdata.weightGs,
           rprtdata.calPerServing,
           rprtdata.totalServings,
           rprtdata.costPerServing,
           rprtdata.costCalPerServings);
    
    
    if(finalOption != 0)
    {
        printf(" ***");
        
    }
    putchar('\n');
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo finalFoodInfo)
{
    printf("Final Analysis\n"
           "--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n\n", finalFoodInfo.sku, finalFoodInfo.price);
    printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------//

void start(void)
{
    int analyzeNumber, cheaper = 0;
    struct CatFoodInfo cfi[MAX_ANALYZE] = { {0} };
    struct ReportData reportdata[MAX_ANALYZE] = { {0} };
    
    //Welcome message
    openingMessage(MAX_ANALYZE);
    
    putchar('\n');
    
    //User input for cat food info...
    for (analyzeNumber = 0; analyzeNumber < (MAX_ANALYZE); analyzeNumber++)
    {
        cfi[analyzeNumber] = getCatFoodInfo(analyzeNumber + 1);
        putchar('\n');
    }
    
 
    
    //displaying cat food info table header...
    displayCatFoodHeader();
    
    //displaying cat food info table...
    for (analyzeNumber = 0; analyzeNumber < (MAX_ANALYZE); analyzeNumber++)
    {
        displayCatFoodData(cfi[analyzeNumber].sku, &cfi[analyzeNumber].price, cfi[analyzeNumber].calories, &cfi[analyzeNumber].weight);
    }
    
    //filling report data with corresponding function...
    for (analyzeNumber = 0; analyzeNumber < (MAX_ANALYZE); analyzeNumber++)
    {
    
        reportdata[analyzeNumber] = calculateReportData(cfi[analyzeNumber]);
    }
    
    putchar('\n');
    
    //displaying header for report data table...
    displayReportHeader();
    
   
    
    //finding the cheapest product out of all...
    for (analyzeNumber = 0; analyzeNumber < (MAX_ANALYZE); analyzeNumber++)
    {
        if(reportdata[analyzeNumber].costPerServing < reportdata[cheaper].costPerServing)
        {
            cheaper = analyzeNumber;
        }
    }
        
    //Logic behind printing 3 stars at the end of the cheapest product...
    for (analyzeNumber = 0; analyzeNumber < MAX_ANALYZE; analyzeNumber++)
    {
        if(analyzeNumber == cheaper)
        {
            displayReportData(reportdata[analyzeNumber], 1);
        }
        
        else
        {
            displayReportData(reportdata[analyzeNumber], 0);
        }
        
    }
    

    putchar('\n');
    
    //Goodbye message...
    displayFinalAnalysis(cfi[cheaper]);
    
    //END
    
 }
