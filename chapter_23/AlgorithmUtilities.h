#ifndef ALGORITHMUTILITIES_H
#define ALGORITHMUTILITIES_H

#include <iostream>

namespace exercise23
{
    template<typename Iterator>
    void printRange(Iterator beg, Iterator end)
    {
        for (Iterator iterator = beg; iterator != end; iterator++)
            std::cout << *iterator << " ";
        std::cout << std::endl;
    }

    template<typename Container>
    void printContainer(const Container& container)
    {
        printRange(container.begin(), container.end());
    }

    template<typename ForwardIterator, typename T>
    void fill(ForwardIterator beg, ForwardIterator end, const T& value)
    {
        for (ForwardIterator iterator = beg; iterator != end; iterator++)
            *iterator = value;
    }

    template<typename ForwardIterator, typename Size, typename T>
    void fill_n(ForwardIterator beg, Size n, const T& value)
    {
        for (Size i = 0; i < n; i++)
        {
            *beg = value;
            beg++;
        }
    }

    template<typename ForwardIterator, typename Function>
    void generate(ForwardIterator beg, ForwardIterator end, Function gen)
    {
        for (ForwardIterator iterator = beg; iterator != end; iterator++)
            *iterator = gen();
    }

    template<typename ForwardIterator, typename Size, typename Function>
    void generate_n(ForwardIterator beg, Size n, Function gen)
    {
        for (Size i = 0; i < n; i++)
        {
            *beg = gen();
            beg++;
        }
    }

    template<typename BidirectionalIterator>
    void reverse(BidirectionalIterator beg, BidirectionalIterator end)
    {
        if (beg == end)
            return;

        end--;
        while (true)
        {
            if (beg == end)
                break;

            typename std::iterator_traits<BidirectionalIterator>::value_type temp = *beg;
            *beg = *end;
            *end = temp;
            beg++;

            if (beg == end)
                break;

            end--;
        }
    }

    template<typename BidirectionalIterator, typename OutputIterator>
    OutputIterator reverse_copy(BidirectionalIterator beg, BidirectionalIterator end, OutputIterator targetPosition)
    {
        while (beg != end)
        {
            end--;
            *targetPosition = *end;
            targetPosition++;
        }

        return targetPosition;
    }

    template<typename ForwardIterator, typename T>
    void replace(ForwardIterator beg, ForwardIterator end, const T& oldValue, const T& newValue)
    {
        for (ForwardIterator iterator = beg; iterator != end; iterator++)
        {
            if (*iterator == oldValue)
                *iterator = newValue;
        }
    }

    template<typename ForwardIterator, typename BoolFunction, typename T>
    void replace_if(ForwardIterator beg, ForwardIterator end, BoolFunction f, const T& newValue)
    {
        for (ForwardIterator iterator = beg; iterator != end; iterator++)
        {
            if (f(*iterator))
                *iterator = newValue;
        }
    }

    template<typename InputIterator, typename T>
    InputIterator find(InputIterator beg, InputIterator end, const T& value)
    {
        for (InputIterator iterator = beg; iterator != end; iterator++)
        {
            if (*iterator == value)
                return iterator;
        }

        return end;
    }

    template<typename InputIterator, typename BoolFunction>
    InputIterator find_if(InputIterator beg, InputIterator end, BoolFunction f)
    {
        for (InputIterator iterator = beg; iterator != end; iterator++)
        {
            if (f(*iterator))
                return iterator;
        }

        return end;
    }
}

#endif
