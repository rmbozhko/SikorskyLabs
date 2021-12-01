//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_PHARMACIST_H
#define FINAL_PHARMACIST_H

#include <ostream>
#include "Person.h"
#define NUMBER_OF_PHARMACIST 10

class Pharmacist : public Person {
public:
    Pharmacist() = default;
    Pharmacist(char *name, char *surname, const Date &dateOfBirth);
    void printClassName() const override;
    friend std::ostream &operator<<(std::ostream &os, const Pharmacist &pharmacist);
};


#endif //FINAL_PHARMACIST_H
