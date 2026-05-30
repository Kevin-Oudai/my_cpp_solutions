#ifndef DIGITPARITYCOUNTER_H
#define DIGITPARITYCOUNTER_H

class DigitParityCounter
{
public:
    DigitParityCounter();

    void evenAndOddCount(int value);
    int getEvenCount() const;
    int getOddCount() const;

private:
    int evenCount;
    int oddCount;

    void countDigits(int value);
};

#endif
