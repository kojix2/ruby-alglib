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
    if (ruby_array.size() == 0)
    {
        throw std::invalid_argument("Input array is empty");
    }

    int rows = ruby_array.size();
    int cols = detail::From_Ruby<Array>().convert(ruby_array.call("first")).size();

    alglib::real_2d_array real_array;
    real_array.setlength(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        Array row = detail::From_Ruby<Array>().convert(ruby_array[i].value());
        if (row.size() != cols)
        {
            throw std::invalid_argument("All rows must have the same size");
        }
        for (int j = 0; j < cols; ++j)
        {
            real_array[i][j] = detail::From_Ruby<double>().convert(row[j].value());
        }
    }
    return real_array;
}

Array real_2d_array_to_ruby_array(const alglib::real_2d_array &real_array)
{
    Array result;
    for (int i = 0; i < real_array.rows(); i++)
    {
        Array row;
        for (int j = 0; j < real_array.cols(); j++)
        {
            row.push(real_array[i][j]);
        }
        result.push(row);
    }
    return result;
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
        result[i] = Rice::detail::From_Ruby<CType>().convert(ruby_array[i].value());
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

// Explicit instantiations for real_1d_array and integer_1d_array
template alglib::real_1d_array ruby_array_to_alglib_1d_array<alglib::real_1d_array, double>(Array);
template alglib::integer_1d_array ruby_array_to_alglib_1d_array<alglib::integer_1d_array, int>(Array);
template Array alglib_1d_array_to_ruby_array<alglib::real_1d_array>(const alglib::real_1d_array &);
template Array alglib_1d_array_to_ruby_array<alglib::integer_1d_array>(const alglib::integer_1d_array &);
