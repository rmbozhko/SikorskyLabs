//
// Created by rbozhko on 11/10/2021.
//

#include <iostream>
#include "File.h"

char *File::getName() const {
    return name;
}

const std::string &File::getExtension() const {
    return extension;
}

Date File::getCreationDate() const {
    return creationDate;
}

unsigned long File::getSize() const {
    return size;
}

File::File(char *name, std::string  extension, Date &creationDate, unsigned long size) : name(name),
                                                                                        extension(std::move(extension)),
                                                                                        creationDate(creationDate),
                                                                                        size(size) {}

std::ostream &operator<<(std::ostream &os, const File &file) {
    os << "name: " << file.name << " extension: " << file.extension << " creationDate: " << file.creationDate
       << " size: " << file.size;
    return os;
}

void File::setName(char *name) {
    File::name = name;
}

void File::setExtension(const std::string &extension) {
    File::extension = extension;
}

void File::setCreationDate(const Date &creationDate) {
    File::creationDate = creationDate;
}

void File::setSize(unsigned long size) {
    File::size = size;
}

void File::Show() {
    std::cout << "File ";
    std::cout << "{\n\t\"name\": " << "\"" << this->name << "\",\n\t" <<
                "\"extension\": " << "\"" <<  this->extension << "\",\n\t" <<
                "\"creationDate\": " << this->creationDate.getDay() << "/" << this->creationDate.getMonth() << "/" << this->creationDate.getYear() << "\n\t" <<
                "\"size\": " << this->size << "\n}" << std::endl;
}
