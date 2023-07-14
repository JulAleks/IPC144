/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{

    char type;
    int num, i, flag = 0;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n");

    do {
  
    printf("\nD = do/while | W = while | F = for | Q = quit\n");
    printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf("%c%d%*c", &type, &num);

    if (type == 'Q') {
        if (num == 0) {
            flag = 1;
        }else
        printf("ERROR: To quit, the number of iterations should be 0!\n");
       
    }
    else if (type != 'D' && type != 'W' && type != 'F') {
        printf("ERROR: Invalid entered value(s)!\n");
    }
    else if (num < 3 || num > 20) {
        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
    } 
    else if (type == 'D') {
       i = 0;
       printf("DO-WHILE: ");
        do  {
            printf("D");
            i++;
        } while (i < num);
        printf("\n");
    }
    else if (type == 'W') {
        printf("WHILE   : ");
        i = 0;
        while (i < num) {
        printf("W");
        i++; 
        }  
        printf("\n");
    }
    else if (type == 'F') {
        printf("FOR     : ");
        for (i = 0; i < num; i++) {
            printf("F");
        } printf("\n");
    }
    } while (flag == 0);{
    printf("\n+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    }
 
    return 0;
}