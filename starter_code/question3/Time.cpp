#include "Time.h"
#include <exception>
#include <iomanip>

Time::Time():
    hour(0), minute(0), second(0)
{}

Time::Time(unsigned int hour, unsigned int minute, unsigned int second):
                            hour(hour), minute(minute), second(second)
{}


Time::Time(unsigned int nSeconds){
    this->setTime(nSeconds);
}

Time::Time(const Time& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::Time(Time&& other):
                hour(other.hour), minute(other.minute), second(other.second)
{}

Time::~Time()
{}


unsigned int Time::getHour(){
    return hour;
}
unsigned int Time::getMinute(){
    return minute;
}
unsigned int Time::getSecond(){
    return second;
}

unsigned int Time::getnSeconds() const{
    return hour*MINS_PER_HOUR*SECS_PER_MIN + minute*SECS_PER_MIN + second;
}

void Time::setTime(unsigned int nSeconds){

    second  = nSeconds%(SECS_PER_MIN);
    nSeconds = nSeconds/SECS_PER_MIN;
    minute = nSeconds%(MINS_PER_HOUR);
    hour = nSeconds/MINS_PER_HOUR;
}


void Time::setTime(unsigned int hour, unsigned int minute, unsigned int second){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

/*                                           */
/* YOU MAY ADD YOUR MODIFICATIONS HERE       */
/*                                           */

Time& Time::operator+=(const Time& other)
{
    unsigned int totalSeconds = getnSeconds() + other.getnSeconds();
    setTime(totalSeconds);
    return *this;
}

Time Time::operator+(const Time& other) const
{
    Time result = *this;
    result += other;
    return result;
}

Time& Time::operator-=(const Time& other)
{
    int diffSeconds = static_cast<int>(getnSeconds()) - static_cast<int>(other.getnSeconds());
    if (diffSeconds < 0)
        diffSeconds += SECS_PER_DAY;
    setTime(diffSeconds);
    return *this;
}

Time Time::operator-(const Time& other) const
{
    Time result = *this;
    result -= other;
    return result;
}

bool Time::operator==(const Time& other) const
{
    return getnSeconds() == other.getnSeconds();
}

bool Time::operator!=(const Time& other) const
{
    return !(*this == other);
}

bool Time::operator>(const Time& other) const
{
    return getnSeconds() > other.getnSeconds();
}

bool Time::operator<(const Time& other) const
{
    return getnSeconds() < other.getnSeconds();
}

bool Time::operator>=(const Time& other) const
{
    return getnSeconds() >= other.getnSeconds();
}

bool Time::operator<=(const Time& other) const
{
    return getnSeconds() <= other.getnSeconds();
}

unsigned int& Time::operator[](const std::string& channel)
{
    if (channel == "hour")
        return hour;
    else if (channel == "minute")
        return minute;
    else if (channel == "second")
        return second;
    else
        throw std::invalid_argument("Invalid channel");
}

const unsigned int& Time::operator[](const std::string& channel) const
{
    if (channel == "hour")
        return hour;
    else if (channel == "minute")
        return minute;
    else if (channel == "second")
        return second;
    else
        throw std::invalid_argument("Invalid channel");
}

std::ostream& operator<<(std::ostream& os, const Time& time)
{
    os << std::setfill('0') << std::setw(2) << time.hour << ":"
       << std::setfill('0') << std::setw(2) << time.minute << ":"
       << std::setfill('0') << std::setw(2) << time.second;
    return os;
}
