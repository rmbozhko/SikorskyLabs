//
// Created by rbozhko on 11/7/2021.
//

#include <iostream>
#include "Date.h"
#include "exceptions/InvalidInput.h"

unsigned long Date::getYear() const {
    return year;
}

unsigned short Date::getMonth() const {
    return month;
}

unsigned short Date::getDay() const {
    return day;
}

void Date::setYear(unsigned int year_) {
    Date::year = year_;
}

void Date::setMonth(unsigned short month_) {
    Date::month = month_;
}

void Date::setDay(unsigned short day_) {
    Date::day = day_;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << "Date { \"year\": " << date.year << ", \"month\": " << date.month << " \"day\": " << date.day << " }";
    return os;
}



Date::Date(unsigned short day_, unsigned short month_, unsigned int year_) : year(year_), month(month_), day(day_) {
    if (isValid(year_, month_, day_)) {
        this->day = day_;
        this->month = month_;
        this->year = year_;
    } else {
        throw InvalidInputDate();
    }
}

bool Date::leapYear(int year_) const {
    return(year_ % 100 != 0 && year_ % 4 == 0) || (year_ % 400 == 0);
}

bool Date::isValid(int year_, short month_, short day_) const {
    bool validation = true;
    if (!(year_ >= 1600 && year_ <= 2100))
        validation = false;

    if (day_ < 1)
        validation = false;

    switch (month_) {
        case 2:
            if (leapYear(year_)) {
                if (day_ > 29) {
                    validation = false;
                }
            } else {
                if (day_ > 28) {
                    validation = false;
                }
            }
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day_ > 31)
                validation = false;
            break;
        case 4: case 6: case 9: case 11:
            if (day_ > 30)
                validation = false;
            break;
        default:
            validation = false;
            break;
    }
    return validation;
}
