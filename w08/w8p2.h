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

#define MAX_ANALYZE 3
#define MAX_GRAMS 64
#define LBS_TO_KG 2.20462

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
};

struct ReportData
{
    int sku;
    double pPrice;
    int calPerServing;
    double weightLbs;
    double weightKgs;
    int weightGs;
    double totalServings;
    double costPerServing;
    double costCalPerServings;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePtr);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int analyzeCount);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequence);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* pricePtr, const int calories, const double* weightPtr);


// 7. Logic entry point
//void start(void);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* cnvrtLbs, double* cnvrtdKg);

// 9. convert lbs: g
int convertLbsG(const double* convrtLbs, int* cnvrtdG);

// 10. convert lbs: kg / g
void convertLbs(const double* cnvrtLbs, double* cnvrtdKg, int* cnvrtdG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int srvingSizeG, const int totalG, double* numberOfServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* pPrice, const double* totalServings, double* calculatedResult);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* pPrice, const double* totalCalories, double* cpcResult);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catfooddata);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rprtdata, const int finalOption);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo finaldata);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
