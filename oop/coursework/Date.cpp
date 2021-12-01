//
// Created by rbozhko on 11/7/2021.
//

#include "Date.h"

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

Date::Date(unsigned int year, unsigned short month, unsigned short day) : year(year), month(month), day(day) {}
