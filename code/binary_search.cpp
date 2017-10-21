/*
binary_seach.cpp; Binary search algorithm
*/


#include <iostream>
#include <array>

template <unsigned int SIZE>
int binary_search(int item, int position, const std::array<int, SIZE> &input)
{
    const size_t arraySize = input.size();
 
    if (input[position] < item)
        return binary_search(item, (position+arraySize)/2, input);
    if (input[position] > item)
        return binary_search(item, position/2, input);
     if (input[position] == item)
        return position;
    return -1;
}

int main()
{
    const size_t SIZE = 15;
    std::array<int, SIZE> test_data = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 20, 40};
    int x = 4;

    std::cout << "Index: " << binary_search(x, 1, test_data) << '\n';

    return 0;
}