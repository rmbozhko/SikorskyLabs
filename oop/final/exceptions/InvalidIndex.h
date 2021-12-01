//
// Created by rbozhko on 11/26/2021.
//

#ifndef FINAL_INVALIDINDEX_H
#define FINAL_INVALIDINDEX_H


#include <exception>

class InvalidIndex : public std::exception {
public:
    const char* what() const throw() {
        return "Invalid index";
    }
};

#endif //FINAL_INVALIDINDEX_H
