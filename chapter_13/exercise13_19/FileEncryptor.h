#ifndef FILEENCRYPTOR_H
#define FILEENCRYPTOR_H

#include <string>

class FileEncryptor
{
public:
    int run() const;

private:
    bool encryptFile(const std::string &inputFilename,
                     const std::string &outputFilename) const;
};

#endif
