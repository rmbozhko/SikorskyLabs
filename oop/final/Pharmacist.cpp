//
// Created by rbozhko on 11/7/2021.
//

#include <iostream>
#include "Pharmacist.h"

void    Pharmacist::printClassName() const {
    std::cout << "Pharmacist" << std::endl;
}

Pharmacist::Pharmacist(char *name, char *surname, const Date &dateOfBirth) : Person(name, surname, dateOfBirth) {}

std::ostream &operator<<(std::ostream &os, const Pharmacist &pharmacist) {
    os << "{\n\t\"name\": " << "\"" << pharmacist.getName() << "\",\n\t" <<
       "\"surname\": " << "\"" <<  pharmacist.getSurname() << "\",\n\t" <<
       "\"birthDay\": " << pharmacist.getDateOfBirth().getDay() << "/" <<
                            pharmacist.getDateOfBirth().getMonth() << "/" <<
                            pharmacist.getDateOfBirth().getYear() << "\n}";
    return os;
}
