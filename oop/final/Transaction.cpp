//
// Created by rbozhko on 11/7/2021.
//

#include "Transaction.h"

float Transaction::getTotal() const {
    return total;
}

void Transaction::setTotal(float total) {
    Transaction::total = total;
}
