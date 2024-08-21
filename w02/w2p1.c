/*
*****************************************************************************
                   <assessment name example: Workshop - #2 (Part-1)>
     Full Name  : Navnoor Singh
     Student ID#: 160821211
     Email      : nsingh391@nsingh391@myseneca.ca
     Section    : ZBB
     Authenticity Declaration:
     I declare this submission is the result of my own work and has not been
     shared with any other student or 3rd party content provider. This submitted
     piece of work is entirely of my own creation.
*****************************************************************************
*/


#include<stdio.h>

int main (void)
{
  const double TAX_RATE = 0.05;
  const char patSize = 'S';

  int numberofShirts, tax, subTotal, total;
  double shirtPriceS, shirtPriceM, shirtPriceL;

  printf ("Set Shirt Prices\n" 
          "================\n");
  printf ("Enter the price for a SMALL shirt: $");
  scanf ("%lf", &shirtPriceS);
  printf ("Enter the price for a MEDIUM shirt: $");
  scanf ("%lf", &shirtPriceM);
  printf ("Enter the price for a LARGE shirt: $");
  scanf ("%lf", &shirtPriceL);
  putchar ('\n');

  printf ("Shirt Store Price List\n"
          "======================\n");
  printf ("SMALL  : $%.2lf\n", shirtPriceS);
  printf ("MEDIUM : $%.2lf\n", shirtPriceM);
  printf ("LARGE  : $%.2lf\n", shirtPriceL);
  putchar ('\n');
  

  printf ("Patty's shirt size is '%c'\n"
          "Number of shirts Patty is buying: ", patSize);
  scanf ("%d", &numberofShirts);
  putchar ('\n'); 
  printf ("Patty's shopping cart...\n"
          "Contains : %d shirts\n", numberofShirts);
  
  //calculations
  subTotal = (int)(((shirtPriceS * numberofShirts) + 0.005) * 100);
  tax = (int)((subTotal * TAX_RATE) + 0.5);
  total = subTotal + tax;
  
  printf ("Sub-total: $%8.4lf\n", subTotal / 100.0000);
  printf ("Taxes    : $%8.4lf\n", tax / 100.0000);
  printf ("Total    : $%8.4lf\n", total / 100.0000);

  return 0;
}
        
