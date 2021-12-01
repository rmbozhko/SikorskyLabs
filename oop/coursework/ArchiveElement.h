//
// Created by rbozhko on 11/10/2021.
//

#ifndef LAB5_ARCHIVEELEMENT_H
#define LAB5_ARCHIVEELEMENT_H
#include "TextFile.h"
#include "Date.h"
const static int NUMBER_OF_TEXT_FILES = 5;

class ArchiveElement : public TextFile {
private:
    TextFile    **textFiles;
    Date        archiveElementCreationDate;
    int         numberOfTextFiles;
public:
    ArchiveElement(char *name, const std::string &extension, Date &creationDate, unsigned long size,
                   const std::string &location, Person &author, const std::vector<std::string> &keywords, const Date &archiveElementCreationDate);

    int getNumberOfTextFiles() const;

    TextFile **getTextFiles() const;

    TextFile& operator[](int index);

    void Show();
};


#endif //LAB5_ARCHIVEELEMENT_H
