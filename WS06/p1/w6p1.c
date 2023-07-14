/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define MIN_INCOME 500.0
#define MAX_INCOME 400000.00
#define MAX_ITEM 10
#define MIN_ITEM 1

int main(void)
{
    {
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    }
     
    double netIncome, totalCost=0.0, cost[MAX_ITEM];
    int i, itemNum, import[MAX_ITEM];
    char finance[MAX_ITEM];

    do {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);

        if (netIncome < MIN_INCOME) printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        if (netIncome > MAX_INCOME) printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");

    } while (!(netIncome >= MIN_INCOME && netIncome <= MAX_INCOME));

    do {
        printf("\nHow many wish list items do you want to forecast?: ");
        scanf("%d", &itemNum);
   
        if (itemNum < MIN_ITEM || itemNum > MAX_ITEM) printf("ERROR: List is restricted to between 1 and 10 items.\n");


    } while (!(itemNum >= MIN_ITEM && itemNum <= MAX_ITEM));
    
    for (i = 0; i < itemNum; i++) {
       
        printf("\nItem-%d Details:\n", i + 1);
        do {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < 100.00) printf("      ERROR: Cost must be at least $100.00\n");
        } while (!(cost[i] >= 100.00));

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &import[i]);
            if (import[i] < 1 || import[i] > 3) printf("      ERROR: Value must be between 1 and 3\n");
        } while (import[i] > 3 || import[i] < 1);

        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            if (finance[i] != 'y' && finance[i] != 'n') printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
        } while (finance[i] != 'y' && finance[i] != 'n');
    }
    {
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < itemNum; i++){
    printf("%3d %6d %8c %14.2lf\n", i+1, import[i], finance[i], cost[i]);
    }
    printf("---- -------- -------- -----------\n");
    
    for (i = 0; i < itemNum; i++) {
    totalCost+= cost[i]; 
    }
    printf("                      $%11.2lf\n\n", totalCost);
    printf("Best of luck in all your future endeavours!\n");
    }

  return 0;
}