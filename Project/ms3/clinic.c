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
#define OPEN_HOUR 10
#define CLOSE_HOUR 14
#define ITERVAL 30
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    displayPatientTableHeader();
    int i;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
        }
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (Copy your code from MS#2)
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
            
            searchPatientByPatientNumber(patient, max);
            putchar('\n');
            suspend();
        }
        else if (selection == 2)
        {
        
            searchPatientByPhoneNumber(patient, max);
            putchar('\n');
            suspend();
        }

    } while (selection);


}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {

    int position= findPatientIndexByPatientNum(0, patient, max);
    if (position == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else {
        int id;
        id = nextPatientNumber(patient, max);
        printf("Patient Data Input\n");
        printf("------------------\n");
        patient[position].patientNumber = id;
        inputPatient(&patient[position]);
        inputPhoneData(&patient[position].phone);
        printf("*** New patient record added ***\n\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {

    
    printf("Enter the patient number: ");

    int ptNum, result = 0;
   ptNum= inputIntPositive();


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
                   
                    inputPhoneData(&patient[result].phone);
                    printf("*** New patient record added ***\n\n");
                }
                else {
                    
                    inputPhoneData(&patient[result].phone);
                    printf("Patient record updated!\n\n");
                }
            }

        } while (selection);

    }
    else {
        printf("*** No records found ***\n\n");
    }

}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int ptNum, result;
    printf("Enter the patient number: ");
    ptNum = inputIntPositive();
  
    result = findPatientIndexByPatientNum(ptNum, patient, max);
    if (result != -1) {
        putchar('\n');
        displayPatientData(&patient[result], 1);
        char selection, input[] = "yn";
        do {
            printf("\nAre you sure you want to remove this patient record? (y/n): ");
     
            selection = inputCharOption(input);
            clearInputBuffer();
            if (selection == 'y') {
                patient[result].patientNumber = 0;
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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {
    struct Date date =  inputDate();
   
    putchar('\n');

    sort(data->appointments, data->maxAppointments);

   displayScheduleTableHeader(&date, 0);
   int i, j;
   for (i = 0; i < data->maxAppointments; i++) {
       if (data->appointments[i].ptNumber) {
           for (j = 0; j < data->maxPatient; j++) {
               if (data->appointments[i].ptNumber == data->patients[j].patientNumber && data->appointments[i].date.year == date.year &&
                   data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day) {
                   displayScheduleData(&data->patients[j], &data->appointments[i], 0);
               }
           }
       }
   }


    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appoint, int maxAppt, struct Patient* patient, int maxPatients) {

   // struct Date date;
    struct Time time;

    int ptNum, index, availability;

    printf("Patient Number: ");
    ptNum = inputIntPositive();
    index = findPatientIndexByPatientNum(ptNum, patient, maxPatients);

    if (!(index >= 0)) {
        printf("\nERROR: Patient record not found!\n\n");
    }
    else {

        availability = isFull(appoint, maxPatients);       
       
        if (availability == 1) {
        
            int flagDate = 1;
            while (flagDate) {
                
                struct Date date = inputDate();

                int timeFlag = 1;
                while (timeFlag) {
                    printf("Hour (0-23)  : ");
                    time.hour = inputIntRange(0, 23);
                    printf("Minute (0-59): ");
                    time.min = inputIntRange(0, 59);
                    if (time.hour > CLOSE_HOUR || time.hour < OPEN_HOUR || (time.hour == CLOSE_HOUR && time.min > 0) || time.min % ITERVAL != 0) {
                        printf("ERROR: Time must be between %d:00 and %d:00 in 30 minute intervals.\n\n", OPEN_HOUR, CLOSE_HOUR);
                    }
                    else {
                        timeFlag = 0;
                    }
                }

                int  availableSlot = searchTimeSlot(appoint, date, time, maxAppt);

                if (availableSlot != -1) {
                    appoint->ptNumber = ptNum;
                    appoint->date.year = date.year;
                    appoint->date.month = date.month;
                    appoint->date.day = date.day;
                    appoint->time.hour = time.hour;
                    appoint->time.min = time.min;
                    printf("\n*** Appointment scheduled! ***\n\n");
                    flagDate = 0;
                }
                else {
                    printf("\nERROR: Appointment timeslot is not available!\n\n");
                }      
            }
        }
        else {
            printf("ERROR: Schedule reached maximum capacity of %d appointments", maxAppt);
        }     
    }
}
     

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appoint, int maxAppt, struct Patient* patient, int maxPatients) {
 

    int index, ptNum;

    printf("Patient Number: ");
    ptNum = inputIntPositive();

    index = findPatientIndexByPatientNum(ptNum, patient, maxPatients);

    if (!(index >= 0)) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        
        struct Date date = inputDate();

        int appt = bookedAppt(ptNum, date, appoint, maxAppt);
        
        if (appt != -1) {
           
            putchar('\n');
            
            displayPatientData(&patient[index], 1);
            char selection, input[] = "yn";
            do {
                printf("Are you sure you want to remove this appointment (y,n): ");
                selection = inputCharOption(input);
                clearInputBuffer();

                if (selection == 'y') {
                    appoint[appt].ptNumber = 0;
                    printf("\nAppointment record has been removed!\n\n");
                }
                else if (selection == 'n') {
                    printf("Operation aborted.\n\n");
                }
            } while (selection != 'y' && selection != 'n');
            
        }
    }
}
    
//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {

    int i, j;

    sort(data->appointments, data->maxAppointments);

    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) {
        for (j = 0; j < data->maxPatient; j++) {
            if (data->appointments[i].ptNumber == data->patients[j].patientNumber) {
                displayScheduleData(&data->patients[j], &data->appointments[i], 1);
            }
        }
    }

    putchar('\n');
}

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int ptNum, result = 0;
    printf("Search by patient number: ");
    ptNum = inputIntPositive();
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    int i, result = 0, match = 0;;
    char phNum[PHONE_LEN + 1] = "0";

    printf("Search by phone number: ");
    inputCString(phNum, 0, 10);
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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
    int i, result = 0, highest = patient[0].patientNumber;
    for (i = 0; i < max; i++) {
        if (highest < patient[i].patientNumber) {
            highest = patient[i].patientNumber;
        }
    }
    result = highest + 1;
    return result;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    return -1;
}

