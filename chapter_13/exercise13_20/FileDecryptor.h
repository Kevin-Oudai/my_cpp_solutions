#ifndef FILEDECRYPTOR_H
#define FILEDECRYPTOR_H

#include <string>

class FileDecryptor
{
public:
    int run() const;

private:
    bool decryptFile(const std::string &inputFilename,
                     const std::string &outputFilename) const;
};

#endif
