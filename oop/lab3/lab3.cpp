#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "lab03.h"

using namespace std;

bool is_digits(const std::string &str) {
    return std::all_of(str.begin(), str.end(), ::isdigit);
}

void display_menu() {
    cout << "Menu:" << endl;
    cout << "1. Enter data" << endl;
    cout << "2. Show data" << endl;
    cout << "0. Exit the program" << endl;
}

int read_input() {
    string input;
    int input_code;
    while (true) {
        cout << "Enter the integer code of desired action: ";
        getline(cin, input);
        if (input.length() == 1 && is_digits(input)) {
            stringstream(input) >> input_code;
            break;
        }
    }
    return input_code;
}

bool is_exit_code(int code) {
    return (code == 0);
}

SellingGoodsAccounter * read_data() {
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
    auto *accounter = new SellingGoodsAccounter(accounterName,
                                                                 strtol(goodsNumber, &pEnd, 10),
                                                                 strtol(lastMonthTotalRevenue, &pEnd, 10),
                                                                 strtol(dailyAverageRevenue, &pEnd, 10));
    delete[] accounterName;
    delete[] goodsNumber;
    delete[] lastMonthTotalRevenue;
    delete[] dailyAverageRevenue;
    return accounter;
}

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

void show_data(vector<SellingGoodsAccounter*> &accounters) {
    drawHeaderRow();
    for (int i = 0; i < accounters.size(); ++i) {
        drawRow(*accounters.at(i));
        if (i + 1 != accounters.size()) {
            drawRawFloor();
        }
    }
    drawFooterRow();
}

void handle_input(int code, vector<SellingGoodsAccounter*> &accounters) {
    switch (code) {
        case 1:
            accounters.push_back(read_data());
            break;
        case 2:
            show_data(accounters);
            break;
        default:
            cerr << "Invalid code" << endl;
    }
}

int main() {
    std::vector<SellingGoodsAccounter*> accounters;

    while (true) {
        display_menu();
        int input_code = read_input();
        if (is_exit_code(input_code)) break;
        handle_input(input_code, accounters);
    }
    return 0;
}
