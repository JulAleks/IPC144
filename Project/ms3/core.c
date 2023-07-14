/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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
#include <string.h>
#include <ctype.h>

#include "core.h"
//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//display phone
void displayFormattedPhone(const char* phone) {
    if (phone == NULL) {
        printf("(___)___-____");
    }
    else {
        int size = 0;
        int digit = 0;
        int i;
        for (i = 0; phone[i] != '\0'; i++) {
            if (phone[i] >= '0' && phone[i] <= '9') {
                size++;
                digit++;
            }
        }
        if (size != 10 || digit != 10) {
            printf("(___)___-____");
        }
        else {
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
                phone[0], phone[1], phone[2],
                phone[3], phone[4], phone[5],
                phone[6], phone[7], phone[8], phone[9]);
        }
    }
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//
// Copy your work done from Milestone #2 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
//

//get Integer
int inputInt(void) {
    int input = 0;
    char chInput;
    do {
        scanf("%d%c", &input, &chInput);

        if (chInput != '\n') {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (input < 0);
    return input;
}


//get IntPositive
int inputIntPositive(void) {
    int input = 0;
    while (input <= 0) {
        input = inputInt();
        if (input < 0) {
            printf("ERROR! Value must be > 0: ");
            clearInputBuffer();
        }
    }
    return input;
}

//get in range
int inputIntRange(int lowRange, int upRange) {
    int result;
    do {
        result = inputInt();
        if (result < lowRange || result > upRange) {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowRange, upRange);
            result = 0;
        }
    } while (result < lowRange || result > upRange);
    return result;
}


//input char option
char inputCharOption(char stringArray[]) {
    char input[10];
    int found = 0;
    do {
        scanf("%9s", input);
        if (strlen(input) == 1 && (strchr(stringArray, input[0]) || strchr(stringArray, input[1]))) {
            found = 1;
        }
        if (!found) {
            printf("ERROR: Character must be one of [%s]: ", stringArray);
        }
    } while (!found);

    return input[0];
}


//input a string
void inputCString(char* string, int min, int max) {
    char input[30] = { '\0' };
    int lenString = 0;
    int validInput = 0;

    while (!validInput) {
        scanf(" %[^\n]", input); 
        clearInputBuffer();
        lenString = strlen(input);

        if (isdigit(*input)) {
            if (lenString != 10) {
                printf("Invalid 10-digit number! Number: ");
             
            }
            else {
                strcpy(string, input);
                validInput = 1; 
            }
        }
        else if (!isdigit(*input)) {
            if (lenString < min) {
                printf("ERROR: String length must be at least %d chars: ", min);
                
            }
            else if (lenString > max) {
                printf("ERROR: String length must be no more than %d chars: ", max);
                
            }
            else {
                strcpy(string, input);
                validInput = 1; 
             
            }
        }
    }
}
