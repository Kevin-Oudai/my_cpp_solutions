#ifndef REVERSENUMBERFILESORTER_H
#define REVERSENUMBERFILESORTER_H

class ReverseNumberFileSorter
{
public:
    ReverseNumberFileSorter(const char *filename, int size);
    ~ReverseNumberFileSorter();
    int run();

private:
    const char *filename;
    int size;
    int *numbers;

    bool readNumbers();
    void sortDescending();
    void writeNumbers() const;
};

#endif
