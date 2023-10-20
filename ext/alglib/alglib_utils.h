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
    Array::iterator it = rubyArray.begin();
    Array::iterator end = rubyArray.end();
    for(int i = 0; it != end; ++it, ++i)
    {
        a[i] = detail::From_Ruby<int>().convert(it->value());
    }
    return a;
}
