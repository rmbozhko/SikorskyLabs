//
// Created by rbozhko on 10/5/2021.
//
#include <cstring>
#include <stdexcept>
#include <iostream>
#include "lab03.h"

void SellingGoodsAccounter::setAccounterName(const char* accounterName_) {
    if (strlen(accounterName_) > 10) {
        throw std::invalid_argument("Invalid data value");
    }
    strcpy(accounterName, accounterName_);
}

void SellingGoodsAccounter::setGoodsNumber(long goodsNumber_) {
    if (goodsNumber_ < 0 || goodsNumber_ > INT8_MAX) {
        throw std::invalid_argument("Invalid data value");
    }
    goodsNumber = goodsNumber_;
}

void SellingGoodsAccounter::setLastMonthTotalRevenue(long lastMonthTotalRevenue_) {
    if (lastMonthTotalRevenue_ < 0) {
        throw std::invalid_argument("Invalid data value");
    }
    lastMonthTotalRevenue = lastMonthTotalRevenue_;
}

void SellingGoodsAccounter::setDailyAverageRevenue(long dailyAverageRevenue_) {
    if (dailyAverageRevenue_ < 0) {
        throw std::invalid_argument("Invalid data value");
    }
    dailyAverageRevenue = dailyAverageRevenue_;
}

SellingGoodsAccounter::SellingGoodsAccounter(char* accounterName_, long goodsNumber_,
                                             long lastMonthTotalRevenue_, long dailyAverageRevenue_) {
    accounterName = new char [10];
    strcpy(accounterName, accounterName_);
    goodsNumber = goodsNumber_;
    lastMonthTotalRevenue = lastMonthTotalRevenue_;
    dailyAverageRevenue = dailyAverageRevenue_;
    std::cout << "Initialization constructor has finished" << std::endl;
}

SellingGoodsAccounter::SellingGoodsAccounter() : SellingGoodsAccounter("Default", 0, 0, 0) {
    std::cout << "Default constructor has finished" << std::endl;
}

SellingGoodsAccounter::SellingGoodsAccounter(const SellingGoodsAccounter &accounter) {
    delete[] accounterName;
    accounterName = accounter.accounterName;
    goodsNumber = accounter.goodsNumber;
    lastMonthTotalRevenue = accounter.lastMonthTotalRevenue;
    dailyAverageRevenue = accounter.dailyAverageRevenue;
    std::cout << "Copy constructor has finished" << std::endl;
}

SellingGoodsAccounter::~SellingGoodsAccounter() {
    delete[] accounterName;
    std::cout << "Destructor has finished" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const SellingGoodsAccounter &accounter) {
    os << "accounterName: " << accounter.accounterName << " goodsNumber: " << accounter.goodsNumber
       << " lastMonthTotalRevenue: " << accounter.lastMonthTotalRevenue << " dailyAverageRevenue: "
       << accounter.dailyAverageRevenue;
    return os;
}

const char* SellingGoodsAccounter::getAccounterName() const {
    return accounterName;
}

long SellingGoodsAccounter::getGoodsNumber() const {
    return goodsNumber;
}

long SellingGoodsAccounter::getLastMonthTotalRevenue() const {
    return lastMonthTotalRevenue;
}

long SellingGoodsAccounter::getDailyAverageRevenue() const {
    return dailyAverageRevenue;
}