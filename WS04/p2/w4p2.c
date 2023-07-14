/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name : Julia Alekseev
Student ID#: 051292134
Email: jalekseev@myseneca.ca
Section : G

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
    int mainFlag = 0;
    do {
        printf("Grocery Shopping\n");
        printf("================\n");

        int apl, org, pear, tom, cabb;

        do {
            printf("How many APPLES do you need? : ");
            scanf("%d", &apl);
            if (apl < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (apl < 0);
        printf("\n");

        do {
            printf("How many ORANGES do you need? : ");
            scanf("%d", &org);
            if (org < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (org < 0);
        printf("\n");

        do {
            printf("How many PEARS do you need? : ");
            scanf("%d", &pear);
            if (pear < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (pear < 0);
        printf("\n");

        do {
            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tom);
            if (tom < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (tom < 0);
        printf("\n");

        do {
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabb);
            if (cabb < 0) {
                printf("ERROR: Value must be 0 or more.\n");
            }
        } while (cabb < 0);

        printf("\n--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");
        
        if (apl > 0) {
            {
                int cusApl, basket = 0, flagApl = 0;
                do {
                    while (basket < apl) {
                        printf("Pick some APPLES... how many did you pick? : ");
                        scanf("%d", &cusApl);

                        if (cusApl > apl - basket) {
                            printf("You picked too many... only %d more APPLE(S) are needed.\n", apl - basket);
                        }
                        else if (cusApl <= 0) {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                        else if (cusApl >= 0 && cusApl <= apl)
                        {
                            basket += cusApl;
                            if (basket < apl) {
                                printf("Looks like we still need some APPLES...\n");
                            }
                            else {
                                flagApl += 1;
                            }
                        }
                    }
                } while (flagApl == 0); {
                    printf("Great, that's the apples done!\n\n");
                }
            }
        }



        if (org > 0) {
            {
                int cusOrg, basket = 0, flagOrg = 0;
                do {
                    while (basket < org) {
                        printf("Pick some ORANGES... how many did you pick? : ");
                        scanf("%d", &cusOrg);

                        if (cusOrg > org - basket) {
                            printf("You picked too many... only %d more ORANGE(S) are needed.\n", org - basket);
                        }
                        else if (cusOrg <= 0) {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                        else if (cusOrg >= 0 && cusOrg <= org)
                        {
                            basket += cusOrg;
                            if (basket < org) {
                                printf("Looks like we still need some ORANGES...\n");
                            }
                            else {
                                flagOrg += 1;
                            }
                        }
                    }
                } while (flagOrg == 0); {
                    printf("Great, that's the oranges done!\n\n");
                }
            }
        }


        if (pear > 0) {
            {
                int cusPear, basket = 0, flagPear = 0;
                do {
                    while (basket < pear) {
                        printf("Pick some PEARS... how many did you pick? : ");
                        scanf("%d", &cusPear);

                        if (cusPear > pear - basket) {
                            printf("You picked too many... only %d more PEAR(S) are needed.\n", pear - basket);
                        }
                        else if (cusPear <= 0) {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                        else if (cusPear >= 0 && cusPear <= pear)
                        {
                            basket += cusPear;
                            if (basket < pear) {
                                printf("Looks like we still need some PEARS...\n");
                            }
                            else {
                                flagPear += 1;
                            }
                        }
                    }
                } while (flagPear == 0); {
                    printf("Great, that's the pears done!\n\n");
                }
            }
        }


        if (tom > 0) {
            {
                int cusTom, basket = 0, flagTom = 0;
                do {
                    while (basket < tom) {
                        printf("Pick some TOMATOES... how many did you pick? : ");
                        scanf("%d", &cusTom);

                        if (cusTom > tom - basket) {
                            printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tom - basket);
                        }
                        else if (cusTom <= 0) {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                        else if (cusTom >= 0 && cusTom <= tom)
                        {
                            basket += cusTom;
                            if (basket < tom) {
                                printf("Looks like we still need some TOMATOES...\n");
                            }
                            else {
                                flagTom += 1;
                            }
                        }
                    }
                } while (flagTom == 0); {
                    printf("Great, that's the tomatoes done!\n\n");
                }
            }
        }

        if (cabb > 0) {
            {
                int cusCab, basket = 0, flagCub = 0;
                do {
                    while (basket < cabb) {
                        printf("Pick some CABBAGES... how many did you pick? : ");
                        scanf("%d", &cusCab);

                        if (cusCab > cabb - basket) {
                            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabb - basket);
                        }
                        else if (cusCab <= 0) {
                            printf("ERROR: You must pick at least 1!\n");
                        }
                        else if (cusCab >= 0 && cusCab <= cabb)
                        {
                            basket += cusCab;
                            if (basket < cabb) {
                                printf("Looks like we still need some CABBAGES...\n");
                            }
                            else {
                                flagCub += 1;
                            }
                        }
                    }
                } while (flagCub == 0); {
                    printf("Great, that's the cabbages done!\n\n");
                }
            }
        }
        int esc;
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &esc);
        if (esc == 0) {
            mainFlag += 1;
        }
        else {
            mainFlag = 0;
            printf("\n");
        }
    } while (mainFlag == 0); {
        printf("\nYour tasks are done for today - enjoy your free time!\n");
    }

        return 0;
}