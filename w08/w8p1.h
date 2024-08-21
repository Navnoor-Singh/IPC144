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

#define MAX_ANALYZE 3
#define MAX_GRAMS 64

// ----------------------------------------------------------------------------
// structures

struct catFoodInfo
{
    int sku;
    double price;
    int calories;
    double weight;
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
struct catFoodInfo getCatFoodInfo(const int sequence);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* pricePtr, const int calories, const double* weightPtr);


// 7. Logic entry point
void start(void);
