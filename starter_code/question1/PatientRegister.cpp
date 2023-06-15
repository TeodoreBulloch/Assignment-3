#include "PatientRegister.h"
#include "Patient.h"
#include <algorithm>
#include <stdexcept> 

PatientRegister::PatientRegister() {
    // constructor implementation
}

PatientRegister::~PatientRegister() {
    // destructor implementation
}

//This function adds a patient to the register. It checks if the patient is already present in the register by comparing their registration number. 
//If the patient is not already in the register, it is added to the patients vector
void PatientRegister::addPatient(const Patient& patient) {
    // Check if patient is already in register
    if (!isPatientInRegister(patient.getRegNum())) {
        patients.push_back(patient);
    }
}

//This function removes a patient from the register based on their registration number. It uses the erase and remove_if algorithms to remove the matching patient from the patients vector.
void PatientRegister::removePatient(int reg_num) {
    patients.erase(std::remove_if(patients.begin(), patients.end(),
                                  [reg_num](const Patient& patient) {
                                      return patient.getRegNum() == reg_num;
                                  }),
                   patients.end());
}

//This function checks if a patient with a specific registration number is already present in the register. 
//It uses the any_of algorithm to iterate over the patients vector and return true if any patient has a matching registration number.
bool PatientRegister::isPatientInRegister(int reg_num) const {
    return std::any_of(patients.begin(), patients.end(),
                       [reg_num](const Patient& patient) {
                           return patient.getRegNum() == reg_num;
                       });
}

//This function retrieves a reference to a patient with a specific registration number from the register. 
//It iterates over the patients vector and returns the first patient with a matching registration number. If no patient is found, it throws an std::invalid_argument exception.
Patient& PatientRegister::getPatient(int reg_num) {
    for (Patient& patient : patients) {
        if (patient.getRegNum() == reg_num) {
            return patient;
        }
    }
    throw std::invalid_argument("Patient not found in register");
}

//This is an overloaded [] operator for the PatientRegister class, allowing direct access to patients in the register using an index. 
//It returns a reference to the patient at the specified index in the patients vector. It performs bounds checking and throws an std::out_of_range exception if the index is out of range.
Patient& PatientRegister::operator[](int index) {
    if (index < 0 || static_cast<size_t>(index) >= patients.size()) {
        throw std::out_of_range("Index out of range");
    }
    return patients[static_cast<size_t>(index)];
}


int PatientRegister::getSize() const {
    return patients.size();
}