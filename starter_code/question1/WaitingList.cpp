#include "WaitingList.h"
#include "Patient.h"
#include <stdexcept>

WaitingList::WaitingList() : nextQueueNumber(1) {
    // constructor implementation
}

WaitingList::~WaitingList() {
    // destructor implementation
}

//This function adds a patient to the waiting list. It takes a const reference to a Patient object and pushes it into the patients queue.
void WaitingList::addPatient(const Patient& patient) {
    patients.push(patient);
}

//This function removes the next patient from the waiting list. It checks if the waiting list is not empty before calling the pop function on the patients queue to remove the front patient.
void WaitingList::removePatient() {
    if (!patients.empty()) {
        patients.pop();
    }
}

//This function retrieves a reference to the next patient in the waiting list. 
//It checks if the waiting list is not empty and returns a reference to the front patient using front function of the patients queue. 
//If the waiting list is empty, it throws an std::out_of_range exception.
Patient& WaitingList::getNextPatient() {
    if (!patients.empty()) {
        return patients.front();
    }
    throw std::out_of_range("Waiting list is empty");
}

//This function returns the value of nextQueueNumber, which represents the next available queue number for a patient.
int WaitingList::getNextQueueNumber() const {
    return nextQueueNumber;
}

bool WaitingList::isEmpty() const {
    return patients.empty();
}
