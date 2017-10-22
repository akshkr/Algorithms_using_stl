/*
bubble_sort.cpp

Bubble sort algorithm
*/

#include <iostream>
#include <vector>
#include <ctime>

#define MINMAX 1
#define MAXMIN -1

template <typename T>
void bubble_sort(std::vector<T> &_data, const char order)
{
    const size_t dataSize = _data.size();

    /* If the size of provided data is less or equal 1, we return*/
    if (dataSize <= 1)
        return;

    /**
    * On each iteration of loop, we look at each two elements and compare them each other
    * If one is bigger/lesser (depends on 'order') we swap them and set swapped flag
    * When isSwapped flag stays false at the end, we finished. Otherwise set isSwapped false again and repeat.
    */
    for (unsigned int i = 0; i < dataSize; ++i)
    {
        bool isSwapped = false;
        for (unsigned int j = 0; j < dataSize-1; ++j)
        {
            if (order * _data[j] > order * _data[j+1])
            {
                isSwapped = true;
                T temp = _data[j];
                _data[j] = _data[j+1];
                _data[j+1] = temp;
            }
        }
        if (!isSwapped)
            return;
    }
}

/**
* Operator << for printing vector on std::stream
*/
std::ostream &operator<<(std::ostream &stream, const std::vector<double> &_data)
{
    for (double i : _data)
    {
        stream << i << '\t';
    }
    return stream;
}

int main()
{
    std::vector<double> test(10);
    srand( time( NULL ) );

    for (double &i : test)
    {
        i = rand();/* Providing some test data */
    }
    std::cout << test << '\n';
    bubble_sort(test, MINMAX);
    std::cout << test << '\n';

    return 0;
}