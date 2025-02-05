#include "alglib_dataanalysis.h"

// void pcabuildbasis(const real_2d_array &x, real_1d_array &s2, real_2d_array &v, const xparams _xparams = alglib::xdefault);
Hash rb_pcabuildbasis(Array x)
{
    Hash result;
    auto a = ruby_array_to_real_2d_array(x);
    alglib::real_1d_array s2;
    alglib::real_2d_array v;
    alglib::pcabuildbasis(a, s2, v, alglib::xdefault);
    result["s2"] = real_1d_array_to_ruby_array(s2);
    result["v"] = real_2d_array_to_ruby_array(v);
    return result;
}