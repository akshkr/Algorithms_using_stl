/*
binary_seach.cpp

Binary search algorithm

On each turn, we reject a half of the elements.
Algorithm assumes that search array is sorted from min to max.
*/

#include <iostream>
#include <array>

template <unsigned int SIZE>
int binary_search(int item, int position, const std::array<int, SIZE> &input)
{
    const size_t arraySize = input.size();

    /**
    * Check if item we seek is bigger than the number on current position
    * If it does, we move towards right side of an array
    */
    if (input[position] < item)
        return binary_search(item, (position + arraySize) / 2, input);
    /**
    * Check if item we seek is lesser than the number on current position
    * If it does, we move towards left side of an array
    */
    if (input[position] > item)
        return binary_search(item, position / 2, input);
    /**
    * Check if item we seek is on current position
    * If it does, we return position
    */
     if (input[position] == item)
        return position;
    // We havent found anything
    return -1;
}

int main()
{
    const size_t SIZE = 15;
    std::array<int, SIZE> test_data = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 20, 40}; // Sample data
    int x = 4; // Item we seek

    std::cout << "Index: " << binary_search(x, 1, test_data) << '\n';

    return 0;
}