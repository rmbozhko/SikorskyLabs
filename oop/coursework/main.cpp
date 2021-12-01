#include <iostream>
#include <vector>
#include <random>
#include "TextFile.h"
#include "ArchiveElement.h"
#include <chrono>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

template <typename T>
double average(T const* t, long n) {
    T s = t[0];
    for (int i = 1; i < n; i++) {
        s *= t[i];
    }
    return sqrt(s);
}

unsigned long*    getArchiveElementTextFilesSize(ArchiveElement &element) {
    unsigned long*    arr;
    
    arr = new unsigned long[NUMBER_OF_TEXT_FILES];
    for (int i = 0; i < NUMBER_OF_TEXT_FILES; i++) {
        arr[i] = element[i].getSize();
    }
    
    return arr;
}

void bubbleSortByFileName(TextFile** files, int size) {
    for (int step = 0; step < (size-1); ++step) {
        int swapped = 0;
        for (int i = 0; i < (size-step-1); ++i) {
            if (strcmp(files[i]->getName(), (files[i + 1]->getName())) > 0) {
                TextFile *temp = files[i];
                files[i] = files[i + 1];
                files[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void bubbleSortByFileLocation(TextFile** files, int size) {
    for (int step = 0; step < (size-1); ++step) {
        int swapped = 0;
        for (int i = 0; i < (size-step-1); ++i) {
            if (files[i]->getLocation().compare(files[i + 1]->getLocation()) > 0) {
                TextFile *temp = files[i];
                files[i] = files[i + 1];
                files[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main() {

    std::vector<int> sizes = {1, 2, 3, 4, 5};
    std::vector<std::string> file_names = {"temp1", "temp2", "temp3", "temp4", "temp5"};
    std::vector<std::string> extensions = {".txt", ".pdf", ".jpeg", ".xlsx", ".docx"};
    std::vector<std::vector<std::string>> keywords_ = {{"key1", "key2"}, {"1key1", "2key2"}, {"11key1", "22key2"}, {"1key", "2key"}, {"no key 1", "no key 2"}};
    std::vector<std::string> locations = {"D:\\Temp\\Test\\files\\", "D:\\Temp\\Test\\temp_files\\", "D:\\Temp\\Test\\const_files\\", "D:\\Temp\\Test\\ignored_files\\", "D:\\Temp\\Test\\corrupted_files\\"};
    std::vector<int> days = {2, 12, 20, 22, 27};
    std::vector<int> months = {2, 4, 5, 7, 11};
    std::vector<int> years = {2018, 2012, 2019, 2020, 2021};
    std::vector<std::string> person_names = {"Oleg", "Maya", "Kira", "Lita", "Mesh"};
    std::vector<std::string> person_surnames = {"Hao", "Keh", "Oly", "Myh", "Lea"};
    std::string textFileName = *select_randomly(file_names.begin(), file_names.end());
    std::string textFileExtension = *select_randomly(extensions.begin(), extensions.end());
    int day = *select_randomly(days.begin(), days.end());
    int month = *select_randomly(months.begin(), months.end());
    int year = *select_randomly(years.begin(), years.end());
    int textFileSize = *select_randomly(sizes.begin(), sizes.end());
    std::string textFileLocation = *select_randomly(locations.begin(), locations.end());
    std::string personName = *select_randomly(person_names.begin(), person_names.end());
    std::string personSurname = *select_randomly(person_surnames.begin(), person_surnames.end());
    Date fileCreationDate(day, month, year);
    Person author((char*)personName.c_str(), (char*)personSurname.c_str(), fileCreationDate);
    std::vector<std::string> keywords = reinterpret_cast<const std::vector<std::basic_string<char>> &>(*select_randomly(
            keywords_.begin(), keywords_.end()));

    ArchiveElement element((char *) textFileName.c_str(), textFileExtension, fileCreationDate, textFileSize,
                           textFileLocation,
                           author, keywords, fileCreationDate);
    for (int i = 0; i < element.getNumberOfTextFiles(); i++) {
        textFileName = *select_randomly(file_names.begin(), file_names.end());
        textFileExtension = *select_randomly(extensions.begin(), extensions.end());
        textFileSize = *select_randomly(sizes.begin(), sizes.end());
        textFileLocation = *select_randomly(locations.begin(), locations.end());
        keywords = reinterpret_cast<const std::vector<std::basic_string<char>> &>(*select_randomly(
                keywords_.begin(), keywords_.end()));

        TextFile textFile((char *) textFileName.c_str(), textFileExtension, fileCreationDate,
                                          textFileSize,textFileLocation, author, keywords);

        element[i] = textFile;
        std::cout << element[i] << std::endl;
    }
    unsigned long *archiveElementTextFilesSize = getArchiveElementTextFilesSize(element);
    std::cout << "Середнє геометричне розмірів файлів, котрі належать до масиву елементу архіву: " << average(archiveElementTextFilesSize, NUMBER_OF_TEXT_FILES) << std::endl;
    delete archiveElementTextFilesSize;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    bubbleSortByFileName(element.getTextFiles(), NUMBER_OF_TEXT_FILES);
    auto t2 = high_resolution_clock::now();
    /* Getting number of milliseconds as an integer. */
    std::chrono::duration<double, std::milli> sortingByFileNameTiming = t2 - t1;
    std::cout << "Файли відсортовано за ім\'ям." << std::endl;
    for (int i = 0; i < element.getNumberOfTextFiles(); i++) {
        std::cout << element[i] << std::endl;
    }

    t1 = high_resolution_clock::now();
    bubbleSortByFileLocation(element.getTextFiles(), NUMBER_OF_TEXT_FILES);
    t2 = high_resolution_clock::now();
    std::chrono::duration<double, std::milli> sortingByFileLocationTiming = t2 - t1;
    std::cout << "Різниця в часі виконання операції впорядкування за символьним полем: " << std::abs((sortingByFileNameTiming - sortingByFileLocationTiming).count()) << " ms\n";
    std::cout << "Файли відсортовано за розміщенням." << std::endl;
    for (int i = 0; i < element.getNumberOfTextFiles(); i++) {
        std::cout << element[i] << std::endl;
    }
    return 0;
}
