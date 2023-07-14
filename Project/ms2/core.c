/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////


// Clear the standard input buffer 
void clearInputBuffer(void)
{ // Discard all remaining char's from the standard input buffer: 
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

//get Integer
int inputInt(void) {
    int input = 0;
    char chInput;
    while (input == 0) {
        scanf("%d%c", &input, &chInput);
        if (chInput != '\n') {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }
    return input;
}


//get IntPositive
int inputIntPositive(void) {
    int input = 0;
    while (input <= 0) {
        scanf("%d", &input);
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
        scanf("%d", &result);
        if (result < lowRange || result > upRange) {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
            clearInputBuffer();
        }
    } while (result < lowRange || result > upRange);
    return result;
}


//input char option
char inputCharOption(char stringArray[]) {
    char input;
    int found = 0;
    char* inputP;
    do {
        scanf(" %c", &input);
        clearInputBuffer();

        inputP = strchr(stringArray, input);
        if (inputP == NULL) {
            printf("ERROR: Character must be one of [%s]: ", stringArray);
        }
        else {
            found++;
        }
    } while (found == 0);

    return input;

}

//input a string
void inputCString(char* string, int min, int max) {
    char input[10] = { '\0' };
    int lenString = 0;

    do {

        scanf("%9[^\n]", input);
        clearInputBuffer();
        lenString = strlen(input);


        if (!(lenString >= min && lenString <= max)) {
            if (max == min) {
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            else if (lenString > max) {
                printf("ERROR: String length must be no more than %d chars: ", max);
            }
            else {
                printf("ERROR: String length must be between %d and %d chars: ", min, max);
            }
        }
        else {
            strcpy(string, input);
        }
    } while (!(lenString >= min && lenString <= max));
}


