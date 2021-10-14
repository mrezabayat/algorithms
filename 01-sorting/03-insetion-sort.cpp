#include <iostream>
#include <vector>
#include "utility.hpp"

template<typename T>
void insertionSort(std::vector<T> &numbers)
{
    for (size_t i{1}; i < numbers.size(); ++i)
    {
        for (size_t j{}; j < i; ++j)
        {
            if (numbers[i] < numbers[j])
            {
                sort::swap(numbers[i], numbers[j]);
            }
        }
    }
}

int main()
{
    std::vector<int> numbers = sort::generateRandomVector<int>();

    //--------------------- Running the sort algorithm -------------------
    std::cout << "before sorting:\n";
    std::cout << numbers;

    insertionSort(numbers);

    std::cout << "after sorting:\n";
    std::cout << numbers;

    return 0;
}