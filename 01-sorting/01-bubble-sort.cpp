#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

// Bubble sort algorithm
// Worst complexity: n^2
// Average complexity: n^2
// Best complexity: n
// Space complexity: 1
// Method: Exchanging
// Stable: Yes
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
                swap(numbers[i], numbers[i - 1]);
        }
        --size;
    }
}

// Overloading the << operator for printing vectors.
template<typename T>
std::ostream &operator << (std::ostream &out, const std::vector<T> &vec)
{
    out << "[";
    for (auto a : vec)
        out << a << ", ";
    out << "\b\b]\n";
    return out;
}

int main()
{
    //---------------- Generating random numbers -------------------------
    // First create an instance of an engine.
    std::random_device rnd_device;
    // Specify the engine and distribution.
    std::mt19937 mersenne_engine(rnd_device()); // Generates random integers
    std::normal_distribution<double> dist(-1000, 1000);

    std::vector<double> numbers(25);
    std::generate(numbers.begin(), numbers.end(), [&dist, &mersenne_engine]()
                  { return dist(mersenne_engine); });

    
    //--------------------- Running the sort algorithm -------------------
    std::cout << "before sorting:\n";
    std::cout << numbers;

    bubbleSort(numbers);

    std::cout << "after sorting:\n";
    std::cout << numbers;

    return 0;
}