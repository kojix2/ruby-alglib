#include <rice/rice.hpp>
#include <rice/stl.hpp>

using namespace Rice;

// Convert Ruby Array to real_1d_array
alglib::real_1d_array to_real_1d_array(Array rubyArray)
{
    alglib::real_1d_array a;
    a.setlength(rubyArray.size());
    std::transform(rubyArray.begin(), rubyArray.end(), a.getcontent(), [](const Object &o)
                   { return detail::From_Ruby<double>().convert(o.value()); });
    return a;
}

// Convert Ruby Array to integer_1d_array
alglib::integer_1d_array to_integer_1d_array(Array rubyArray)
{
    alglib::integer_1d_array a;
    a.setlength(rubyArray.size());
    std::transform(rubyArray.begin(), rubyArray.end(), a.getcontent(), [](const Object &o)
                   { return detail::From_Ruby<int>().convert(o.value()); });
    return a;
}

// Convert Ruby 2d Array to real_2d_array
alglib::real_2d_array to_real_2d_array(Array rubyArray, int &n, int &m)
{
    alglib::real_2d_array a;
    n = rubyArray.size();
    m = detail::From_Ruby<int>().convert((detail::From_Ruby<Array>().convert(rubyArray[0].value())).size());
    a.setlength(n, m);

    Array::iterator it = rubyArray.begin();
    Array::iterator end = rubyArray.end();

    for (int i = 0; it != end; ++it, ++i)
    {
        Array row = detail::From_Ruby<Array>().convert(it->value());
        // check if all rows have the same size
        if (detail::From_Ruby<int>().convert(row.size()) != m)
        {
            throw std::invalid_argument("All rows must have the same size");
        }

        std::transform(row.begin(), row.end(), a[i], [](const Object &o)
                       { return detail::From_Ruby<double>().convert(o.value()); });
    }
    return a;
}

// Convert real_2d_array to Ruby Array
Array to_ruby_array(alglib::real_2d_array a)
{
    Array result;
    for (int i = 0; i < a.rows(); i++)
    {
        Array row;
        for (int j = 0; j < a.cols(); j++)
        {
            row.push(a[i][j]);
        }
        result.push(row);
    }
    return result;
}