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

// Clear the standard input buffer 
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue 
void suspend(void);

//get Integer
int inputInt(void);

//get IntPositive
int inputIntPositive(void);

//get in range
int inputIntRange(int lowRange, int upRange);

//input char option
char inputCharOption(char stringArray[]);

//input a string
void inputCString(char* string, int min, int max);

//display phone
char displayFormattedPhone(const char* phoneString);
