//
// Created by rbozhko on 11/7/2021.
//

#include "WeeklyReport.h"
#include "exceptions/InvalidIndex.h"

Operation **WeeklyReport::getOperations() const {
    return operations;
}

void WeeklyReport::setOperations(Operation **operations) {
    WeeklyReport::operations = operations;
}

Medicine **WeeklyReport::getMedicines() const {
    return medicines;
}

void WeeklyReport::setMedicines(Medicine **medicines) {
    WeeklyReport::medicines = medicines;
}

std::ostream &operator<<(std::ostream &os, const WeeklyReport &report) {
    os << "WeeklyReport { \"operations\": " << report.operations << " \"medicines\": " << report.medicines;
    return os;
}

//TODO check how is possible to return valid references
std::pair<Operation*, Medicine*> WeeklyReport::operator[](int index) {
    if (index < 0 || index > getOperationsNumber() || index > getMedicinesNumber()){
        throw InvalidIndex();
    }
    std::pair<Operation*, Medicine*> result = {this->operations[index], this->medicines[index]};
    return result;
}

size_t WeeklyReport::getOperationsNumber() const {
    return operationsNumber;
}

size_t WeeklyReport::getMedicinesNumber() const {
    return medicinesNumber;
}

WeeklyReport::WeeklyReport() {
    this->medicinesNumber = NUMBER_OF_MEDICINES;
    this->operationsNumber = NUMBER_OF_OPERATIONS;

    this->medicines = new Medicine*[this->medicinesNumber];
    for (int i = 0; i < this->medicinesNumber; ++i) {
        this->medicines[i] = new Medicine();
    }

    this->operations = new Operation*[this->operationsNumber];
    for (int i = 0; i < this->operationsNumber; ++i) {
        this->operations[i] = new Operation();
    }
}

WeeklyReport::WeeklyReport(Operation **operations, Medicine **medicines, size_t operationsNumber,
                           size_t medicinesNumber) : operations(operations), medicines(medicines),
                                                     operationsNumber(operationsNumber),
                                                     medicinesNumber(medicinesNumber) {}
