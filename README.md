                                                                           Hospital Management System
 Description

Below is the console-based C program for basic hospital record management. The user will be allowed to add, edit, and search for the patients along with their discharge. A billing system is also provided for calculating fees of the admitted patients along with daily visit patients.
## Features

- **Add Patient Record**: Capture the record of a patient by providing his ID, name, age, disease, visit type (Admitted or Daily), admission days in case of an Admitted patient, appointment date in case of a Daily visit patient, and date of the record.
- **Display Patient Records**: List the records of all the patients in tabular form.
- **Search Patient Record**: Retrieve any patient record based on his unique ID.
- **Edit Patient Record**: Allows editing of the patient's information.
- **Discharge Patient**: calculate and print the bill on the patient's visit type and remove the record from the system.


Setting Up and the Requirements

- C Compiler: A C compiler is needed to compile it and run.
- Libraries used are: `stdio.h`, `stdlib.h`, `string.h`, `conio.h` for `getch()` function.
 Compilation and Execution

1. To compile, use:
```
gcc hospital_management.c -o hospital_management
```
2. Run:
```
./hospital_management
````
Usage

1. **Add Record**: Enter the patient's information, including ID, name, age, disease, and other details. A duplicate ID of an already existing patient is not allowed.
2. **Display Records**: Lists all the records with details like ID, name, age, disease, visit type, admission days/appointment date, and date while the record was added.
3. **Search Record**: Enter an ID for a patient to fast get the details of the patient.
4. **Record Edit**: Change patient information. If the type of visit is changed to "Admitted", the date of appointment will be cleared and vice-versa.
5. **Discharge Patient**: Input the ID of the patient to calculate his bill based on his visit type and then remove him from the records.
Billing Information

* **Daily Visit Patients:** $50/visit
* **Admitted Patients**: $200/day of admission

Functions Overview

* **titleDisplay**: Prints the title header of the system.
- **mainMenu**: It displays the main menu and handles the user's choices.
- **addRecord**: Adds a new patient to the system.
- **displayRecords**: Lists all the stored patient records.
- **searchRecord**: Finds a patient by ID and shows his/her details.
- **editRecord**: Edits an already stored patient's record based on his ID.
- **dischargePatient**: Discharges a patient by ID, calculates his/her bill, and deletes his record.
- **findPatientById:** Searches for a patient by his ID and returns his index.
- **clearScreen and pauseAndClear**: Functions that allow clearing the console and pausing the execution. This is for readability.
## Notes

• **Maximum Records**: The system is designed to store a maximum of 100 patient records.
• **Input Validation**: Validate for age between 0 to 120 and a unique patient ID.
