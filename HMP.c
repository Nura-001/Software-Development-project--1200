#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// Structure to hold patient records
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
    char visitType[10];   // Admitted or Daily
    int admissionDays;    // Only relevant for admitted patients
    char appointmentDate[20]; // For daily visit patients
    char dateAdded[20]; // Date when the patient is added
};

// Maximum number of patients
#define MAX_PATIENTS 100

// Billing constants
#define DAILY_FEE 50      // Fee for daily visit
#define ADMISSION_FEE 200 // Daily fee for admitted patients

// Global variables to store patients and count
struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

// Function prototypes
void titleDisplay();
void mainMenu();
void addRecord();
void displayRecords();
void searchRecord();
void editRecord();
void dischargePatient();
int findPatientById(int id);
void clearScreen();
void pauseAndClear();

// Entry point of the program
int main() {
    mainMenu();
    return 0;
}

// Title display function
void titleDisplay() {
    clearScreen();
    printf("============================================\n");
    printf("       Hospital Management System            \n");
    printf("============================================\n");
}

// Main menu function
void mainMenu() {
    int choice;

    while (1) {
        titleDisplay();
        printf("\n1. Add Record");
        printf("\n2. Display Records");
        printf("\n3. Search Record");
        printf("\n4. Edit Record");
        printf("\n5. Discharge Patient");
        printf("\n6. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                editRecord();
                break;
            case 5:
                dischargePatient();
                break;
            case 6:
                printf("\nExiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
                pauseAndClear();
        }
    }
}

// Add record function
void addRecord() {
    if (patientCount >= MAX_PATIENTS) {
        printf("\nCannot add more records. Maximum limit reached.\n");
        pauseAndClear();
        return;
    }

    struct Patient p;
    printf("\nEnter patient ID: ");
    scanf("%d", &p.id);

    // Check for duplicate ID
    if (findPatientById(p.id) != -1) {
        printf("\nA patient with this ID already exists. Please use a unique ID.\n");
        pauseAndClear();
        return;
    }

    printf("Enter patient name: ");
    scanf(" %[^\n]%*c", p.name);  // Allows spaces in name

    // Input validation for age
    do {
        printf("Enter patient age (0-120): ");
        scanf("%d", &p.age);
        if (p.age < 0 || p.age > 120) {
            printf("\nInvalid age! Please enter an age between 0 and 120.\n");
        }
    } while (p.age < 0 || p.age > 120);

    printf("Enter patient disease: ");
    scanf(" %[^\n]%*c", p.disease);  // Allows spaces in disease name

    // Determine if the patient is admitted or daily visit
    printf("Enter visit type (Admitted/Daily): ");
    scanf("%s", p.visitType);

    if (strcmp(p.visitType, "Admitted") == 0) {
        // If admitted, ask for the number of admission days
        printf("Enter number of days for admission: ");
        scanf("%d", &p.admissionDays);
    } else {
        // If daily visit, ask for an appointment date
        printf("Enter appointment date (DD/MM/YYYY): ");
        scanf("%s", p.appointmentDate);
        p.admissionDays = 0; // No admission days for daily visit
    }

    // Enter the date the patient was added
    printf("Enter the date of record (DD/MM/YYYY): ");
    scanf("%s", p.dateAdded);

    patients[patientCount++] = p;
    printf("\nRecord added successfully!\n");
    pauseAndClear();
}

// Display records function
void displayRecords() {
    if (patientCount == 0) {
        printf("\nNo records found!\n");
    } else {
        printf("\nPatient Records:\n");
        printf("-----------------------------------------------------------------------\n");
        printf("ID\tName\t\tAge\tDisease\t\tVisit Type\tAdmission Days\tAppointment Date\tDate Added\n");
        printf("-----------------------------------------------------------------------\n");
        for (int i = 0; i < patientCount; i++) {
            printf("%d\t%-15s\t%d\t%-15s\t%-10s\t%d\t\t%s\t\t%s\n",
                   patients[i].id,
                   patients[i].name,
                   patients[i].age,
                   patients[i].disease,
                   patients[i].visitType,
                   patients[i].admissionDays,
                   patients[i].appointmentDate,
                   patients[i].dateAdded);
        }
    }
    pauseAndClear();
}

// Discharge patient function
void dischargePatient() {
    int id;
    printf("\nEnter patient ID to discharge: ");
    scanf("%d", &id);

    int index = findPatientById(id);
    if (index != -1) {
        struct Patient p = patients[index];
        printf("\nDischarging Patient ID: %d\n", p.id);

        // Calculate bill based on visit type
        int bill = 0;
        if (strcmp(p.visitType, "Admitted") == 0) {
            bill = p.admissionDays * ADMISSION_FEE;
        } else {
            bill = DAILY_FEE;
        }

        printf("Patient Name: %s\n", p.name);
        printf("Total Bill: $%d\n", bill);

        // Remove patient after discharge
        for (int i = index; i < patientCount - 1; i++) {
            patients[i] = patients[i + 1];
        }
        patientCount--;

        printf("\nPatient discharged successfully!\n");
    } else {
        printf("\nPatient not found!\n");
    }
    pauseAndClear();
}

// Search record function
void searchRecord() {
    int id;
    printf("\nEnter patient ID to search: ");
    scanf("%d", &id);

    int index = findPatientById(id);
    if (index != -1) {
        printf("\nPatient Found:\n");
        printf("ID: %d\n", patients[index].id);
        printf("Name: %s\n", patients[index].name);
        printf("Age: %d\n", patients[index].age);
        printf("Disease: %s\n", patients[index].disease);
        printf("Visit Type: %s\n", patients[index].visitType);
        if (strcmp(patients[index].visitType, "Admitted") == 0) {
            printf("Admission Days: %d\n", patients[index].admissionDays);
        } else {
            printf("Appointment Date: %s\n", patients[index].appointmentDate);
        }
        printf("Date Added: %s\n", patients[index].dateAdded);
    } else {
        printf("\nRecord not found!\n");
    }
    pauseAndClear();
}

// Edit record function
void editRecord() {
    int id;
    printf("\nEnter patient ID to edit: ");
    scanf("%d", &id);

    int index = findPatientById(id);
    if (index != -1) {
        printf("\nEditing Record for Patient ID: %d\n", patients[index].id);

        printf("Enter new patient name (current: %s): ", patients[index].name);
        scanf(" %[^\n]%*c", patients[index].name);

        do {
            printf("Enter new patient age (current: %d): ", patients[index].age);
            scanf("%d", &patients[index].age);
            if (patients[index].age < 0 || patients[index].age > 120) {
                printf("\nInvalid age! Please enter an age between 0 and 120.\n");
            }
        } while (patients[index].age < 0 || patients[index].age > 120);

        printf("Enter new patient disease (current: %s): ", patients[index].disease);
        scanf(" %[^\n]%*c", patients[index].disease);

        printf("Enter new visit type (current: %s): ", patients[index].visitType);
        scanf("%s", patients[index].visitType);

        if (strcmp(patients[index].visitType, "Admitted") == 0) {
            printf("Enter new number of admission days (current: %d): ", patients[index].admissionDays);
            scanf("%d", &patients[index].admissionDays);
            patients[index].appointmentDate[0] = '\0'; // Clear appointment date if changed to Admitted
        } else {
            printf("Enter new appointment date (current: %s): ", patients[index].appointmentDate);
            scanf("%s", patients[index].appointmentDate);
            patients[index].admissionDays = 0; // Reset admission days for daily visit
        }

        printf("Enter new date of record (current: %s): ", patients[index].dateAdded);
        scanf("%s", patients[index].dateAdded);

        printf("\nRecord updated successfully!\n");
    } else {
        printf("\nRecord not found!\n");
    }
    pauseAndClear();
}

// Helper function to find patient by ID
int findPatientById(int id) {
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Helper function to clear the screen
void clearScreen() {
    system("cls");  // For Windows; use system("clear") for Linux/Unix
}

// Helper function to pause and then clear the screen
void pauseAndClear() {
    printf("\nPress any key to continue...");
    getch();
    clearScreen();
}
