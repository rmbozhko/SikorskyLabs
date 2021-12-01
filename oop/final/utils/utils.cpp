//
// Created by rbozhko on 11/26/2021.
//

#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include "../Pharmacist.h"
#include "utils.h"

struct findPharmacistByDayOrMonthOrYear {
private:
    Pharmacist** pharmacists;
    int i;
public:
    findPharmacistByDayOrMonthOrYear(Pharmacist **pharmacist) : pharmacists(pharmacist), i(-1) {}

    Pharmacist* operator() (int date) {
        while (pharmacists[++i] != nullptr) {
            const Date &dateOfBirth = pharmacists[i]->getDateOfBirth();
            if (dateOfBirth.getDay() == date || dateOfBirth.getMonth() == date || dateOfBirth.getYear() == date) {
                return pharmacists[i];
            }
        }
        return nullptr;
    };
};

struct findPharmacistByNameOrSurname {
private:
    Pharmacist** pharmacists;
    int i;
public:
    findPharmacistByNameOrSurname(Pharmacist **pharmacists) : pharmacists(pharmacists), i(-1) {}

    Pharmacist* operator() (const char *str) {
        while (pharmacists[++i] != nullptr) {
            if (strcmp(str, pharmacists[i]->getName()) == 0 || strcmp(str, pharmacists[i]->getSurname()) == 0) {
                return pharmacists[i];
            }
        }
        return nullptr;
    };
};

void printFoundTextData(Pharmacist** pharmacists, const char* strToFind) {
    Pharmacist* result;
    findPharmacistByNameOrSurname textFinder(pharmacists);
    while ((result = textFinder(strToFind)) != nullptr) {
        std::cout << *result << ", ";
    }
    std::cout << std::endl;
}

void printFoundNumericalData(Pharmacist** pharmacists, int intToFind) {
    Pharmacist* result;
    findPharmacistByDayOrMonthOrYear numericalFinder(pharmacists);
    while ((result = numericalFinder(intToFind)) != nullptr) {
        std::cout << *result << ", ";
    }
    std::cout << std::endl;
}

bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool is_exit_code(int code) {
    return (code == 0);
}

int read_input() {
    std::string input;
    int input_code;
    while (true) {
        std::cout << "Enter the integer code of desired action: ";
        getline(std::cin, input);
        if (input.length() == 1 && is_digits(input)) {
            std::stringstream(input) >> input_code;
            break;
        }
    }
    return input_code;
}

void readNumericalInputForSearch(Pharmacist *pPharmacist[NUMBER_OF_PHARMACIST]) {
    std::string input;
    while (true) {
        std::cout << "Enter day, month or year of particular pharmacist to find: ";
        getline(std::cin, input);
        if ((input.length() == 1 || input.length() == 2 || input.length() == 4)  && is_digits(input)) {
            printFoundNumericalData(pPharmacist, atoi(input.c_str()));
            break;
        }
    }
}

void print(Pharmacist** pharmacists) {
    if (pharmacists == nullptr) return;
    for (int i = 0; pharmacists[i] != nullptr && i < NUMBER_OF_PHARMACIST; ++i) {
        std::cout << *pharmacists[i] << ", ";
    }
    std::cout << std::endl;
}

void readInputOfFile(int code, Pharmacist **pharmacists) {
    std::string filename;
    while (true) {
        std::cout << "Enter filename: ";
        getline(std::cin, filename);
        if (filename.length() <= 255) {
            switch (code) {
                case 3:
                    write(pharmacists, filename.c_str());
                    break;
                case 4:
                    writeBinary(pharmacists, filename.c_str());
                    break;
                case 5:
                    print(read(filename.c_str()));
                    break;
                case 6:
                    print(readBinary(filename.c_str()));
                    break;
            }
            break;
        }
    }
}

void readTextInputForSearch(Pharmacist *pPharmacist[10]) {
    std::string input;
    while (true) {
        std::cout << "Enter name or surname of particular pharmacist to find: ";
        getline(std::cin, input);
        if (input.length() <= 255) {
            printFoundTextData(pPharmacist, input.c_str());
            break;
        }
    }
}

const char* dateToStringFormat(Date date) {
    return strdup((std::to_string(date.getDay()) + "/" + std::to_string(date.getMonth()) + "/" + std::to_string(date.getYear())).c_str());
}

void printNTimes(const std::string &str, size_t times) {
    for (int i = 0; i < times; i++) {
        std::cout << str;
    }
}

void drawHeaderRow() {
    std::cout << "\u2554";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u2557" << std::endl;
}

void drawFooterRow() {
    std::string box_horizontal_line = "\u2550";
    std::cout << "\u255A";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u255D" << std::endl;
}

void drawRow(const Pharmacist &pharmacist) {
    std::cout << "\u2551";
    printf("%20s", pharmacist.getName());
    std::cout << "\u2551";
    printf("%20s", pharmacist.getSurname());
    std::cout << "\u2551";
    const char* dateStr = dateToStringFormat(pharmacist.getDateOfBirth());
    printf("%10s", dateStr);
    std::cout << "\u2551" << std::endl;
    free((void *) dateStr);
}

void drawRawFloor() {
    std::cout << "\u2560";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u256C";
    printNTimes(box_horizontal_line, 20);
    std::cout << "\u256C";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u2563" << std::endl;
}

void show_data(Pharmacist *pharmacists[NUMBER_OF_PHARMACIST]) {
    size_t i = 0;
    if (pharmacists[i] != nullptr) {
        pharmacists[i]->printClassName();
        drawHeaderRow();
        for (; pharmacists[i] != nullptr && i < NUMBER_OF_PHARMACIST; i++) {
            drawRow(*pharmacists[i]);
            if (i + 1 != NUMBER_OF_PHARMACIST && pharmacists[i + 1] != nullptr) {
                drawRawFloor();
            }
        }
        drawFooterRow();
    }
}
