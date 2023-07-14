/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
    struct CatFoodInfo catFood= { 0 };

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

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNum, double* price, double* weight, int kcal) {
    printf("%07d %10.2lf %10.1lf %8d\n", skuNum, *price, *weight, kcal);
}



// ----------------------------------------------------------------------------
// PART-2

// 1. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbsToConvert, double* kgResult) {
    double result = (*lbsToConvert) / LBS;
    if (kgResult != NULL) {
        *kgResult = result;
    }
    return result;
}


// 2. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbsToConvert, int* gramResult) {

    int result = ((*lbsToConvert/LBS) * 1000);

    if (gramResult != NULL) {
        *gramResult = result;
    }


    return result;
}

// 3. convert lbs: kg and g
void convertLbs(const double* lbsToConvert, double* kgResult, int* grResult) {

    *kgResult = convertLbsKg(lbsToConvert, NULL);
    *grResult = convertLbsG(lbsToConvert, NULL);

}

// 4. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrProduct, double* servings) {
    double result = ((double)totalGrProduct / servingSize);
    if (servings != NULL) {
        *servings = result;
    }
    return result;
}


// 5. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServings, double* costPerServing) {
    double result = (*price / *totalServings);

    if (costPerServing != NULL) {
        *costPerServing = result;
    }
    return result;
}


// 6. calculate: cost per calorie
double calculateCostPerServingPerCal(const double* pricePerServ, const int* totalCalories, double* costPerCal) {
    double result = (*pricePerServ / *totalCalories);

    if (costPerCal != NULL) {
        *costPerCal = result;
    }
    return result;
}

// 7. Derive a reporting detail record based on the cat food product data
struct ReportData generateReportData(struct CatFoodInfo catFood) {
    struct ReportData data;

    data.skuNum = catFood.skuNum;
    data.price = catFood.price;
    data.kcal = catFood.kcal;
    data.weightLbs = catFood.weight;

    double resultKg;
    convertLbsKg(&catFood.weight,&resultKg);
    data.weightKg = resultKg;

    int gramsOfProduct;
    convertLbsG(&catFood.weight, &gramsOfProduct);
    data.weightGr = gramsOfProduct;

    double totServ; 
    calculateServings(GRAMS, gramsOfProduct, &totServ);
    data.totServ = totServ;

    double costPerServ;
    calculateCostPerServing(&catFood.price, &totServ, &costPerServ);
    data.totCostServ = costPerServ;

    double costPerCal;
    calculateCostPerServingPerCal(&costPerServ, &catFood.kcal, &costPerCal);
    data.totCostKcalServ = costPerCal;

    return data;
}


// 8. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 9. Display the formatted data row in the analysis table
void displayReportData(struct ReportData data, const int cheap) {

    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.skuNum, data.price, data.weightLbs, data.weightKg, data.weightGr, data.kcal,data.totServ, data.totCostServ, data.totCostKcalServ);
    
}


//10. Display the findings (cheapest)
void displayFinalAnalysis(struct CatFoodInfo catFood) {
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:00%d Price: $%.2lf\n\n", catFood.skuNum, catFood.price);
    printf("Happy shopping!\n");
}


// ----------------------------------------------------------------------------

//11. Logic entry point
void start(void) {

    openingMessage();

    struct CatFoodInfo catFood[MAX_PRODUCTS]; 
    struct ReportData data[MAX_PRODUCTS]; 

    int i;
   

    for (i = 0; i < MAX_PRODUCTS; i++) {
        catFood[i] = getCatFoodInfo(i + 1);
        data[i] = generateReportData(catFood[i]);
    }

    displayCatFoodHeader();

    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayCatFoodData(catFood[i].skuNum, &catFood[i].price, &catFood[i].weight, catFood[i].kcal);

    }

    printf("\n");

    displayReportHeader();

    double cheapest = data[0].totCostKcalServ;
    int cheapestProduct = 0;
    for (i = 1; i < MAX_PRODUCTS; i++) {
        if (data[i].totCostKcalServ < cheapest) {
            cheapest = data[i].totCostKcalServ;
            cheapestProduct = i;
        }
    }

    for (i = 0; i < MAX_PRODUCTS; i++) {
        displayReportData(data[i], cheapestProduct);
        if (cheapestProduct == i) {
            printf(" ***\n");
        }
        else {
            printf("\n");
        }
    }
            printf("\n");
    for (i = 0; i < MAX_PRODUCTS; i++) {

        if (cheapestProduct == i) {
            displayFinalAnalysis(catFood[i]);

        }

    }

    
}

