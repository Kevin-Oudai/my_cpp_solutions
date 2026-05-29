#ifndef FILECOMBINER_H
#define FILECOMBINER_H

#include <string>

class FileCombiner
{
public:
    int run() const;

private:
    bool combineFiles(std::string *sourceFilenames, int numberOfFiles,
                      const std::string &targetFilename) const;
    bool copyOneFile(std::ifstream &input, std::ofstream &output) const;
};

#endif
