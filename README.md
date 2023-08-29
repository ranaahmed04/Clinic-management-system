# Clinic Management System

This is a C program for a clinic management system that allows both admin and user modes. The program provides various features such as adding new patient records, editing patient records, reserving slots with the doctor, canceling reservations, and viewing patient records and today's reservations.

## Getting Started

To run the clinic management system, follow the instructions below:

1. Clone the repository to your local machine or download the source code files.
2. Navigate to the project directory.

### Prerequisites

You need to have a C compiler installed on your machine to compile and run the program. If you don't have a C compiler, you can install one such as GCC.

### Compiling and Running

1. Open a terminal or command prompt.
2. Navigate to the project directory.
3. Compile the source code using the following command:

   `````bash
   gcc clinic_management_system.c -o clinic_management_system
   ```

4. Run the program using the following command:

   ````bash
   ./clinic_management_system
   ```

## Usage

Upon running the program, you will be prompted to choose between admin mode and user mode. The following sections explain the features available in each mode.

### Admin Mode

In admin mode, the system asks for a password. The default password is `1234`. You have three attempts to enter the correct password. After three consecutive incorrect attempts, the system will close.

Once logged in as an admin, you have access to the following features:

1. **Add new patient record**: To add a new patient, enter the patient's basic information, including name, age, gender, and ID. The ID must be unique. If the entered ID already exists, the system will reject the entry.

2. **Edit patient record**: Enter the patient's ID to check if it exists. If the ID exists, you can edit the patient's information. If not, an incorrect ID message will be displayed.

3. **Reserve a slot with the doctor**: By default, there are five available slots: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm. The system will display the available slots. Enter the patient's ID and the desired slot to reserve it. The reserved slot will not appear again in the next patient reservation.

4. **Cancel reservation**: To cancel a reservation, enter the patient's ID. The canceled reservation will be shown again in the available slots window.

### User Mode

In user mode, there is no password required. The system provides the following features:

1. **View patient record**: Enter the patient's ID to view their basic information.

2. **View today’s reservations**: This option displays all reservations for the current day, along with the patient ID attached to each reservation slot.
