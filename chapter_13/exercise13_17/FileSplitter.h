#ifndef FILESPLITTER_H
#define FILESPLITTER_H

#include <string>

class FileSplitter
{
public:
    int run() const;

private:
    bool splitFile(const std::string &sourceFilename, int bytesPerFile) const;
    std::string getOutputFilename(const std::string &sourceFilename,
                                  int fileNumber) const;
};

#endif
