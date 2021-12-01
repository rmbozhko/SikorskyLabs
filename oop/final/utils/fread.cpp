//
// Created by rbozhko on 11/28/2021.
//

#include <fstream>
#include <iostream>
#include <cstring>
#include "utils.h"
#include "../exceptions/InvalidFile.h"

Pharmacist** read(const char* filename) {
    std::string line;
    std::ifstream file(filename);
    if (!file) {
        throw InvalidFile();
    }
    Pharmacist** pharmacists = new Pharmacist*[NUMBER_OF_PHARMACIST];
    int i = 0;
    while (getline (file, line)) {
        std::string name = std::string(line);
        getline (file, line);
        std::string surname = std::string(line);
        getline (file, line);
        std::string day = std::string(line);
        getline (file, line);
        std::string month = std::string(line);
        getline (file, line);
        std::string year = std::string(line);
        pharmacists[i++] = new Pharmacist((char*)strdup(name.c_str()), (char*) strdup(surname.c_str()),
                                                                        Date(atoi(day.c_str()),
                                                                                        atoi(month.c_str()),
                                                                                        atoi(year.c_str())));
    }

    file.close();
    return pharmacists;
}

Pharmacist** readBinary(const char* filename) {
    char pharmacistName[256];
    char pharmacistSurname[256];
    char pharmacistBDay[10];
    char bDayTempBuffer[10];
    std::ifstream file(filename, std::ios::out | std::ios::binary);

    if (!file) {
        throw InvalidFile();
    }
    Pharmacist** pharmacist = new Pharmacist*[NUMBER_OF_PHARMACIST];
    for (int i = 0; i < NUMBER_OF_PHARMACIST; ++i) {
        pharmacist[i] = nullptr;
    }
    for (int i = 0; !file.eof() && i < NUMBER_OF_PHARMACIST; i++) {
        bzero(pharmacistName, 256);
        bzero(pharmacistSurname, 256);
        bzero(pharmacistBDay, 10);
        bzero(bDayTempBuffer, 10);

        file.read((char*)pharmacistName, 5);
        file.read((char*)pharmacistSurname, 6);
        file.read((char*)pharmacistBDay, 7);
        if (strlen(pharmacistName) > 0 && strlen(pharmacistSurname) > 0 && strlen(pharmacistBDay) > 0) {
            int day = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay, 2));
            bzero(bDayTempBuffer, 10);
            int month = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay + 2, 1));
            int year = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay + 3, 4));
            pharmacist[i] = new Pharmacist(strdup(pharmacistName), strdup(pharmacistSurname), Date(day, month, year));
        }
    }
    file.close();
    return pharmacist;
}