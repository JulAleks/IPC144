/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Julia Alekseev
Student ID#: 051292134
Email  : jalekseev@myseneca.ca  
Section    : G
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    double SML, MED, LRG, SUB;
    int QTY;
    


    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &SML);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &MED);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &LRG);
   

    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", SML);
    printf("MEDIUM : $%.2lf\n", MED);
    printf("LARGE  : $%.2lf\n\n", LRG);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &QTY);


    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", QTY);

    SUB = SML * QTY;
    printf("Sub-total: $%.4lf\n", SUB);

    double TX = SUB * TAX;
    int subTx = (TX + 0.005) * 100;
    printf("Taxes    : $%8.4lf\n", subTx/100.0);

    double total = (subTx / 100.0) +SUB;
    printf("Total    : $%.4lf\n", total);

    return 0;
}