/// Sort schedule 
void sort(struct Appointment *appoints, int max) {
    int i, j, lowest;
    struct Appointment temp;

    // Using selection sort to compare appointment dates and times
    for (i = 0; i < max - 1; i++)
    {
        lowest = i;
        for (j = i + 1; j < max; j++)
        {
            if (appoints[j].date.year < appoints[lowest].date.year || (appoints[j].date.year == appoints[lowest].date.year && (appoints[j].date.month < appoints[lowest].date.month ||
               (appoints[j].date.month == appoints[lowest].date.month && (appoints[j].date.day < appoints[lowest].date.day || (appoints[j].date.day == appoints[lowest].date.day &&
               (appoints[j].time.hour < appoints[lowest].time.hour || (appoints[j].time.hour == appoints[lowest].time.hour && appoints[j].time.min < appoints[lowest].time.min))))))))
            {
                lowest = j;
            }
        }
        if (lowest != i)
        {
            temp = appoints[i];
            appoints[i] = appoints[lowest];
            appoints[lowest] = temp;
        }
    }
}

////check if schedule is full
int isFull(struct Appointment* appoint, int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (appoint[i].ptNumber == 0) {
            return 1;
        }
    }
    return -1;
}

////Search time slot
int searchTimeSlot(struct Appointment* appoints, struct Date date, struct Time time, int max) {
    int i = 0, available = 1;
    while (i < max && available) {
        if (appoints[i].date.year == date.year && appoints[i].date.month == date.month && appoints[i].date.day == date.day &&
            appoints[i].time.hour == time.hour && appoints[i].time.min == time.min)
        {
            available = 0;
        }
        i++;
    }
    if (available) {
        return 1;
    }
    else {
        return -1;
    }

}

////finds booked appt
int bookedAppt(int patientNumber, struct Date date, struct Appointment* appoint, int max) {
    int i ;

    for (i = 0; i < max; i++) {
        if ((appoint[i].ptNumber == patientNumber) && (appoint[i].date.day == date.day) && (appoint[i].date.month == date.month) && (appoint[i].date.year == date.year)) {
            return i;
        }
    }
    return -1;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient) {

    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 4, 15);
    putchar('\n');
}

// Get user input for phone contact information
// (Copy your code from MS#2)
void inputPhoneData(struct Phone* phone) {
    const char* descriptions[] = { "CELL", "HOME", "WORK", "TBD" };
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

        if (selection >= 1 && selection <= 3)
        {
          
            strcpy(phone->description, descriptions[selection - 1]);
            printf("Contact: %s\n", phone->description);
            printf("Number : ");
            inputCString(phone->number, 0, 10);
            putchar('\n');
            selection = 0;

        }
        else if (selection == 4)
        {
            strcpy(phone->description, descriptions[3]);
            selection = 0;
        }
    } while (selection);
}

//input date 
struct Date inputDate() {
    struct Date date;
    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(1, 12);

    if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12) {
        printf("Day (1-31)  : ");
        date.day = inputIntRange(1, 31);
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        printf("Day (1-30)  : ");
        date.day = inputIntRange(1, 30);
    }
    else {
        if (date.year % 4 == 0) {
            printf("Day (1-29)  : ");
            date.day = inputIntRange(1, 29);
        }
        else {
            printf("Day (1-28)  : ");
            date.day = inputIntRange(1, 28);
        }
    }

    return date;
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {
    
    int patientCount = 0;
    int result = 0;


    FILE* ptr = fopen(datafile, "r");

    if (ptr != NULL) {
        while (patientCount < max && result != EOF) {
            result = fscanf(ptr, "%d|%[^|]|%[^|]|%[^\n]", &patients[patientCount].patientNumber, patients[patientCount].name,
                patients[patientCount].phone.description, patients[patientCount].phone.number);
            
            if (result != EOF) {
                patientCount++;
            }
        }

        fclose(ptr);
    }
    else {
        printf("ERROR: Failed to read file\n");
    }

    return patientCount;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {

    int i, appointmentCount = 0;
    int result = 0;

    FILE* ptr;
    ptr = fopen(datafile, "r");


    if (ptr != NULL) {

    
        for (i = 0; i < max && result != EOF; i++) {
          
           result = fscanf(ptr, "%d,%d,%d,%d,%d,%d", &appoints[appointmentCount].ptNumber, 
                &appoints[appointmentCount].date.year, &appoints[appointmentCount].date.month, 
                &appoints[appointmentCount].date.day, &appoints[appointmentCount].time.hour, 
                &appoints[appointmentCount].time.min);

            if (result != EOF) {
                appointmentCount++;
            }
        }

        fclose(ptr);
    }

    else {
        printf("ERROR: File could not be read\n");
    }

    return appointmentCount;
}


