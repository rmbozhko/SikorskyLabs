//
// Created by rbozhko on 11/7/2021.
//

#ifndef FINAL_MEDICINE_H
#define FINAL_MEDICINE_H
#define NUMBER_OF_MEDICINES 10

class Medicine {
private:
    char*   name;
    float   price;

public:
    Medicine() = default;

    Medicine(char *name, float price);

    char *getName() const;

    void setName(char *name);

    float getPrice() const;

    void setPrice(float price);
};


#endif //FINAL_MEDICINE_H
