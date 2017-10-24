/**
*
*/

#include <iostream>
#include <vector>
#include <ctime>

namespace merge
{
    /*
    * Merging algorithm
    */
    template <typename T>
    void merge(std::vector<T> &input, const int p, const int s, const int k)
    {
        std::vector<T> tmp(input.size(), 0);
        int i1 = p;
        int i2 = s;
        int i = p;

        while (i <= k)
        {
            if (i1 == s)
            {
                tmp[i] = input[i2];
                i2 += 1;
            }
            else
            {
                if (i2 > k)
                {
                    tmp[i] = input[i1];
                    i1 += 1;
                }
                else
                {
                    if (input[i1] > input[i2])
                    {
                        tmp[i] = input[i2];
                        i2 += 1;
                    }
                    else
                    {
                        tmp[i] = input[i1];
                        i1 += 1;
                    }
                }
            }
            i += 1;
        }

        i = p;
        while (i <= k)
        {
            input[i] = tmp[i];
            i += 1;
        }
        //return tmp;
    }
}

template <typename T>
void merge_sort(std::vector<T> &input, const int p, const int k)
{
    /*
    * We split input into two subcollection:
    * from [p] to [s - ] and
    * from [s] to [k]
    */
    const int s = (p + k + 1) / 2;

    /*
    * Now we check whether the half on subcollection
    * has more than one element. If this is true,
    * we call recursively merge_sort
    */
    if (s - p > 1)
        merge_sort(input, p, s - 1);
    if (k - s > 0)
        merge_sort(input, s, k);
    /*
    * After sorting both sides, we merge them
    */
    merge::merge(input, p, s, k);
}

/**
* Overloading operator << to print std::vector on screen
*/
template <typename T>
std::ostream &operator<<(std::ostream &stream, const std::vector<T> &input)
{
    for (T i : input)
    {
        stream << i << ' ';
    }
    return stream;
}

int main()
{
    /**
    * Testing the merge sort implementation
    */
    srand( time( NULL ) );
    std::vector<double> test;
    for (int i = 0; i < 10; ++i)
    {
        test.push_back(rand());
    }
    std::cout << test << '\n';
    merge_sort(test, 0, test.size()-1);
    std::cout << test << '\n';

    return 0;
}