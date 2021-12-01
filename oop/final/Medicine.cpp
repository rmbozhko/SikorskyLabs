//
// Created by rbozhko on 11/7/2021.
//

#include "Medicine.h"

char *Medicine::getName() const {
    return name;
}

void Medicine::setName(char *name) {
    Medicine::name = name;
}

float Medicine::getPrice() const {
    return price;
}

void Medicine::setPrice(float price) {
    Medicine::price = price;
}

Medicine::Medicine(char *name, float price) : name(name), price(price) {}
