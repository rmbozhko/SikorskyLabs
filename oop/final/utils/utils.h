//
// Created by rbozhko on 11/26/2021.
//

#ifndef FINAL_UTILS_H
#define FINAL_UTILS_H

#include "../Pharmacist.h"
#include "../WeeklyReport.h"

template <typename T>
double average(T const* t, long n) {
    T s = t[0];
    for (int i = 1; i < n; i++) {
        s += t[i];
    }
    return sqrt(s);
}

unsigned long*    getWeekMedicineQuantity(WeeklyReport *report);
double*    getWeekOperationsTotalCost(WeeklyReport *report);

bool is_exit_code(int code);
int read_input();

void show_data(Pharmacist **pharmacists);

void readInputOfFile(int code, Pharmacist **pPharmacist);
Pharmacist** read(const char* filename);
Pharmacist** readBinary(const char* filename);
void write(Pharmacist** pharmacists, const char* filename);
void writeBinary(Pharmacist** pharmacists, const char* filename);

void readNumericalInputForSearch(Pharmacist *pPharmacist[10]);
void readTextInputForSearch(Pharmacist *pPharmacist[10]);

#endif //FINAL_UTILS_H