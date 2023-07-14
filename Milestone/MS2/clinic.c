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
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    displayPatientTableHeader();
    int i;
   
   for (i = 0; i < max; i++) {
       if (patient[i].patientNumber != 0) {
           displayPatientData(&patient[i], fmt);
       }
   }
   
   clearInputBuffer();
   putchar('\n');

}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int selection;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number");

        printf("\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            clearInputBuffer();
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        else if (selection == 2)
        {
            clearInputBuffer();
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }  
        
    } while (selection);

  
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {

    int i, position = 0;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != '\0') {
            position++;
        }
    }
    if (position == max) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        int id = 0;
        while (findPatientIndexByPatientNum(id, patient, max) != -1) {
            id++;
        }
        printf("Patient Data Input\n");
        printf("------------------\n");
        patient[position].patientNumber = id;
        inputPatient(&patient[position]);
        inputPhoneData(&patient[position].phone);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {

    clearInputBuffer();
    printf("Enter the patient number: ");

    int ptNum, result = 0;
    scanf("%d", &ptNum);

    clearInputBuffer();
    putchar('\n');

    result = findPatientIndexByPatientNum(ptNum, patient, max);
    if (result != -1) {
        int selection;

        do {
            printf("Edit Patient (%05d)\n"
                "=========================\n"
                "1) NAME : %s\n"
                "2) PHONE: ", patient[result].patientNumber, patient[result].name);
            displayFormattedPhone(patient[result].phone.number);

            printf("\n"
                "-------------------------\n"
                "0) Previous menu\n"
                "-------------------------\n"
                "Selection: ");
            selection = inputIntRange(0, 2);
            putchar('\n');

            if (selection == 1)
            {
                clearInputBuffer();
                char newName[NAME_LEN + 1];
                printf("Name  : ");
                inputCString(newName, 4, 15);
                strcpy(patient[result].name, newName);
                putchar('\n');
                printf("Patient record updated!\n\n");

            }
            else if (selection == 2)
            {
                if (strcmp(patient[result].phone.number, "0") == 0) {
                    clearInputBuffer();
                    inputPhoneData(&patient[result].phone);
                    printf("*** New patient record added ***\n\n");
                }
                else {
                    clearInputBuffer();
                    inputPhoneData(&patient[result].phone);
                    printf("Patient record updated!\n\n");
                }
            }
            
        } while (selection);
    
    }
    else {
        printf("*** No records found ***\n");
    }
    
  

}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int ptNum, result;
    clearInputBuffer();
    printf("Enter the patient number: ");
    scanf("%d", &ptNum);
    clearInputBuffer();
    result = findPatientIndexByPatientNum(ptNum, patient, max);
    if (result != -1) {
        putchar('\n');
        displayPatientData(&patient[result], 1);
        char selection, input[] = "yn";
        do {
            printf("\nAre you sure you want to remove this patient record? (y/n): ");
            selection = inputCharOption(input);
            if (selection == 'y') {
                patient[result].patientNumber = 0;
                patient[result].name[result] = '\0';
                patient[result].phone.description[result] = '\0';
                patient[result].phone.number[result] = '\0';
                printf("Patient record has been removed!\n\n");
            }
            else if (selection == 'n') {
                printf("Operation aborted.\n\n");
            }
        } while (selection != 'y' && selection != 'n');
    }
    else {
      
        printf("\nERROR: Patient record not found!\n\n");
    }

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int ptNum, result = 0;
    printf("Search by patient number: ");
    ptNum = inputIntPositive;
    clearInputBuffer();
    putchar('\n');

    result = findPatientIndexByPatientNum(ptNum, patient, max);
    if (result != -1) {
        displayPatientData(&patient[result], 1);
    }
    else {
        printf("*** No records found ***\n");
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    int i, result = 0, match = 0;;
    char phNum[PHONE_LEN + 1]="0";

    printf("Search by phone number: ");
    scanf("%10[^\n]", phNum);
    clearInputBuffer();
    putchar('\n');
    displayPatientTableHeader();
    for (i = 0; i < max; i++) {
        result = strcmp(phNum, patient[i].phone.number);

        if (result == 0) {
            displayPatientData(&patient[i], 0);
            match++;
        }
    }
    if (!match) {
        printf("\n*** No records found ***");
        putchar('\n');
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i, result = 0, highest = 0;
    for (i = 0; i < max; i++) {
        if (highest < patient[i].patientNumber) {
            highest = patient[i].patientNumber;
        }
    }
    result = highest + 1;
    return result;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) { 
            return i;
        }
    }
        
        return -1;   
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {

    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    scanf("%15[^\n]", patient->name);
    clearInputBuffer();
    putchar('\n');
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {

    int selection;

    do {
        printf("Phone Information\n"
            "-----------------\n"
            "How will the patient like to be contacted?\n"
            "1. Cell\n"
            "2. Home\n"
            "3. Work\n"
            "4. TBD\n");

        printf("Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');

        if (selection == 1)
        {
            clearInputBuffer();
            strcpy(phone->description, "CELL");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            scanf("%10[^\n]", phone->number);
            clearInputBuffer();
            putchar('\n');
            selection = 0;

        }
        else if (selection == 2)
        {
            clearInputBuffer();
            strcpy(phone->description, "HOME");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            scanf("%10[^\n]", phone->number);
            clearInputBuffer();
            putchar('\n');
            selection = 0;
        }
        else if (selection == 3)
        {
            clearInputBuffer();
            strcpy(phone->description, "WORK");
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            scanf("%10[^\n]", phone->number);
            clearInputBuffer();
            putchar('\n');
            selection = 0;
        }
        else if (selection == 4)
        {
            clearInputBuffer();
            strcpy(phone->description, "TBD");
            selection = 0;
        }
        

    } while (selection);


}