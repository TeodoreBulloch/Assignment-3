#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

class Patient {
private:
    std::string name;
    std::string dob; // date of birth
    int reg_num; // registration number
    std::vector<std::string> admission_history;

public:
    Patient(std::string name, std::string dob, int reg_num);
    ~Patient();
    // getters
    std::string getName() const;
    std::string getDob() const;
    int getRegNum() const;
    std::vector<std::string> getAdmissionHistory() const;
    // setters
    void setName(std::string name);
    void setDob(std::string dob);
    void setRegNum(int reg_num);
    void addAdmission(std::string admission);
    // other member functions
    friend std::ostream& operator<<(std::ostream& os, const Patient& patient);
};

#endif  // PATIENT_H