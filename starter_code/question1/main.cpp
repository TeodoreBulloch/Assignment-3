#include <iostream>
#include "Patient.h"
#include "PatientRegister.h"
#include "WaitingList.h"

int main() {
    // Create some patients
    Patient patient1("John Doe", "1990-01-01", 1);
    Patient patient2("Jane Smith", "1985-05-10", 2);
    Patient patient3("Alice Johnson", "1995-09-15", 3);

    // Create a patient register
    PatientRegister patientRegister;

    // Add patients to the register
    patientRegister.addPatient(patient1);
    patientRegister.addPatient(patient2);
    patientRegister.addPatient(patient3);

    // Display the patient register
    std::cout << "Patient Register:\n";
    for (int i = 0; i < patientRegister.getSize(); ++i) {
        std::cout << patientRegister[i];
    }

    // Remove a patient from the register
    patientRegister.removePatient(2);

    // Display the updated patient register
    std::cout << "\nPatient Register after removal:\n";
    for (int i = 0; i < patientRegister.getSize(); ++i) {
        std::cout << patientRegister[i];
    }

    // Create a waiting list
    WaitingList waitingList;

    // Add patients to the waiting list
    waitingList.addPatient(patient1);
    waitingList.addPatient(patient2);
    waitingList.addPatient(patient3);

    // Get the next patient to start surgery
    Patient& nextPatient = waitingList.getNextPatient();

    // Display the next patient to start surgery
    std::cout << "\nNext Patient for Surgery:\n";
    std::cout << nextPatient;

    return 0;
}
