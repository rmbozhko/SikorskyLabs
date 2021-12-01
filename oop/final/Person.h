//
// Created by rbozhko on 11/26/2021.
//

#ifndef FINAL_PERSON_H
#define FINAL_PERSON_H


#include "Date.h"

class Person {
private:
    char*   name;
    char*   surname;
    Date    dateOfBirth;
public:
    Person() = default;

    Person(char *name, char *surname, const Date &dateOfBirth);

    char *getName() const;

    char *getSurname() const;

    Date getDateOfBirth() const;

    virtual void    printClassName() const;
};


#endif //FINAL_PERSON_H
