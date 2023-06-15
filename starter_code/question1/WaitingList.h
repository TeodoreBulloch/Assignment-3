#ifndef WAITINGLIST_H
#define WAITINGLIST_H

#include <queue>

class Patient;  // Forward declaration

class WaitingList {
private:
    std::queue<Patient> patients;
    int nextQueueNumber; // Keep track of the next queue number

public:
    WaitingList();
    ~WaitingList();
    // other member functions
    void addPatient(const Patient& patient);
    void removePatient();
    Patient& getNextPatient();
    int getNextQueueNumber() const;
    bool isEmpty() const;
};

#endif  // WAITINGLIST_H