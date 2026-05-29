#ifndef BINARYFILECOPIER_H
#define BINARYFILECOPIER_H

#include <string>

class BinaryFileCopier
{
public:
    BinaryFileCopier(int bufferSize);
    ~BinaryFileCopier();
    int run();

private:
    int bufferSize;
    char *buffer;

    bool copyFile(const std::string &sourceFilename,
                  const std::string &targetFilename);
};

#endif
