
#include "alglib_array_converters.h"

// Convert Ruby Array to real_1d_array
alglib::real_1d_array ruby_array_to_real_1d_array(Array ruby_array)
{
    alglib::real_1d_array real_array;
    real_array.setlength(ruby_array.size());
    std::transform(ruby_array.begin(), ruby_array.end(), real_array.getcontent(), [](const Object &o)
                   { return detail::From_Ruby<double>().convert(o.value()); });
    return real_array;
}

// Convert Ruby Array to integer_1d_array
alglib::integer_1d_array ruby_array_to_integer_1d_array(Array ruby_array)
{
    alglib::integer_1d_array integer_array;
    integer_array.setlength(ruby_array.size());
    std::transform(ruby_array.begin(), ruby_array.end(), integer_array.getcontent(), [](const Object &o)
                   { return detail::From_Ruby<int>().convert(o.value()); });
    return integer_array;
}

/*
Below functions are experimental implementations.
Do not expect this to work!
*/

// Convert Ruby 2d Array to real_2d_array
alglib::real_2d_array ruby_array_to_real_2d_array(Array ruby_array, int &rows, int &cols)
{
    alglib::real_2d_array real_array;
    rows = ruby_array.size();
    cols = detail::From_Ruby<Array>().convert(ruby_array.call("first")).size();
    // debug
    real_array.setlength(rows, cols);

    Array::iterator it = ruby_array.begin();
    Array::iterator end = ruby_array.end();

    for (int i = 0; it != end; ++it, ++i)
    {
        Array row = detail::From_Ruby<Array>().convert(it->value());
        // check if all rows have the same size
        if (row.size() != cols)
        {
            throw std::invalid_argument("All rows must have the same size");
        }

        std::transform(row.begin(), row.end(), real_array[i], [](const Object &o)
                       { return detail::From_Ruby<double>().convert(o.value()); });
    }
    return real_array;
}

// Convert real_1d_array to Ruby Array
Array real_1d_array_to_ruby_array(alglib::real_1d_array real_array)
{
    Array result;
    for (int i = 0; i < real_array.length(); i++)
    {
        result.push(real_array[i]);
    }
    return result;
}

// Convert real_2d_array to Ruby Array
Array real_2d_array_to_ruby_array(alglib::real_2d_array real_array)
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