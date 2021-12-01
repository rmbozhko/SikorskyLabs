//
// Created by rbozhko on 11/7/2021.
//

#include "Person.h"

char *Person::getName() const {
    return name;
}

void Person::setName(char *name) {
    Person::name = name;
}

char *Person::getSurname() const {
    return surname;
}

void Person::setSurname(char *surname) {
    Person::surname = surname;
}

const Date &Person::getDate() const {
    return date;
}

void Person::setDate(const Date &date) {
    Person::date = date;
}

Person::Person(char *name, char *surname, const Date &date) : name(name), surname(surname), date(date) {}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "name: " << person.name << " surname: " << person.surname << " date: " << person.date;
    return os;
}
