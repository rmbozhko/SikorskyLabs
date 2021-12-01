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
public:
    Date() = default;
    Date(unsigned int year, unsigned short month, unsigned short day);

    void setYear(unsigned int year_);

    void setMonth(unsigned short month_);

    void setDay(unsigned short day_);

    unsigned long getYear() const;

    unsigned short getMonth() const;

    unsigned short getDay() const;

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
};



#endif //FINAL_DATE_H
