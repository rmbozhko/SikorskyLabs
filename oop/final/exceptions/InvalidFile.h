//
// Created by rbozhko on 11/28/2021.
//

#ifndef FINAL_INVALIDFILE_H
#define FINAL_INVALIDFILE_H

#include <exception>

class InvalidFile : public std::exception {
public:
    const char* what() const throw() {
        return "Failed to work with provided file";
    }
};

#endif //FINAL_INVALIDFILE_H
