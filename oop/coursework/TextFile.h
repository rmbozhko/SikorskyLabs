//
// Created by rbozhko on 11/10/2021.
//

#ifndef LAB5_TEXTFILE_H
#define LAB5_TEXTFILE_H

#include <vector>
#include <ostream>
#include "File.h"
#include "Person.h"

class TextFile : public File {
private:
    std::string                 location;
    Person                      author;
    std::vector<std::string>    keywords;
public:
    TextFile() = default;

    TextFile(char *name, const std::string &extension, Date &creationDate, unsigned long size,
             std::string location, Person &author, std::vector<std::string> keywords);

    const std::string &getLocation() const;

    Person getAuthor() const;

    const std::vector<std::string> &getKeywords() const;
    TextFile& operator=(const TextFile& rhs);

    friend std::ostream &operator<<(std::ostream &os, const TextFile &file);

    void Show();
};


#endif //LAB5_TEXTFILE_H
