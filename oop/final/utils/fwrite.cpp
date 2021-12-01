//
// Created by rbozhko on 11/28/2021.
//

#include "../Pharmacist.h"
#include <fstream>
#include <iostream>
#include "../exceptions/InvalidFile.h"

void write(Pharmacist** pharmacists, const char* filename) {
    std::ofstream file(filename, std::fstream::out);
    if (!file) {
        throw InvalidFile();
    }
    for (int i = 0; pharmacists[i] != nullptr && i < NUMBER_OF_PHARMACIST; ++i) {
        file << pharmacists[i]->getName() << "\n"
            << pharmacists[i]->getSurname() << "\n"
            << pharmacists[i]->getDateOfBirth().getDay() << "\n"
            << pharmacists[i]->getDateOfBirth().getMonth() << "\n"
            << pharmacists[i]->getDateOfBirth().getYear() << std::endl;
    }

    file.close();
}

void writeBinary(Pharmacist** pharmacists, const char* filename) {
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file) {
        throw InvalidFile();
    }
    for(int i = 0; pharmacists[i] != nullptr && i < NUMBER_OF_PHARMACIST; i++) {
        file.write(pharmacists[i]->getName(), 5);
        file.write(pharmacists[i]->getSurname(), 6);
        file.write(std::to_string(pharmacists[i]->getDateOfBirth().getDay()).c_str(), 2);
        file.write(std::to_string(pharmacists[i]->getDateOfBirth().getMonth()).c_str(), 1);
        file.write(std::to_string(pharmacists[i]->getDateOfBirth().getYear()).c_str(), 4);
    }
    file.close();
}
