#pragma once
#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "ap.h"

using namespace Rice;

/**
 * @brief Convert a Ruby Array to an ALGLIB 1D array (e.g., real_1d_array, integer_1d_array).
 * @tparam AlglibArray ALGLIB array type (e.g., alglib::real_1d_array)
 * @tparam CType C++ element type (e.g., double, int)
 * @param ruby_array Ruby Array object
 * @return Converted ALGLIB array
 * @throw std::invalid_argument if conversion fails
 */
template <typename AlglibArray, typename CType>
AlglibArray ruby_array_to_alglib_1d_array(Array ruby_array);

/**
 * @brief Convert an ALGLIB 1D array to a Ruby Array.
 * @tparam AlglibArray ALGLIB array type (e.g., alglib::real_1d_array)
 * @param arr ALGLIB array
 * @return Ruby Array object
 */
template <typename AlglibArray>
Array alglib_1d_array_to_ruby_array(const AlglibArray &arr);

/**
 * @brief Convert a Ruby 2D Array (Array of Arrays) to an ALGLIB 2D array (e.g., real_2d_array).
 * @tparam Alglib2DArray ALGLIB 2D array type (e.g., alglib::real_2d_array)
 * @tparam CType C++ element type (e.g., double)
 * @param ruby_array Ruby Array of Arrays
 * @return Converted ALGLIB 2D array
 * @throw std::invalid_argument if conversion fails
 */
template <typename Alglib2DArray, typename CType>
Alglib2DArray ruby_array_to_alglib_2d_array(Array ruby_array);

/**
 * @brief Convert an ALGLIB 2D array to a Ruby 2D Array (Array of Arrays).
 * @tparam Alglib2DArray ALGLIB 2D array type (e.g., alglib::real_2d_array)
 * @param arr ALGLIB 2D array
 * @return Ruby Array of Arrays
 */
template <typename Alglib2DArray>
Array alglib_2d_array_to_ruby_array(const Alglib2DArray &arr);

// Existing function declarations for backward compatibility
alglib::real_1d_array ruby_array_to_real_1d_array(Array ruby_array);
alglib::integer_1d_array ruby_array_to_integer_1d_array(Array ruby_array);
alglib::real_2d_array ruby_array_to_real_2d_array(Array ruby_array);
Array real_1d_array_to_ruby_array(const alglib::real_1d_array &arr);
Array real_2d_array_to_ruby_array(const alglib::real_2d_array &real_array);
Array integer_1d_array_to_ruby_array(const alglib::integer_1d_array &arr);
