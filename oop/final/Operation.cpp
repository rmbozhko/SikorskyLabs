//
// Created by rbozhko on 11/7/2021.
//

#include "Operation.h"
#include "exceptions/InvalidIndex.h"

Medicine **Operation::getMedicine() const {
    return medicines;
}

unsigned long Operation::getQuantity() const {
    return quantity;
}

Pharmacist *Operation::getPharmacist() const {
    return pharmacist;
}

Operation::Operation(Medicine **medicines, unsigned long quantity, double cost, Pharmacist *pharmacist) : medicines(medicines),
                                                                                             quantity(quantity),
                                                                                             cost(cost),
                                                                                             pharmacist(pharmacist) {}

double Operation::getCost() const {
    return cost;
}

Medicine& Operation::operator[](int index) {
    if (index < 0 || index > getQuantity()) {
        throw InvalidIndex();
    }
    return *this->medicines[index];
}