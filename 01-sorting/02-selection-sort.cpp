#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>
#include "utility.hpp"

// Selection sort algorithm
// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n^2
// Space complexity: 1
// Method: Selection
// Stable: No
// Class: Comparison sort

template <typename iterator>
iterator minIterator(const iterator start, const iterator end)
{
    if (start == end)
        throw("Vector is empty.");

    iterator min{start};
    for (iterator i{start + 1}; i != end; ++i)
        if (*i < *min)
            min = i;

    return min;
}

template <typename T>
void selectionSort(std::vector<T> &numbers)
{
    if (numbers.empty())
        throw("Vector of numbers are empty.");

    size_t sizeOfNumbers{numbers.size()};
    while (sizeOfNumbers > 0)
    {
        // find the index of minimum
        try
        {
            /*
            // using the std functions
            auto minIndex = std::min_element(numbers.begin() + numbers.size() - sizeOfNumbers, numbers.end());
            std::iter_swap(minIndex, numbers.begin() + numbers.size() - sizeOfNumbers);
            */
           
            // doing it manually
            auto minIndex = minIterator(numbers.begin() + numbers.size() - sizeOfNumbers, numbers.end());
            sort::swap(*minIndex, *(numbers.begin() + numbers.size() - sizeOfNumbers));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        --sizeOfNumbers;
    }
}

int main()
{
    std::vector<int> numbers = sort::generateRandomVector<int>();

    //------------------ Selection sort algorithm -----------------------
    std::cout << "before sorting:\n";
    std::cout << numbers;

    selectionSort(numbers);

    std::cout << "after sorting:\n";
    std::cout << numbers;
    //-------------------------------------------------------------------
    return 0;
}