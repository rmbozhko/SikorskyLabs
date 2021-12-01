//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_DATE_H
#define FINAL_DATE_H


#include <ostream>

class Date {
private:
    unsigned int year;
    unsigned short month;
    unsigned short day;

    bool leapYear(int year) const;

public:
    bool isValid(int year, short month, short day) const;

    Date() = default;

    Date(unsigned short day, unsigned short month, unsigned int year);

    void setYear(unsigned int year_);

    void setMonth(unsigned short month_);

    void setDay(unsigned short day_);

    unsigned long getYear() const;

    unsigned short getMonth() const;

    unsigned short getDay() const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};



#endif //FINAL_DATE_H
