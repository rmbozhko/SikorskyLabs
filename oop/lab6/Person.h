//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_PHARMACIST_H
#define FINAL_PHARMACIST_H

#include <ostream>
#include "Date.h"

class Person {
private:
    char*   name;
    char*   surname;
    Date    date;
public:
    Person() = default;
    Person(char *name, char *surname, const Date &date);

    char *getName() const;

    void setName(char *name);

    char *getSurname() const;

    void setSurname(char *surname);

    const Date &getDate() const;

    void setDate(const Date &date);

    friend std::ostream &operator<<(std::ostream &os, const Person &person);
};


#endif //FINAL_PHARMACIST_H
