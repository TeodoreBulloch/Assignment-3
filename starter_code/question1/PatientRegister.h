#ifndef PATIENTREGISTER_H
#define PATIENTREGISTER_H

#include <vector>

class Patient;  // Forward declaration

class PatientRegister {
private:
    std::vector<Patient> patients;

public:
    PatientRegister();
    ~PatientRegister();
    // other member functions
    void addPatient(const Patient& patient);
    void removePatient(int reg_num);
    bool isPatientInRegister(int reg_num) const;
    Patient& getPatient(int reg_num);
    Patient& operator[](int index);
    int getSize() const;
};

#endif  // PATIENTREGISTER_H