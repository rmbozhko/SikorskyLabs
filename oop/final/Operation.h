//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_OPERATION_H
#define FINAL_OPERATION_H
#include "Transaction.h"
#include "Medicine.h"
#include "Pharmacist.h"
#define NUMBER_OF_OPERATIONS 10

class Operation : public Transaction {
private:
    Medicine**      medicines;
    unsigned long   quantity;
    double          cost;
    Pharmacist*     pharmacist;
public:
    Operation() = default;

    Operation(Medicine **medicines, unsigned long quantity, double cost, Pharmacist *pharmacist);

    Medicine **getMedicine() const;

    unsigned long getQuantity() const;

    double getCost() const;

    Pharmacist *getPharmacist() const;

    Medicine& operator[](int index);
};


#endif //FINAL_OPERATION_H
