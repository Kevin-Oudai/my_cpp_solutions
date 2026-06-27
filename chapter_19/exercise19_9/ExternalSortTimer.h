#ifndef EXTERNALSORTTIMER_H
#define EXTERNALSORTTIMER_H

#include <fstream>
#include <string>

class ExternalSortTimer
{
public:
    void run() const;
    void displayTable(bool useExerciseSizes) const;

private:
    void createDataFile(const std::string &fileName, int size) const;
    void sortFile(const std::string &sourceFile, const std::string &targetFile, int segmentSize) const;
    int initializeSegments(int segmentSize, const std::string &sourceFile, const std::string &f1) const;
    void merge(int numberOfSegments, int segmentSize, const std::string &f1,
        const std::string &f2, const std::string &f3, const std::string &targetFile) const;
    void mergeOneStep(int numberOfSegments, int segmentSize, const std::string &f1,
        const std::string &f2, const std::string &f3) const;
    void copyHalfToF2(int numberOfSegments, int segmentSize, std::ifstream &f1,
        std::ofstream &f2) const;
    void mergeSegments(int numberOfSegments, int segmentSize, std::ifstream &f1,
        std::ifstream &f2, std::ofstream &f3) const;
    void mergeTwoSegments(int segmentSize, std::ifstream &f1, std::ifstream &f2,
        std::ofstream &f3) const;
    void copyRemaining(std::ifstream &input, std::ofstream &output) const;
    void copyFile(const std::string &sourceFile, const std::string &targetFile) const;
    bool readInt(std::ifstream &input, int &value) const;
    void quickSort(int list[], int arraySize) const;
    long timeExternalSort(int size) const;
    bool isSortedFile(const std::string &fileName) const;
};

#endif
