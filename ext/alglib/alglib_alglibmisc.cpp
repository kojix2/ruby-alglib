#include "alglib_alglibmisc.h"

double rb_hqrndnormal()
{
    alglib::hqrndstate state;
    alglib::hqrndrandomize(state);
    return alglib::hqrndnormal(state);
}

Array rb_hqrndnormalv(alglib::ae_int_t n)
{
    Array result = Array(rb_ary_new2(n));
    alglib::hqrndstate state;
    alglib::hqrndrandomize(state);
    alglib::real_1d_array x;
    alglib::hqrndnormalv(state, n, x);
    for (alglib::ae_int_t i = 0; i < n; i++)
    {
        result.push(x[i]);
    }
    return result;
}