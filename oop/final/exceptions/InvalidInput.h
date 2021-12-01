//
// Created by rbozhko on 11/26/2021.
//

#ifndef FINAL_INVALIDINPUT_H
#define FINAL_INVALIDINPUT_H


class InvalidInput : public std::exception {
};

class InvalidInputName : public InvalidInput {
public:
    const char* what() const throw() {
        return "Ім\'я провізора перевищує вказаний ліміт.";
    }
};

class InvalidInputSurname : public InvalidInput {
public:
    const char* what() const throw() {
        return "Призвіще провізора перевищує вказаний ліміт.";
    }
};

class InvalidInputDate : public InvalidInput {
public:
    const char* what() const throw() {
        return "Допущена помилка під час введення дати.";
    }
};



#endif //FINAL_INVALIDINPUT_H
