/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name : Julia Alekseev
Student ID#: 051292134
Email: jalekseev@myseneca.ca
Section : G

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// System Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* postInt) {
    int input;
    do {
        scanf(" %d", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else if (postInt != NULL) {
            *postInt = input;
        }
    } while (input <= 0);

    return input;
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* postDouble) {
    double input;

    do {
        scanf(" %lf", &input);
        if (input <= 0) {
            printf("ERROR: Enter a positive value: ");
        }
        else if (postDouble != NULL) {
            *postDouble = input;
        }
    } while (input <= 0);

    return input;

}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void) {
    printf("Cat Food Cost Analysis\n");
    printf("======================\n\n");
    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAX_PRODUCTS);
    printf("NOTE: A 'serving' is %dg\n\n", GRAMS);

}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int productNum) {
    struct CatFoodInfo catFood;

    printf("Cat Food Product #%d\n", productNum);
    printf("--------------------\n");

    printf("SKU           : ");
    catFood.skuNum = getIntPositive(&catFood.skuNum);

    printf("PRICE         : $");
    catFood.price = getDoublePositive(&catFood.price);

    printf("WEIGHT (LBS)  : ");
    catFood.weight = getDoublePositive(&catFood.weight);

    printf("CALORIES/SERV.: ");
    catFood.kcal = getIntPositive(&catFood.kcal);

    printf("\n");

    return catFood;
}



// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");

}

//6. Display a formatted record of cat food data
void displayCatFoodData(int skuNum, double *price, double* weight, int kcal) {
    printf("%07d %10.2lf %10.1lf %8d\n", skuNum, *price, *weight, kcal);
}

// 7. Logic entry point
void start(void) {

    openingMessage();

    struct CatFoodInfo catFood[MAX_PRODUCTS] = { { 0, 0.0, 0.0, 0 } };

    int i;

    for (i = 0; i < MAX_PRODUCTS; i++) {
        catFood[i] = getCatFoodInfo(i + 1);
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(catFood[i].skuNum, &catFood[i].price, &catFood[i].weight, catFood[i].kcal);
    }
}






