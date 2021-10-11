#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>

// Selection sort algorithm
// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n^2
// Space complexity: 1
// Method: Selection
// Stable: No
// Class: Comparison sort

/*!
 * \brief This general function swaps two varables
 * \param a first variable
 * \param a second variable
 */
template <typename T>
void swap(T &a, T &b)
{
    T temp{a};
    a = b;
    b = temp;
}

// Overloading the << operator for printing vectors.
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    out << "[";
    for (auto a : vec)
        out << a << ", ";
    out << "\b\b]\n";
    return out;
}


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
            swap(*minIndex, *(numbers.begin() + numbers.size() - sizeOfNumbers));
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
    //------------------ Generating random numbers ---------------------
    std::random_device rndDevice;
    std::mt19937 engine(rndDevice());
    std::uniform_int_distribution<int> dist(-10, 10);

    std::vector<int> rndNumbers(6);
    std::generate(rndNumbers.begin(), rndNumbers.end(), [&dist, &engine]()
                  { return dist(engine); });
    //-------------------------------------------------------------------

    //------------------ Selection sort algorithm -----------------------
    std::cout << "before sorting:\n";
    std::cout << rndNumbers;

    selectionSort(rndNumbers);

    std::cout << "after sorting:\n";
    std::cout << rndNumbers;
    //-------------------------------------------------------------------
    return 0;
}