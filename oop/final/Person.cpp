//
// Created by rbozhko on 11/26/2021.
//

#include <iostream>
#include "Person.h"

Person::Person(char *name, char *surname, const Date &dateOfBirth) : name(name), surname(surname), dateOfBirth(dateOfBirth) {}

char *Person::getName() const {
    return name;
}

char *Person::getSurname() const {
    return surname;
}

Date Person::getDateOfBirth() const {
    return dateOfBirth;
}

void    Person::printClassName() const {
    std::cout << "Person" << std::endl;
}
