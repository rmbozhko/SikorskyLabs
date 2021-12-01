#include <cstring>
#include <iostream>
#include <vector>
#include <random>
#include "Date.h"
#include "Pharmacist.h"
#include "utils/utils.h"
#include "exceptions/InvalidInput.h"

WeeklyReport *generateWeeklyReport(Pharmacist **pharmacists);

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

void display_menu() {
    std::cout << "Menu:" << std::endl;
    std::cout << "1. Enter data" << std::endl;
    std::cout << "2. Show data" << std::endl;
    std::cout << "3. Write data in text mode" << std::endl;
    std::cout << "4. Write data in binary mode" << std::endl;
    std::cout << "5. Read data in text mode" << std::endl;
    std::cout << "6. Read data in binary mode" << std::endl;
    std::cout << "7. Search pharmacist by name or surname" << std::endl;
    std::cout << "8. Search pharmacist by day, month or year of birth" << std::endl;
    std::cout << "0. Exit the program" << std::endl;
}

Pharmacist* read_data() {
    Pharmacist *pharmacist;
    char pharmacistName[256];
    char pharmacistSurname[256];
    char pharmacistBDay[10];
    char bDayTempBuffer[10];
    char* temp;

    while (true) {
        bzero(pharmacistName, 256);
        bzero(pharmacistSurname, 256);
        bzero(pharmacistBDay, 10);
        bzero(bDayTempBuffer, 10);
        try {
            std::cout << "Введіть ім\'я провізора (макс. довжина - 255 символів):\n";
            std::cin >> pharmacistName;
            if (strlen(pharmacistName) <= 255 && strlen(pharmacistName) > 0) {
                std::cout << "Ім\'я провізора введено успішно." << std::endl;
            } else {
                throw InvalidInputName();
            }

            std::cout << "Введіть призвіще провізора (макс. довжина - 255 символів):\n";
            std::cin >> pharmacistSurname;
            if (strlen(pharmacistSurname) < 255 && strlen(pharmacistSurname) > 0) {
                std::cout << "Призвіще провізора введено успішно." << std::endl;
                temp = strdup(pharmacistSurname);
            } else {
                throw InvalidInputSurname();
            }

            std::cout << "Введіть день народження провізора (формат - дд/мм/рррр):\n";
            std::cin >> pharmacistBDay;
            if (strlen(pharmacistBDay) == 10) {
                int day = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay, 2));
                int month = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay + 3, 2));
                int year = std::stoi(strncpy(bDayTempBuffer, pharmacistBDay + 6, 4));
                pharmacist = new Pharmacist(strdup(pharmacistName), temp, Date(day, month, year));
                std::cout << "День народження провізора введено успішно." << "\n"
                            "Провізора додано до списку провізорів аптеки." << std::endl;
            } else {
                throw InvalidInputDate();
            }
            break;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return pharmacist;
}

int main() {
    Pharmacist** pharmacists = new Pharmacist*[NUMBER_OF_PHARMACIST];
    for (int i = 0; i < NUMBER_OF_PHARMACIST; ++i) {
        pharmacists[i] = nullptr;
    }
    size_t i = 0;
    while (true) {
        display_menu();
        int input_code = read_input();
        if (is_exit_code(input_code)) break;
        switch (input_code) {
            case 1:
                try {
                    if (i < NUMBER_OF_PHARMACIST) {
                        pharmacists[i++] = read_data();
                    }
                } catch (std::exception& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;
            case 2:
                show_data(pharmacists);
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                readInputOfFile(input_code, pharmacists);
                break;
            case 7:
                readTextInputForSearch(pharmacists);
                break;
            case 8:
                readNumericalInputForSearch(pharmacists);
                break;

            default:
                std::cerr << "Invalid code" << std::endl;
        }
    }
    WeeklyReport* report = generateWeeklyReport(pharmacists);
    unsigned long* medicineQuantity = getWeekMedicineQuantity(report);
    double* operationsTotalCost = getWeekOperationsTotalCost(report);
    std::cout << "Середнє значення за тиждень кількості ліків в операціях: " << average(medicineQuantity, NUMBER_OF_OPERATIONS) << std::endl;
    std::cout << "Середнє значення за тиждень вартості операцій: " << average(operationsTotalCost, NUMBER_OF_OPERATIONS) << std::endl;
    delete medicineQuantity;
    delete operationsTotalCost;
    return 0;
}

WeeklyReport *generateWeeklyReport(Pharmacist **pharmacists) {
    std::vector<float> prices = {150.80, 19.35, 34.60, 45, 500};
    std::vector<std::string> medicine_names = {"Отривін", "Назипан", "Фервекс", "Активоване вугілля", "Доларен"};
    std::vector<double> costs = {2120.80, 1980.35, 3460.60, 4253, 5500};
    std::vector<double> quantity = {2120.80, 1980.35, 3460.60, 4253, 5500};
    Medicine** medicines = new Medicine*[NUMBER_OF_MEDICINES];
    for (size_t i = 0; i < NUMBER_OF_PHARMACIST; i++) {
        std::string &medicine_name = *select_randomly(medicine_names.begin(), medicine_names.end());
        medicines[i] = new Medicine((char*)medicine_name.c_str(),
                                    *select_randomly(prices.begin(), prices.end()));
    }
    Operation** operations = new Operation*[NUMBER_OF_OPERATIONS];
    for (size_t i = 0; i < NUMBER_OF_PHARMACIST; i++) {
        std::string &medicine_name = *select_randomly(medicine_names.begin(), medicine_names.end());
        operations[i] = new Operation(medicines, NUMBER_OF_OPERATIONS, *select_randomly(costs.begin(), costs.end()), pharmacists[i]);
    }
    WeeklyReport* report = new WeeklyReport(operations, medicines, NUMBER_OF_OPERATIONS, NUMBER_OF_MEDICINES);
    return report;
}


