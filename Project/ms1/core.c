
/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

//get Integer
int inputInt(void) {
    int input = 0;
    char chInput;
    while (input == 0) {
        scanf("%d%c", &input, &chInput);
        if (chInput == '\n') {
            return input;
        }
        else {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } 
    return 0;
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
       
    } return input;
}

//get in range
int inputIntRange(int lowRange, int upRange) {
    int input = 0;
    char chInput;
    do {
        scanf("%d%c", &input, &chInput);
        if (chInput == '\n') {
            if (input < lowRange || input > upRange) {
                printf("ERROR! Value must be between %d and %d inclusive: ", lowRange, upRange);
             
            }
        }
        else {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (chInput != '\n' || input < lowRange || input > upRange);
    return input;
}


//input char option
char inputCharOption(char stringArray[]) {
    char input;
    int i;
    int found ;
    do {
        scanf("%c", &input);
        clearInputBuffer();
        found = 0; 

        for (i = 0; stringArray[i] != '\0'; i++) {
            if (stringArray[i] == input && input != '\n') {
                found = 1;
            }
        }

        if (found == 0) {
            printf("ERROR: Character must be one of [%s]: ", stringArray);
           
        }
    } while (found == 0);
    return input;
}

//input a string
void inputCString(char* string, int min, int max) {
char input[10] = {'\0'};
    int lenString = 0;
    
    do{
        
        scanf("%9[^\n]", input);
        clearInputBuffer();
        lenString = 0;
       
        while (input[lenString] != '\0') {
            lenString++;
        }

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
            int i;
            for (i = 0; input[i] != '\0';  i++) {
                string[i] = input[i];  
            }
        }
    } while (!(lenString >= min && lenString <= max));
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