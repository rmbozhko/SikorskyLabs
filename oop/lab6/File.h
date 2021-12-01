//
// Created by rbozhko on 11/10/2021.
//

#ifndef LAB5_FILE_H
#define LAB5_FILE_H
#include "Date.h"
#include <cstring>
#include <ostream>

class File {
private:
    char*           name;
    std::string     extension;
    Date            creationDate;
    unsigned long   size;
public:
    File() = default;
    File(char *name, std::string  extension, Date &creationDate, unsigned long size);

    char *getName() const;

    const std::string &getExtension() const;

    Date getCreationDate() const;

    unsigned long getSize() const;

    void setName(char *name);

    void setExtension(const std::string &extension);

    void setCreationDate(const Date &creationDate);

    void setSize(unsigned long size);

    friend std::ostream &operator<<(std::ostream &os, const File &file);

    virtual void    Show();
};


#endif //LAB5_FILE_H
