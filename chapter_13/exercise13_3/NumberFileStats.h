#ifndef NUMBERFILESTATS_H
#define NUMBERFILESTATS_H

class NumberFileStats
{
public:
    NumberFileStats(const char *filename, int size);
    ~NumberFileStats();
    int run();

private:
    const char *filename;
    int size;
    int *numbers;

    bool readNumbers();
    int getSum() const;
    int getProduct() const;
};

#endif
