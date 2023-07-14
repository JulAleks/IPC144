/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name : Julia Alekseev
Student ID#: 051292134
Email: jalekseev@myseneca.ca
Section : G

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
   const double GRAMS_IN_LBS = 453.5924;
   char coffeeType1, coffeeType2, coffeeType3, suggestCream1, suggestCream2, suggestCream3; 
   int coffeeWeight1, coffeeWeight2, coffeeWeight3;

   {printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n"); }

    {printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggestCream1); }
    
    {printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggestCream2); }
    
    {printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &suggestCream3); }
    
    {printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType1 == 'l' || coffeeType1 == 'L', coffeeType1 == 'm' || coffeeType1 == 'M', coffeeType1 == 'r' || coffeeType1 == 'R', coffeeWeight1, coffeeWeight1 / GRAMS_IN_LBS, suggestCream1 == 'y' || suggestCream1 == 'Y');
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType2 == 'l' || coffeeType2 == 'L', coffeeType2 == 'm' || coffeeType2 == 'M', coffeeType2 == 'r' || coffeeType2 == 'R', coffeeWeight2, coffeeWeight2 / GRAMS_IN_LBS, suggestCream2 == 'y' || suggestCream2 == 'Y');
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", coffeeType3 == 'l' || coffeeType3 == 'L', coffeeType3 == 'm' || coffeeType3 == 'M', coffeeType3 == 'r' || coffeeType3 == 'R', coffeeWeight3, coffeeWeight3 / GRAMS_IN_LBS, suggestCream3 == 'y' || suggestCream3 == 'Y'); }
    
    {char requestedCoffee, requestedCream;
    int dailyServing;
     printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
     printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
     scanf(" %c", &requestedCoffee);
     printf("Do you like your coffee with cream ([Y]es,[N]o): ");
     scanf(" %c", &requestedCream);
     printf("Typical number of daily servings: ");
     scanf("%d", &dailyServing);

     printf("\nThe below table shows how your preferences align to the available products:\n\n");
     printf("--------------------+-------------+-------+\n");
     printf("  |     Coffee      |  Packaged   | With  |\n");
     printf("ID|      Type       | Bag Weight  | Cream |\n");
     printf("--+-----------------+-------------+-------+\n");
     printf(" 1|       %d         |      %d      |   %d   |\n", requestedCoffee == 'l' || requestedCoffee == 'L', dailyServing > 0 && dailyServing < 5, requestedCream == 'y' || requestedCream == 'Y');
     printf(" 2|       %d         |      %d      |   %d   |\n", requestedCoffee == 'r' || requestedCoffee == 'R', dailyServing > 4 && dailyServing < 10, requestedCream == 'n' || requestedCream == 'N');
     printf(" 3|       %d         |      %d      |   %d   |\n", requestedCoffee == 'm' || requestedCoffee == 'M', dailyServing > 9, requestedCream == 'n' || requestedCream == 'N'); }
     
    {char requestedCoffee2, requestedCream2;
    int dailyServing2;
    printf("\nEnter how you like your coffee and the coffee maker equipment you use...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &requestedCoffee2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &requestedCream2);
    printf("Typical number of daily servings: ");
    scanf("%d", &dailyServing2);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", requestedCoffee2 == 'l' || requestedCoffee2 == 'L', dailyServing2 > 0 && dailyServing2 < 5, requestedCream2 == 'y' || requestedCream2 == 'Y');
    printf(" 2|       %d         |      %d      |   %d   |\n", requestedCoffee2 == 'r' || requestedCoffee2 == 'R', dailyServing2 > 4 && dailyServing2 < 10, requestedCream2 == 'n' || requestedCream2 == 'N');
    printf(" 3|       %d         |      %d      |   %d   |\n", requestedCoffee2 == 'm' || requestedCoffee2 == 'M', dailyServing2 > 9, requestedCream2 == 'n' || requestedCream2 == 'N');
    printf("\nHope you found a product that suits your likes!\n");}
   
    
    return 0;
}


