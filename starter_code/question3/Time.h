#ifndef COSC1076_A3_DATE_H
#define COSC1076_A3_DATE_H

#include <iostream>

#define MINS_PER_HOUR   60
#define SECS_PER_MIN    60
#define HOURS_PER_DAY   24
#define SECS_PER_DAY    MINS_PER_HOUR*SECS_PER_MIN*HOURS_PER_DAY

class Time{
//Contract: This class can only be used when the time is within 
//              a particular day. If any operation takes the time 
//              to the previous or next day, then this class 
//              should not be used.

public:    
    
    // Constructors/DeConstructors
    Time();
    
    //Contract: hour, minute, second should be valid
    //          hour should be a positive number in range [0,23], 
    //          minute should be a number in range [0,59], 
    //          second should be a numbers in range [0,59]. 
    Time(unsigned int hour, unsigned int minute, unsigned int second);
    
    //nSeconds is the number of seconds since 00:00:00
    //Contract: nSeconds must be less than the number of 
    //             seconds in a day.
    Time(unsigned int nSeconds);
    
    Time(const Time& other);
    Time(Time&& other);
    ~Time();
    
    //Getters and setters
    unsigned int getHour();
    unsigned int getMinute();
    unsigned int getSecond();

    //nSeconds is the number of seconds since 00:00:00
    unsigned int getnSeconds() const;

    //Contract: nSeconds must be less than the number of 
    //             seconds in a day.
    void setTime(unsigned int nSeconds);

    //Contract: hour, minute, second should be valid
    //          hour should be a positive number in range [0,23], 
    //          minute should be a number in range [0,59], 
    //          second should be a numbers in range [0,59]. 
    void setTime(unsigned int hour, unsigned int minute, unsigned int second);

    /*                                           */
    /* YOU MAY ADD YOUR MODIFICATIONS HERE       */
    /*                                           */
     Time& operator+=(const Time& other);
    // Preconditions: None
    // Postconditions: The current Time object is updated by adding the given Time object
    // Returns: A reference to the current Time object

    Time operator+(const Time& other) const;
    // Preconditions: None
    // Postconditions: The current Time object and the given Time object are added, and a new Time object is returned

    Time& operator-=(const Time& other);
    // Preconditions: None
    // Postconditions: The current Time object is updated by subtracting the given Time object
    // Returns: A reference to the current Time object

    Time operator-(const Time& other) const;
    // Preconditions: None
    // Postconditions: The given Time object is subtracted from the current Time object, and a new Time object is returned

    bool operator==(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is equal to the given Time object; false otherwise

    bool operator!=(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is not equal to the given Time object; false otherwise

    bool operator>(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is greater than the given Time object; false otherwise

    bool operator<(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is less than the given Time object; false otherwise

    bool operator>=(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is greater than or equal to the given Time object; false otherwise

    bool operator<=(const Time& other) const;
    // Preconditions: None
    // Postconditions: None
    // Returns: True if the current Time object is less than or equal to the given Time object; false otherwise

    unsigned int& operator[](const std::string& channel);
    // Preconditions: channel must be a valid channel ("hour", "minute", or "second")
    // Postconditions: None
    // Returns: A reference to the corresponding channel value of the Time object

    const unsigned int& operator[](const std::string& channel) const;
    // Preconditions: channel must be a valid channel ("hour", "minute", or "second")
    // Postconditions: None
    // Returns: A const reference to the corresponding channel value of the Time object

    friend std::ostream& operator<<(std::ostream& os, const Time& time);
    
    
private:
    /*                                           */
    /* DO NOT MOFIFY ANY CODE IN THIS SECTION    */
    /*                                           */
    unsigned int hour;
    unsigned int minute;
    unsigned int second;
};

#endif //COSC1076_A3_DATE_H