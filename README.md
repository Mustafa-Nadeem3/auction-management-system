# Hospital Management System

## Introduction

This is a C++ project for a Hospital Management System created using Visual Studio 2022. The system allows users to manage patient records, including adding new records, searching or editing existing records, listing patient records based on different criteria, and deleting patient records. Additionally, the system tracks financial information for each patient.

## Features

### 1. Getting Started

Upon launching the application, the user is prompted to enter the current date. This date will be used for record-keeping and date-based searches.

### 2. Add New Patient Record

This feature allows the user to add a new patient record. There are two service options: O.P.D. (Outpatient Department) and Emergency. The following information can be entered for each patient:

- Patient ID
- Age
- Sex (Male/Female)
- Disease ID
- Specialist Room Number (for O.P.D. service)

The entered information is stored in arrays for future reference.

### 3. Search or Edit Patient Record

This feature combines searching and editing patient records. Users can search for a specific patient record using either the record number or patient ID. The system displays all information associated with the patient, including medical details.

Users can also view the patient's financial records, which include the following:

- Total Charges
- Total Deposited Amount
- Total Amount to be Returned (if applicable)

If an incorrect record number or patient ID is provided, the system displays a message indicating that no records were found.

### 4. List Patient Records

Users can list patient records based on various criteria:

- Records sorted by IDs
- Records of Emergency Patients
- Records of O.P.D. Patients
- Records of Patients on a Particular Date

The system provides flexibility in organizing and viewing patient information. Financial records can also be accessed for any patient listed under these criteria.

### 5. Delete Patient Records

This feature allows users to delete patient records. To delete a record, the user must provide the patient number to be removed. After confirming the deletion, the patient record is permanently removed from the system. Prior to deletion, the user can review both medical and financial records for the patient.

## Usage

To use this Hospital Management System, follow these steps:

1. Enter the current date when prompted at the start of the application.
2. Use the menu options to add, search, edit, list, or delete patient records as needed.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow the standard GitHub fork and pull request workflow.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project was created using Visual Studio 2022.
- We appreciate the support of the open-source community.

## Contact Information

For any questions or inquiries, please contact Mustafa Nadeem at mustafanad007@gmail.com.

Feel free to customize this README file with your name, contact information, and any additional acknowledgments or relevant details specific to your project.
