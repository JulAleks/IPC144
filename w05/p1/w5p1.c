/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012 
#define MAX_YEAR 2022

int main(void)
{
    printf("General Well-being Log\n");
    printf("======================\n");

    int flag1 = 0, month, year;
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

       if ((month > 12 || month < 1) && (year > MAX_YEAR || year < MIN_YEAR)) {
           printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
           printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
       else if (year > MAX_YEAR || year < MIN_YEAR) {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        else if (month > 12 || month < 1) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        else {
            flag1 = 1; 
        }

    } while (flag1 == 0); {

        printf("\n*** Log date set! ***\n");

        if (month == 1) {
        printf("\nLog starting date: %d-JAN-01\n", year);
        }
        else if (month == 2) {
            printf("\nLog starting date: %d-FEB-01\n", year);
        }
        else if (month == 3) {
            printf("\nLog starting date: %d-MAR-01\n", year);
        }
        else if (month == 4) {
            printf("\nLog starting date: %d-APR-01\n", year);
        }
        else if (month == 5) {
            printf("\nLog starting date: %d-MAY-01\n", year);
        }
        else if (month == 6) {
            printf("\nLog starting date: %d-JUN-01\n", year);
        }
        else if (month == 7) {
            printf("\nLog starting date: %d-JUL-01\n", year);
        }
        else if (month == 8) {
            printf("\nLog starting date: %d-AUG-01\n", year);
        }
        else if (month == 9) {
            printf("\nLog starting date: %d-SEP-01\n", year);
        }
        else if (month == 10) {
            printf("\nLog starting date: %d-OCT-01\n", year);
        }
        else if (month == 11) {
            printf("\nLog starting date: %d-NOV-01\n", year);
        }
        else if (month == 12) {
            printf("\nLog starting date: %d-DEC-01\n", year);
        }
     
    }

   

    return 0;
}