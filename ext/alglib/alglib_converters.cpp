#include "alglib_converters.h"

alglib::real_1d_array ruby_array_to_real_1d_array(Array ruby_array)
{
    // Call the template function for real_1d_array and double
    return ruby_array_to_alglib_1d_array<alglib::real_1d_array, double>(ruby_array);
}

alglib::integer_1d_array ruby_array_to_integer_1d_array(Array ruby_array)
{
    // Call the template function for integer_1d_array and int
    return ruby_array_to_alglib_1d_array<alglib::integer_1d_array, int>(ruby_array);
}

Array real_1d_array_to_ruby_array(const alglib::real_1d_array &arr)
{
    // Call the template function for real_1d_array
    return alglib_1d_array_to_ruby_array<alglib::real_1d_array>(arr);
}

Array integer_1d_array_to_ruby_array(const alglib::integer_1d_array &arr)
{
    // Call the template function for integer_1d_array
    return alglib_1d_array_to_ruby_array<alglib::integer_1d_array>(arr);
}

alglib::real_2d_array ruby_array_to_real_2d_array(Array ruby_array)
{
    // Call the template function for real_2d_array and double
    return ruby_array_to_alglib_2d_array<alglib::real_2d_array, double>(ruby_array);
}

Array real_2d_array_to_ruby_array(const alglib::real_2d_array &real_array)
{
    // Call the template function for real_2d_array
    return alglib_2d_array_to_ruby_array<alglib::real_2d_array>(real_array);
}

/**
 * @brief Template implementation: Convert a Ruby Array to an ALGLIB 1D array.
 */
template <typename AlglibArray, typename CType>
AlglibArray ruby_array_to_alglib_1d_array(Array ruby_array)
{
    AlglibArray result;
    result.setlength(ruby_array.size());
    for (size_t i = 0; i < ruby_array.size(); ++i)
    {
        try
        {
            result[i] = Rice::detail::From_Ruby<CType>().convert(ruby_array[i].value());
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument(
                "ruby_array_to_alglib_1d_array: Element " + std::to_string(i) +
                " conversion failed: " + e.what());
        }
    }
    return result;
}

/**
 * @brief Template implementation: Convert an ALGLIB 1D array to a Ruby Array.
 */
template <typename AlglibArray>
Array alglib_1d_array_to_ruby_array(const AlglibArray &arr)
{
    Array ruby_array;
    for (int i = 0; i < arr.length(); ++i)
    {
        ruby_array.push(arr[i]);
    }
    return ruby_array;
}

/**
 * @brief Template implementation: Convert a Ruby 2D Array (Array of Arrays) to an ALGLIB 2D array.
 */
template <typename Alglib2DArray, typename CType>
Alglib2DArray ruby_array_to_alglib_2d_array(Array ruby_array)
{
    if (ruby_array.size() == 0)
    {
        throw std::invalid_argument("ruby_array_to_alglib_2d_array: Input array is empty");
    }
    int rows = ruby_array.size();
    Array first_row;
    try
    {
        first_row = Rice::detail::From_Ruby<Array>().convert(ruby_array.call("first"));
    }
    catch (const std::exception &e)
    {
        throw std::invalid_argument("ruby_array_to_alglib_2d_array: First row is not an Array: " + std::string(e.what()));
    }
    int cols = first_row.size();

    Alglib2DArray result;
    result.setlength(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        Array row;
        try
        {
            row = Rice::detail::From_Ruby<Array>().convert(ruby_array[i].value());
        }
        catch (const std::exception &e)
        {
            throw std::invalid_argument(
                "ruby_array_to_alglib_2d_array: Row " + std::to_string(i) +
                " is not an Array: " + e.what());
        }
        if (row.size() != cols)
        {
            throw std::invalid_argument(
                "ruby_array_to_alglib_2d_array: Row " + std::to_string(i) +
                " size mismatch: expected " + std::to_string(cols) +
                ", got " + std::to_string(row.size()));
        }
        for (int j = 0; j < cols; ++j)
        {
            try
            {
                result[i][j] = Rice::detail::From_Ruby<CType>().convert(row[j].value());
            }
            catch (const std::exception &e)
            {
                throw std::invalid_argument(
                    "ruby_array_to_alglib_2d_array: Element (" +
                    std::to_string(i) + "," + std::to_string(j) +
                    ") conversion failed: " + e.what());
            }
        }
    }
    return result;
}

/**
 * @brief Template implementation: Convert an ALGLIB 2D array to a Ruby 2D Array (Array of Arrays).
 */
template <typename Alglib2DArray>
Array alglib_2d_array_to_ruby_array(const Alglib2DArray &arr)
{
    Array result;
    for (int i = 0; i < arr.rows(); i++)
    {
        Array row;
        for (int j = 0; j < arr.cols(); j++)
        {
            row.push(arr[i][j]);
        }
        result.push(row);
    }
    return result;
}

/**
 * @brief Explicit template instantiations for 1D/2D real/integer ALGLIB arrays.
 * This ensures symmetric conversion support for both real and integer types.
 */

// 1D real
template alglib::real_1d_array ruby_array_to_alglib_1d_array<alglib::real_1d_array, double>(Array);
template Array alglib_1d_array_to_ruby_array<alglib::real_1d_array>(const alglib::real_1d_array &);

// 1D integer
template alglib::integer_1d_array ruby_array_to_alglib_1d_array<alglib::integer_1d_array, int>(Array);
template Array alglib_1d_array_to_ruby_array<alglib::integer_1d_array>(const alglib::integer_1d_array &);

// 2D real
template alglib::real_2d_array ruby_array_to_alglib_2d_array<alglib::real_2d_array, double>(Array);
template Array alglib_2d_array_to_ruby_array<alglib::real_2d_array>(const alglib::real_2d_array &);

// 2D integer
template alglib::integer_2d_array ruby_array_to_alglib_2d_array<alglib::integer_2d_array, int>(Array);
template Array alglib_2d_array_to_ruby_array<alglib::integer_2d_array>(const alglib::integer_2d_array &);
