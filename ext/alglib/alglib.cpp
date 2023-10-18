// https://github.com/kojix2/ruby-alglib

#include <rice/rice.hpp>
#include <rice/stl.hpp>
// #include "numo.hpp"
#include "statistics.h"

using namespace Rice;

// convert Ruby Array to real_1d_array
alglib::real_1d_array to_real_1d_array(Array ary)
{
    alglib::real_1d_array a;
    a.setlength(ary.size());
    int count = 0;
    Array::iterator it = ary.begin();
    Array::iterator end = ary.end();
    for (; it != end; ++it)
    {
        a[count] = detail::From_Ruby<double>().convert(it->value());
        count++;
    }
    return a;
}

Hash rb_studentttest1(
    Object self,
    Array x,
    int n,
    double mean)
{
    Hash result;
    alglib::real_1d_array a = to_real_1d_array(x);
    // output parameters
    double bothtails;
    double lefttail;
    double righttail;

    alglib::studentttest1(a, n, mean, bothtails, lefttail, righttail);
    result["bothtails"] = bothtails;
    result["lefttail"] = lefttail;
    result["righttail"] = righttail;
    return result;
}

extern "C" void Init_alglib()
{
    Module rb_mAlglib =
        define_module("Alglib")
            .define_module_function("statistics_covariance", &rb_studentttest1);
}