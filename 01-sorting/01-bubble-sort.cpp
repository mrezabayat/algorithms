#include <iostream>
#include <vector>
#include "utility.hpp"

// Bubble sort algorithm
// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n
// Space complexity: 1
// Method: Exchanging
// Stable: Yes
// Class: Comparison sort

/*!
 * \brief Given a vector of numbers, this function sorts them with bubble sort algorithm
 * \param numbers vector of numbers
 */
template <typename T>
void bubbleSort(std::vector<T> &numbers)
{
    size_t size = numbers.size();
    while (size != 0)
    {
        for (size_t i{numbers.size() - 1}; i > (numbers.size() - size); --i)
        {
            if (numbers[i] < numbers[i - 1])
                sort::swap(numbers[i], numbers[i - 1]);
        }
        --size;
    }
}

int main()
{
    std::vector<int> numbers = sort::generateRandomVector<int>();

    //--------------------- Running the sort algorithm -------------------
    std::cout << "before sorting:\n";
    std::cout << numbers;

    bubbleSort(numbers);

    std::cout << "after sorting:\n";
    std::cout << numbers;

    return 0;
}