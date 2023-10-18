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
    double mean)
{
    Hash result;
    alglib::real_1d_array a = to_real_1d_array(x);
    double bothtails, lefttail, righttail;

    alglib::studentttest1(a, x.size(), mean, bothtails, lefttail, righttail);

    result["bothtails"] = bothtails;
    result["lefttail"] = lefttail;
    result["righttail"] = righttail;
    return result;
}

Hash rb_studentttest2(
    Object self,
    Array x,
    Array y)
{
    Hash result;
    alglib::real_1d_array a = to_real_1d_array(x);
    alglib::real_1d_array b = to_real_1d_array(y);
    double bothtails, lefttail, righttail;

    alglib::studentttest2(a, x.size(), b, y.size(), bothtails, lefttail, righttail);

    result["bothtails"] = bothtails;
    result["lefttail"] = lefttail;
    result["righttail"] = righttail;
    return result;
}

extern "C" void Init_alglib()
{
    Module rb_mAlglib =
        define_module("Alglib")
            .define_module_function("studenttest1", &rb_studentttest1)
            .define_module_function("studenttest2", &rb_studentttest2);
}