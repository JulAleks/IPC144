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

//macros
#define MAX_PRODUCTS 3
#define GRAMS 64


// structures
struct CatFoodInfo {
    int skuNum;
    double price;
    double weight;
    int kcal;
};




// function prototypes
//1. Get user input of int typeand validate for a positive non - zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *postInt); 

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *postDouble); 

// 3. Opening Message (include the number of products that need entering)
void openingMessage(void);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int sequenceNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int skuNum, double* price, double* weight, int kcal);

// 7. Logic entry point
void start(void);
