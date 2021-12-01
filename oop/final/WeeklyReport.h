//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_WEEKLYREPORT_H
#define FINAL_WEEKLYREPORT_H

#include <ostream>
#include "Operation.h"
#include "Medicine.h"


class WeeklyReport {
private:
    Operation**  operations;
    Medicine**   medicines;
    size_t      operationsNumber;
    size_t      medicinesNumber;
public:
    WeeklyReport();

    WeeklyReport(Operation **operations, Medicine **medicines, size_t operationsNumber, size_t medicinesNumber);

    Operation **getOperations() const;

    void setOperations(Operation **operations);

    Medicine **getMedicines() const;

    void setMedicines(Medicine **medicines);

    std::pair<Operation*, Medicine*> operator[](int index);

    size_t getOperationsNumber() const;

    size_t getMedicinesNumber() const;

public:
    friend std::ostream &operator<<(std::ostream &os, const WeeklyReport &report);
};


#endif //FINAL_WEEKLYREPORT_H
