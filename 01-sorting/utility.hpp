#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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

namespace sort
{
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
     * \brief generic function that generates a vector with random numbers
     * \param num size of the vector with random numbers, default value = 10
     * \param lowerBand lower band of random numbers, default value = -100
     * \param upperBand upper band of random numbers, default value = 100
     */
    template <typename T>
    std::vector<T> generateRandomVector(size_t num = 10, T lowerBand = -100, T upperBand = 100)
    {
        //---------------- Generating random numbers -------------------------
        // First create an instance of an engine.
        std::random_device rnd_device;
        // Specify the engine and distribution.
        std::mt19937 mersenne_engine(rnd_device()); // Generates random integers
        std::normal_distribution<double> dist(lowerBand, upperBand);

        std::vector<T> numbers(num);
        std::generate(numbers.begin(), numbers.end(), [&dist, &mersenne_engine]()
                      { return dist(mersenne_engine); });
        return numbers;
    }

} // namespace sort
