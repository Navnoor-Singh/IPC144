/*
*****************************************************************************
                          Workshop - #4 (P2)
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
    
    int numberofApples, numberofOranges, numberofPears, numberofTomatoes, numberofCabbages;
    int pickedItems, repeatShopping;
    
    
    do{     // Main repeater.....
        
    printf("Grocery Shopping\n"
           "================\n");
        
    // GETTING USER INPUT.....
        
    //APPLES...
        
        do{
            printf("How many APPLES do you need? : ");
            scanf("%d", &numberofApples);
            if(numberofApples < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while ((numberofApples < 0));
        
    putchar('\n');
    //ORANGES...
        
        do{
            printf("How many ORANGES do you need? : ");
            scanf("%d", &numberofOranges);
            if(numberofOranges < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
          } while (numberofOranges < 0);
        
    putchar('\n');
    //PEARS...
        
        do{
            printf("How many PEARS do you need? : ");
            scanf("%d", &numberofPears);
            if(numberofPears < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
          } while (numberofPears < 0);
        
    putchar('\n');
    //TOMATOES...
        
        do{
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &numberofTomatoes);
            if(numberofTomatoes < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
          } while (numberofTomatoes < 0);
        
    putchar('\n');
    //CABBAGES...
        
        do{
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &numberofCabbages);
            if(numberofCabbages < 0)
            {
                printf("ERROR: Value must be 0 or more.\n");
            }
            
          } while (numberofCabbages < 0);
        
    putchar('\n');
        
        
    //PICKING.....
        
        printf("--------------------------\n"
               "Time to pick the products!\n"
               "--------------------------\n\n");
        
    //APPLES...
        
        while(numberofApples > 0)
            
        {
            printf("Pick some APPLES... how many did you pick? : ");
            scanf("%d", &pickedItems);
            
            if(pickedItems <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            
            else
            {
                if(pickedItems > numberofApples)
                {
                    printf("You picked too many... only %d more APPLE(S) are needed.\n", numberofApples);
                }
                
                else if((pickedItems > 0) && (pickedItems < numberofApples))
                {
                    printf("Looks like we still need some APPLES...\n");
                    numberofApples -= pickedItems;
                }
                
                else if((pickedItems > 0) && (pickedItems == numberofApples))
                {
                    numberofApples -= pickedItems;
                    printf("Great, that's the apples done!\n\n");
                }
            }
            
        }
        
    //ORANGES...
            
        while(numberofOranges > 0)
            
        {
            printf("Pick some ORANGES... how many did you pick? : ");
            scanf("%d", &pickedItems);
            
            if(pickedItems <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            
            else
            {
                if(pickedItems > numberofOranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", numberofOranges);
                }
                
                else if((pickedItems > 0) && (pickedItems < numberofOranges))
                {
                    printf("Looks like we still need some ORANGES...\n");
                    numberofOranges -= pickedItems;
                }
                
                else if((pickedItems > 0) && (pickedItems == numberofOranges))
                {
                    numberofOranges -= pickedItems;
                    printf("Great, that's the oranges done!\n\n");
                }
            }
            
        }
        
    //PEARS...
   
        
        while(numberofPears > 0)
            
        {
            printf("Pick some PEARS... how many did you pick? : ");
            scanf("%d", &pickedItems);
            
            if(pickedItems <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            
            else
            {
                if(pickedItems > numberofPears)
                {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", numberofPears);
                }
                
                else if((pickedItems > 0) && (pickedItems < numberofPears))
                {
                    printf("Looks like we still need some PEARS...\n");
                    numberofPears -= pickedItems;
                }
                
                else if((pickedItems > 0) && (pickedItems == numberofPears))
                {
                    numberofPears -= pickedItems;
                    printf("Great, that's the pears done!\n\n");
                }
            }
            
        }
        
    //TOMATOES...
    
        
        while(numberofTomatoes > 0)
            
        {
            printf("Pick some TOMATOES... how many did you pick? : ");
            scanf("%d", &pickedItems);
            
            if(pickedItems <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            
            else
            {
                if(pickedItems > numberofTomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", numberofTomatoes);
                }
                
                else if((pickedItems > 0) && (pickedItems < numberofTomatoes))
                {
                    printf("Looks like we still need some TOMATOES...\n");
                    numberofTomatoes -= pickedItems;
                }
                
                else if((pickedItems > 0) && (pickedItems == numberofTomatoes))
                {
                    numberofTomatoes -= pickedItems;
                    printf("Great, that's the tomatoes done!\n\n");
                }
            }
            
        }
        
    //CABBAGES...
   
        
        while(numberofCabbages > 0)
            
        {
            printf("Pick some CABBAGES... how many did you pick? : ");
            scanf("%d", &pickedItems);
            
            if(pickedItems <= 0)
            {
                printf("ERROR: You must pick at least 1!\n");
            }
            
            else
            {
                if(pickedItems > numberofCabbages)
                {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", numberofCabbages);
                }
                
                else if((pickedItems > 0) && (pickedItems < numberofCabbages))
                {
                    printf("Looks like we still need some CABBAGES...\n");
                    numberofCabbages-= pickedItems;
                }
                
                else if((pickedItems > 0) && (pickedItems == numberofCabbages))
                {
                    numberofCabbages -= pickedItems;
                    printf("Great, that's the cabbages done!\n\n");
                }
            }
            
        }
      
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &repeatShopping);
        putchar('\n');
        
    }while(repeatShopping > 0);  //Main repeater
    
    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}
