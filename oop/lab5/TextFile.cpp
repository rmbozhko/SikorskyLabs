//
// Created by rbozhko on 11/10/2021.
//

#include <iostream>
#include "TextFile.h"

const std::string &TextFile::getLocation() const {
    return location;
}

Person  TextFile::getAuthor() const {
    return author;
}

const std::vector<std::string> &TextFile::getKeywords() const {
    return keywords;
}

TextFile& TextFile::operator=(const TextFile& rhs) {
    this->setName(rhs.getName());
    this->setExtension(rhs.getExtension());
    this->setCreationDate(rhs.getCreationDate());
    this->setSize(rhs.getSize());
    this->author = rhs.author;
    this->location = rhs.location;
    this->keywords = rhs.keywords;
    return *this;
}

TextFile::TextFile(char *name, const std::string &extension, Date &creationDate, unsigned long size,
                   std::string location, Person &author, std::vector<std::string> keywords) : File(name,
                                                                                                                 extension,
                                                                                                                 creationDate,
                                                                                                                 size),
                                                                                                            location(std::move(
                                                                                                                    location)),
                                                                                                            author(author),
                                                                                                            keywords(std::move(
                                                                                                                    keywords)) {}

std::ostream &operator<<(std::ostream &os, const TextFile &file) {
    os << static_cast<const File &>(file) << " location: " << file.location << " author: " << file.author;
    return os;
}

void TextFile::Show() {
    std::cout << "{\n\t\"name\": " << "\"" << this->getName() << "\",\n\t" <<
              "\"extension\": " << "\"" <<  this->getExtension() << "\",\n\t" <<
              "\"creationDate\": " << this->getCreationDate().getDay() << "/" << this->getCreationDate().getMonth() << "/" << this->getCreationDate().getYear() << "\n\t" <<
              "\"size\": " << this->getSize() << "\",\n\t" <<
              "\"author\": " << this->author.getName() << " " << this->author.getSurname() << "\",\n\t" <<
              "\"location\": " << this->location << "\n}";
}
