//
// Created by rbozhko on 10/14/2021.
//

#ifndef LAB3_LAB03_H
#define LAB3_LAB03_H

#include <ostream>

class SellingGoodsAccounter {
private:
    char*       accounterName;
    long        goodsNumber;
    long        lastMonthTotalRevenue;
    long        dailyAverageRevenue;
public:
    SellingGoodsAccounter();
    SellingGoodsAccounter(char* accounterName_, long goodsNumber_,
                          long lastMonthTotalRevenue_, long dailyAverageRevenue_);
    SellingGoodsAccounter(const SellingGoodsAccounter& accounter);
    ~SellingGoodsAccounter();

    const char* getAccounterName() const;

    long getGoodsNumber() const;

    long getLastMonthTotalRevenue() const;

    long getDailyAverageRevenue() const;

    void setAccounterName(const char* accounterName);

    void setGoodsNumber(long goodsNumber);

    void setLastMonthTotalRevenue(long lastMonthTotalRevenue);

    void setDailyAverageRevenue(long dailyAverageRevenue);

    friend std::ostream &operator<<(std::ostream &os, const SellingGoodsAccounter &accounter);
};

#endif //LAB3_LAB03_H
