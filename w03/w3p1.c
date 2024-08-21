/*
*****************************************************************************
                          Workshop - #3 (P1)
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

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    const int productIDP1 = 111;
    const int productIDP2 = 222;
    const int productIDP3 = 111;
    const double priceP1 = 111.49;
    const double priceP2 = 222.99;
    const double priceP3 = 334.49;
    const char taxedP1 = 'Y';
    const char taxedP2 = 'N';
    const char taxedP3 = 'N';
    int average;
    
    
    printf("Product Information\n"
           "===================\n");
    printf("Product-1 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%8.4lf\n\n", productIDP1, taxedP1, priceP1);
    
    printf("Product-2 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%8.4lf\n\n", productIDP2, taxedP2, priceP2);
    
    printf("Product-3 (ID:%d)\n"
           "  Taxed: %c\n"
           "  Price: $%8.4lf\n\n", productIDP3, taxedP3, priceP3);
    
    
    //average
    average = (int)((((priceP1 + priceP2 + priceP3) / 3) + 0.005) * 100);
    printf("The average of all prices is: $%8.4lf\n\n", average / 100.0000);
    printf("About Relational and Logical Expressions!\n"         "========================================\n"
           "1. These expressions evaluate to TRUE or FALSE\n"
           "2. FALSE: is always represented by integer value 0\n"
           "3. TRUE : is represented by any integer value other than 0\n\n");
    
    printf("Some Data Analysis...\n"
           "=====================\n");
    
    printf("1. Is product 1 taxable? -> %d\n\n" ,(taxedP1 == 'Y'));
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", taxedP2 == 'N' && taxedP3 == 'N');
    printf("3. Is product 3 less than testValue ($%3.2lf)? -> %d\n\n", testValue, priceP3 < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", priceP3 > (priceP1 + priceP2));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%4.2lf)\n\n", priceP1 >= (priceP3 - priceP2) , (priceP3 - priceP2));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", priceP2 >= (average/100.0000));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", productIDP1 != productIDP2 && productIDP1 != productIDP3);
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", productIDP2 != productIDP1 && productIDP2 != productIDP3);
    printf("9. Based on product ID, product 3 is unique -> %d\n\n", productIDP3 != productIDP1 && productIDP3 != productIDP2);
    
    return 0;
}
