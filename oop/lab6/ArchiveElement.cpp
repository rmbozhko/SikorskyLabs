//
// Created by rbozhko on 11/10/2021.
//

#include  <random>
#include  <iterator>
#include <iostream>
#include "ArchiveElement.h"

TextFile& ArchiveElement::operator[](int index) {
    if (index < 0 || index > NUMBER_OF_TEXT_FILES) {
        throw std::invalid_argument("Invalid index");
    }
    return *this->textFiles[index];//*(*(this->textFiles) + index);
}

ArchiveElement::ArchiveElement(char *name, const std::string &extension, Date &creationDate, unsigned long size,
                               const std::string &location, Person &author, const std::vector<std::string> &keywords, const Date &archiveElementCreationDate) : TextFile(name,
                                                                                                         extension,
                                                                                                         creationDate,
                                                                                                         size, location,
                                                                                                         author,
                                                                                                         keywords),
                                                                                                             archiveElementCreationDate(archiveElementCreationDate) {
 this->numberOfTextFiles = NUMBER_OF_TEXT_FILES;
 this->textFiles = new TextFile*[numberOfTextFiles];
    for (int i = 0; i < NUMBER_OF_TEXT_FILES; ++i) {
        this->textFiles[i] = new TextFile();
    }
}

int ArchiveElement::getNumberOfTextFiles() const {
    return numberOfTextFiles;
}

TextFile **ArchiveElement::getTextFiles() const {
    return textFiles;
}

void ArchiveElement::Show() {
    std::cout << "ArchiveElement ";
    std::cout << "{\n\t\"name\": " << "\"" << this->getName() << "\",\n\t" <<
              "\"extension\": " << "\"" <<  this->getExtension() << "\",\n\t" <<
              "\"creationDate\": " << this->getCreationDate().getDay() << "/" << this->getCreationDate().getMonth() << "/" << this->getCreationDate().getYear() << "\n\t" <<
              "\"size\": " << this->getSize() << "\",\n\t" <<
              "\"author\": " << this->getAuthor().getName() << " " << this->getAuthor().getSurname() << "\",\n\t" <<
              "\"location\": " << this->getLocation() << "\",\n\t" <<
              "\"archiveElementCreationDate\": " << this->archiveElementCreationDate.getDay() << "/" << this->archiveElementCreationDate.getMonth() << "/" << this->archiveElementCreationDate.getYear() << ",\n\t" <<
              "\"numberOfTextFiles\": " << this->numberOfTextFiles <<
              "\n}" << std::endl;
}
