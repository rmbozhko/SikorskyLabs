//
// Created by rbozhko on 11/26/2021.
//
#include "utils.h"

unsigned long*    getWeekMedicineQuantity(WeeklyReport *report) {
    unsigned long*    arr;

    arr = new unsigned long[NUMBER_OF_OPERATIONS];
    for (int i = 0; i < NUMBER_OF_OPERATIONS; i++) {
        arr[i] = (*report)[i].first->getQuantity();
    }

    return arr;
}

double*    getWeekOperationsTotalCost(WeeklyReport *report) {
    double*    arr;

    arr = new double[NUMBER_OF_OPERATIONS];
    for (int i = 0; i < NUMBER_OF_OPERATIONS; i++) {
        arr[i] = (*report)[i].first->getCost();
    }

    return arr;
}