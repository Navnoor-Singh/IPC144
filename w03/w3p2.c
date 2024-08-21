
/*
*****************************************************************************
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char productTypeC1, productGrindsizeC1, productCreamC1, productTypeC2, productGrindsizeC2, productCreamC2, productTypeC3, productGrindsizeC3, productCreamC3, coffeeStrength, maker, prefCream;
    double productTempC1, productTempC2, productTempC3;
    int productWeightC1, productWeightC2, productWeightC3, dailyServings;

    // Note:
    // You can convert Celsius to Fahrenheit given the following formula:
    // fahrenheit = (celsius * 1.8) + 32.0);
    
    
    printf("Take a Break - Coffee Shop\n"
          "==========================\n\n"
           "Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n"
           "Type ([L]ight,[B]lend): ");
    scanf(" %c", &productTypeC1);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &productGrindsizeC1);
    printf("Bag weight (g): ");
    scanf("%d", &productWeightC1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &productCreamC1);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &productTempC1);
    
    //coffee-2
    
    printf("\nCOFFEE-2...\n"
           "Type ([L]ight,[B]lend): ");
    scanf(" %c", &productTypeC2);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &productGrindsizeC2);
    printf("Bag weight (g): ");
    scanf("%d", &productWeightC2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &productCreamC2);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &productTempC2);
    
    //coffee-3
    
    printf("\nCOFFEE-3...\n"
           "Type ([L]ight,[B]lend): ");
    scanf(" %c", &productTypeC3);
    printf("Grind size ([C]ourse,[F]ine): ");
    scanf(" %c", &productGrindsizeC3);
    printf("Bag weight (g): ");
    scanf("%d", &productWeightC3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &productCreamC3);
    printf("Ideal serving temperature (Celsius): ");
    scanf("%lf", &productTempC3);
    putchar('\n');
    
    //table
    
    printf("---+---------------+---------------+---------------+-------+--------------\n"
           "   |    Coffee     |    Coffee     |   Packaged    | Best  |   Serving\n"
           "   |     Type      |  Grind Size   |  Bag Weight   | Served| Temperature\n"
           "   +---------------+---------------+---------------+ With  +--------------\n"
           "ID | Light | Blend | Course | Fine |  (G) | Lbs    | Cream |   (C) |   (F)\n"
           "---+---------------+---------------+---------------+-------+--------------\n");
    
    printf(" 1 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
           (productTypeC1 == 'L' || productTypeC1 == 'l') ,
           (productTypeC1 == 'B' || productTypeC1 == 'b'),
           (productGrindsizeC1 == 'C' || productGrindsizeC1 == 'c'),
           (productGrindsizeC1 == 'F' || productGrindsizeC1 == 'f'),
           (productWeightC1), (productWeightC1 / GRAMS_IN_LBS),
           ((productCreamC1 == 'Y' || productCreamC1 == 'y') ||    !(productCreamC1=='N'||productCreamC1 == 'n')),
           productTempC1,  (productTempC1 * 1.8) + 32.0);
    
    
    printf(" 2 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n",
           (productTypeC2 == 'L' || productTypeC2 == 'l'),
           (productTypeC2 == 'B' || productTypeC2 == 'b'),
           (productGrindsizeC2 == 'C' || productGrindsizeC2 == 'c'),
           (productGrindsizeC2 == 'F' || productGrindsizeC2 == 'f'),
           (productWeightC2), (productWeightC2 / GRAMS_IN_LBS),
           ((productCreamC2 == 'Y' || productCreamC2 == 'y') || !(productCreamC2=='N'||productCreamC2 == 'n')),
           productTempC2,  (productTempC2 * 1.8) + 32.0);
    
    
    printf(" 3 |   %d   |   %d   |    %d   |   %d  | %4d | %6.3lf |   %d   | %5.1lf | %5.1lf\n\n",
           (productTypeC3 == 'L' || productTypeC3 == 'l'),
           (productTypeC3 == 'B' || productTypeC3 == 'b'),
           (productGrindsizeC3 == 'C' || productGrindsizeC3 == 'c'),
           (productGrindsizeC3 == 'F' || productGrindsizeC3 == 'f'),
           productWeightC3, (productWeightC3 / GRAMS_IN_LBS),
           ((productCreamC3 == 'Y' || productCreamC3 == 'y') || !(productCreamC3=='N'||productCreamC3 == 'n')),
           productTempC3,  (productTempC3 * 1.8) + 32.0);
    
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    putchar('\n');
    printf("The below table shows how your preferences align to the available products:\n\n");
    
    printf("--------------------+--------------------+-------------+-------+--------------\n"
           "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
           "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
           "--+-----------------+--------------------+-------------+-------+--------------\n");
    
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC1 == 'l' || productTypeC1 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC1 == 'b' || productTypeC1 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC1 == 'c' || productGrindsizeC1 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC1 == 'f' || productGrindsizeC1 == 'F')),
           
           (dailyServings > 0 && dailyServings <= 4 && (productWeightC1 > 0 && productWeightC1 <= 250)),                             //packaged bag weight
           
           ((prefCream == 'y' || prefCream == 'Y')  && (productCreamC1 == 'y'  || productCreamC1 =='Y')),                            //with cream
           
           ((maker == 'r'     ||   maker == 'R')    &&   (productTempC1 > 60.0 && productTempC1 <= 69.9)) ||                         //serving temperature
           ((maker == 'c'     ||   maker == 'C')    &&   (productTempC1 >=70.0 && productTempC1 < 1000.0)));
    
    
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC2 == 'l' || productTypeC2 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC2 == 'b' || productTypeC2 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC2 == 'c' || productGrindsizeC2 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC2 == 'f' || productGrindsizeC2 == 'F')),
        
           (dailyServings >= 5 && dailyServings <= 9 && productWeightC2 == 500),                                                     //packaged bag weight
           
           ((prefCream == 'y'  || prefCream == 'Y')  && (productCreamC2 == 'y'  || productCreamC2 =='Y')),                              //with cream
           
           ((maker == 'r'      ||   maker == 'R')    &&   (productTempC2 > 60.0 && productTempC2 <= 69.9)) ||                           //serving temperature
           ((maker == 'c'      ||   maker == 'C')    &&   (productTempC2 >=70.0 && productTempC2 < 1000.0)));
    
    
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC3 == 'l' || productTypeC3 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC3 == 'b' || productTypeC3 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC3 == 'c' || productGrindsizeC3 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC3 == 'f' || productGrindsizeC3 == 'F')),
        
           (dailyServings >= 10 && dailyServings <= 100 && productWeightC3 == 1000),                                                 //packaged bag weight
           
           ((prefCream == 'y'   || prefCream == 'Y') && (productCreamC3 == 'y' || productCreamC3 =='Y')),                              //with cream
           
           ((maker == 'r'       ||   maker == 'R')   &&  (productTempC3 > 60.0 && productTempC3 <= 69.9)) ||                           //serving temperature
           ((maker == 'c'       ||   maker == 'C')   &&  (productTempC3 >=70.0 && productTempC3 < 1000.0)));
    
    
    /*----------------------------------------------------------Table-2-------------------------------------------------------*/
    
    
    printf("Enter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([M]ild,[R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &prefCream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("Maker ([R]esidential,[C]ommercial): ");
    scanf(" %c", &maker);
    putchar('\n');
    printf("The below table shows how your preferences align to the available products:\n\n");
    
    printf("--------------------+--------------------+-------------+-------+--------------\n"
           "  |     Coffee      |       Coffee       |  Packaged   | With  |   Serving\n"
           "ID|      Type       |     Grind Size     | Bag Weight  | Cream | Temperature\n"
           "--+-----------------+--------------------+-------------+-------+--------------\n");
    printf(" 1|       %d         |         %d          |      %d      |   %d   |      %d\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC1 == 'l' || productTypeC1 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC1 == 'b' || productTypeC1 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC1 == 'c' || productGrindsizeC1 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC1 == 'f' || productGrindsizeC1 == 'F')),
           
           (dailyServings > 0 && dailyServings <= 4 && (productWeightC1 > 0 && productWeightC1 <= 250)),                              //packaged bag weight
           
           ((prefCream == 'y' || prefCream == 'Y') && (productCreamC1 == 'y' || productCreamC1 =='Y')) ||                            //with cream
           ((prefCream == 'n' || prefCream == 'N') && (productCreamC1 == 'n' || productCreamC1 =='N')),
           
           ((maker == 'r'     ||   maker == 'R')   &&  (productTempC1 > 60.0 && productTempC1 <= 69.9)) ||                           //serving temperature
           ((maker == 'c'     ||   maker == 'C')   &&  (productTempC1 >=70.0 && productTempC1 < 1000.0)));
    
    
    printf(" 2|       %d         |         %d          |      %d      |   %d   |      %d\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC2 == 'l' || productTypeC2 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC2 == 'b' || productTypeC2 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC2 == 'c' || productGrindsizeC2 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC2 == 'f' || productGrindsizeC2 == 'F')),
        
           (dailyServings >= 5 && dailyServings <= 9 && productWeightC2 == 500),                                                     //packaged bag weight
           
           ((prefCream == 'y'  || prefCream == 'Y') && (productCreamC2 == 'y' || productCreamC2 =='Y')) ||                            //with cream
           ((prefCream == 'n'  || prefCream == 'N') && (productCreamC2 == 'n' || productCreamC2 =='N')),
           
           ((maker == 'r'      ||   maker == 'R')   &&  (productTempC2 > 60.0 && productTempC2 <= 69.9)) ||                           //serving temperature
           ((maker == 'c'      ||   maker == 'C')   &&   (productTempC2 >=70.0 && productTempC2 < 1000.0)));
    
    
    printf(" 3|       %d         |         %d          |      %d      |   %d   |      %d\n",
           ((coffeeStrength == 'm' || coffeeStrength == 'M')  &&  (productTypeC3 == 'l' || productTypeC3 == 'L' )) ||                //coffee type
           ((coffeeStrength == 'r' || coffeeStrength == 'R')  &&  (productTypeC3 == 'b' || productTypeC3 == 'B' )),
           
           ((maker == 'r'          || maker == 'R')           &&  (productGrindsizeC3 == 'c' || productGrindsizeC3 == 'C' )) ||      //coffee grind size
           ((maker == 'c'          || maker == 'C')           &&  (productGrindsizeC3 == 'f' || productGrindsizeC3 == 'F')),
        
           (dailyServings >= 10 && dailyServings <= 100 && productWeightC3 == 1000),                                                 //packaged bag weight
           
           ((prefCream == 'y'  || prefCream == 'Y') && (productCreamC3 == 'y' || productCreamC3 =='Y')) ||                            //with cream
           ((prefCream == 'n'  || prefCream == 'N') && (productCreamC3 == 'n' || productCreamC3 =='N')),
            
           ((maker == 'r'      ||   maker == 'R')   &&  (productTempC3 > 60.0 && productTempC3 <= 69.9)) ||                           //serving temperature
           ((maker == 'c'      ||   maker == 'C')   &&  (productTempC3 >=70.0 && productTempC3 < 1000.0)));
    
    printf("\nHope you found a product that suits your likes!\n");
    
    return 0;
}



