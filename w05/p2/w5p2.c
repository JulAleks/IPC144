/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
int num = 0, day = 1;
double morRate, eveRate, eveTotal = 0, morTotal = 0, eveAvarage = 0, morAvarage = 0;
int month, year, day;
int main(void)
{
    printf("General Well-being Log\n");
    printf("======================\n");

    
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
     

    } while (!((year <= MAX_YEAR && year >= MIN_YEAR) && (month >= 1 && month <= 12))); {

        printf("\n*** Log date set! ***\n");
   
        if (month == 1) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-JAN-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;  
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }  else if (month == 2) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-FEB-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }else if (month == 3) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-MAR-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }else if (month == 4) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-APR-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }else if (month == 5) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-MAY-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }else if (month == 6) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-JUN-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }else if (month == 7) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-JUL-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        } else if (month == 8) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-AUG-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        } else if (month == 9) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-SEP-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        } else if (month == 10) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-OCT-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        } else if (month == 11) {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-NOV-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        } else {
            for (day = 1; day <= LOG_DAYS; day++) {
                printf("\n%d-DEC-%02d\n", year, day);

                do {
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morRate);
                    if (morRate > 5 || morRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        morTotal += morRate;
                    }
                } while (!(morRate >= 0 && morRate <= 5));

                do {
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveRate);
                    if (eveRate > 5 || eveRate < 0) {
                        printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    }
                    else {
                        eveTotal += eveRate;
                    }
                } while (!(eveRate >= 0 && eveRate <= 5));
            }
        }
        printf("\nSummary\n");
        printf("=======\n");
        printf("Morning total rating: %.3lf\n", morTotal);
        printf("Evening total rating: %6.3lf\n", eveTotal);
        printf("----------------------------\n");
        printf("Overall total rating: %.3lf\n", morTotal+ eveTotal);
        printf("\nAverage morning rating: %4.1lf", morTotal / LOG_DAYS);
        printf("\nAverage evening rating: %4.1lf", eveTotal / LOG_DAYS);
        printf("\n----------------------------\n");
        printf("Average overall rating: %4.1lf\n\n", ((eveTotal / LOG_DAYS)+ (morTotal / LOG_DAYS)) / 2.0);
     
     }
    return 0;
}