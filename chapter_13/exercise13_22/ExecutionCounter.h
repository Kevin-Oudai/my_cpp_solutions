#ifndef EXECUTIONCOUNTER_H
#define EXECUTIONCOUNTER_H

class ExecutionCounter
{
public:
    ExecutionCounter(const char *filename);
    int run() const;

private:
    const char *filename;

    int readCount() const;
    void writeCount(int count) const;
};

#endif
