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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3
#define GRAMS 64
#define LBS 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int skuNum;
    double price;
    double weight;
    int kcal;
};

struct ReportData {

    int skuNum;
    double price;
    int kcal;
    double weightLbs;
    double weightKg;
    int weightGr;
    double totServ;
    double totCostServ;
    double totCostKcalServ;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* postInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* postDouble);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNum, double* price, double* weight, int kcal);

// ----------------------------------------------------------------------------
// PART-2

//1. Convert pounds (lbs) to kilograms (kg)
double convertLbsKg(const double* lbsToConvert, double* kgResult);

//2. Convert pounds (lbs) to grams (g)
int convertLbsG(const double* lbsToConvert, int* gramResult);

//3. Convert pounds (lbs) to kilograms (kg) and grams (g)
void convertLbs(const double* lbsToConvert, double* kgResult, int* grResult);

//4. Calculate servings based on serving size in grams and total grams for a product
double calculateServings(const int servingSize, const int totalGrProduct, double* servings);

//5. Calculate cost per serving based on product price and total number of servings
double calculateCostPerServing(const double* price, const double* totalServings, double* costPerServing);

//6. Calculate cost per calorie based on product price and total number of calories
double calculateCostPerServingPerCal(const double* pricePerServ, const int* totalCalories, double* costPerCal);

//7. Derive a reporting detail record based on the cat food product data
struct ReportData generateReportData(struct CatFoodInfo catFood);

//8. Display the formatted table header for the analysis results
void displayReportHeader(void);

//9. Display a single row of report data
void displayReportData(struct ReportData data, const int cheap);

//10. Display the final analysis summary
void displayFinalAnalysis(struct CatFoodInfo catFood);

// ----------------------------------------------------------------------------

//11. Logic entry point 
void start(void);
