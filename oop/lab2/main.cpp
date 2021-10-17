#include <iostream>
#include <cstring>
#include <algorithm>
#include "SellingGoodsAccounter.h"

void printNTimes(const std::string &str, size_t times) {
    for (int i = 0; i < times; i++) {
        std::cout << str;
    }
}

void drawHeaderRow() {
    std::cout << "\u2554";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u2566";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u2557" << std::endl;
}

void drawFooterRow() {
    std::string box_horizontal_line = "\u2550";
    std::cout << "\u255A";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u2569";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u255D" << std::endl;
}

void drawRow(const SellingGoodsAccounter &accounter) {
    std::cout << "\u2551";
    printf("%10s", accounter.getAccounterName());
    std::cout << "\u2551";
    printf("%6ld", accounter.getGoodsNumber());
    std::cout << "\u2551";
    printf("%8ld", accounter.getLastMonthTotalRevenue());
    std::cout << "\u2551";
    printf("%8ld", accounter.getDailyAverageRevenue());
    std::cout << "\u2551" << std::endl;
}

void drawRawFloor() {
    std::cout << "\u2560";
    std::string box_horizontal_line = "\u2550";
    printNTimes(box_horizontal_line, 10);
    std::cout << "\u256C";
    printNTimes(box_horizontal_line, 6);
    std::cout << "\u256C";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u256C";
    printNTimes(box_horizontal_line, 8);
    std::cout << "\u2563" << std::endl;
}

bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

SellingGoodsAccounter *readInput() {
    char *accounterName = new char[11];
    char *goodsNumber = new char[7];
    char *lastMonthTotalRevenue = new char[9];
    char *dailyAverageRevenue = new char[9];
    char *pEnd;
    while (true) {
        try {
            std::cout << "Введіть назву філії (макс. довжина - 10 символів):\n";
            scanf("%s", accounterName);
            if (strlen(accounterName) <= 10 && strlen(accounterName) > 0) {
                std::cout << "Назва філії введена успішно." << std::endl;
            } else {
                throw "Довжина назви філії перевищує вказаний ліміт.";
            }

            std::cout << "Введіть загальну кількість назв товарів (макс. кількість - 999999 товарів):\n";
            scanf("%s", goodsNumber);
            if (strlen(goodsNumber) > 6) {
                throw "Загальна кількість назв товарів перевищує вказаний ліміт.";
            } else if (!is_digits(goodsNumber)) {
                throw "Дані містять некоректні символи.";
            } else {
                std::cout << "Загальна кількість назв товарів введена успішно." << std::endl;
            }

            std::cout << "Введіть загальний обсяг продажу за минулий місяць (макс. обсяг продажу - 99999999 у. о.):\n";
            scanf("%s", lastMonthTotalRevenue);
            if (strlen(lastMonthTotalRevenue) > 8) {
                throw "Загальний обсяг продажу за минулий місяць перевищує вказаний ліміт.";
            } else if (!is_digits(lastMonthTotalRevenue)) {
                throw "Дані містять некоректні символи.";
            } else {
                std::cout << "Загальний обсяг продажу за минулий місяць введений успішно." << std::endl;
            }

            std::cout << "Введіть середній денний обсяг продажу (макс. обсяг продажу - 99999999 у. о.):\n";
            scanf("%s", dailyAverageRevenue);
            if (strlen(dailyAverageRevenue) > 8) {
                throw "Середній денний обсяг продажу перевищує вказаний ліміт.";
            } else if (!is_digits(dailyAverageRevenue)) {
                throw "Дані містять некоректні символи.";
            } else {
                std::cout << "Середній денний обсяг продажу введений успішно." << std::endl;
            }
            break;
        } catch (const char *error_message) {
            std::cerr << error_message << std::endl;
        }
    }
    auto *pAccounter = new SellingGoodsAccounter(accounterName,
                                                 strtol(goodsNumber, &pEnd, 10),
                                                 strtol(lastMonthTotalRevenue, &pEnd, 10),
                                                 strtol(dailyAverageRevenue, &pEnd, 10));
    delete[] accounterName;
    delete[] goodsNumber;
    delete[] lastMonthTotalRevenue;
    delete[] dailyAverageRevenue;
    return pAccounter;
}

int main() {
    SellingGoodsAccounter accounterDefault;
    SellingGoodsAccounter accounterInitialized("Mongo", 523042, 22569, 12380);
    SellingGoodsAccounter accounterCopied = accounterInitialized;

    SellingGoodsAccounter *readAccounter = readInput();

    drawHeaderRow();
    drawRow(accounterDefault);
    drawRawFloor();
    drawRow(*readAccounter);
    drawRawFloor();
    drawRow(accounterInitialized);
    drawRawFloor();
    drawRow(accounterCopied);
    drawFooterRow();

    return 0;
}
