#include "Patient.h"
#include <iostream>

Patient::Patient(std::string name, std::string dob, int reg_num) 
    : name(name), dob(dob), reg_num(reg_num) {
    // constructor implementation
}

Patient::~Patient() {
    // destructor implementation
}

// These are getter functions that provide access to the private member variables of the Patient class. They allow retrieving the name, date of birth, registration number, and admission history of a patient.
std::string Patient::getName() const {
    return name;
}

std::string Patient::getDob() const {
    return dob;
}

int Patient::getRegNum() const {
    return reg_num;
}

std::vector<std::string> Patient::getAdmissionHistory() const {
    return admission_history;
}

// These are setter functions that allow modifying the name, date of birth, and registration number of a patient.
void Patient::setName(std::string name) {
    this->name = name;
}

void Patient::setDob(std::string dob) {
    this->dob = dob;
}

void Patient::setRegNum(int reg_num) {
    this->reg_num = reg_num;
}

//This function adds a new admission record to the patient's admission history. It takes a string parameter admission and appends it to the admission_history vector.
void Patient::addAdmission(std::string admission) {
    admission_history.push_back(admission);
}


//This is an overloaded << operator for the Patient class, allowing an instance of Patient to be printed to the standard output stream (std::cout)
//   or any other output stream. It formats and outputs the patient's information, including their name, date of birth, registration number, and admission history.
std::ostream& operator<<(std::ostream& os, const Patient& patient) {
    os << "Name: " << patient.getName() << "\n"
       << "DOB: " << patient.getDob() << "\n"
       << "Registration Number: " << patient.getRegNum() << "\n"
       << "Admission History: ";
    for (const auto& admission : patient.getAdmissionHistory()) {
        os << admission << ", ";
    }
    os << "\n";
    return os;
}

