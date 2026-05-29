#ifndef BINARYINTEGERFILE_H
#define BINARYINTEGERFILE_H

class BinaryIntegerFile
{
public:
    BinaryIntegerFile(const char *filename, int size);
    ~BinaryIntegerFile();
    int run();

private:
    const char *filename;
    int size;
    int *numbers;
    int *inputNumbers;

    void readFromKeyboard();
    void writeFile() const;
    void readFile();
    void display() const;
};

#endif
