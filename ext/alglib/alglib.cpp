#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <algorithm>
// #include "numo.hpp"
#include "statistics.h"

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

Hash rb_samplemoments(Array x)
{
    Hash result;
    auto a = to_real_1d_array(x);
    double mean, variance, skewness, kurtosis;

    alglib::samplemoments(a, x.size(), mean, variance, skewness, kurtosis, alglib::xdefault);
    
    result["mean"] = mean;
    result["variance"] = variance;
    result["skewness"] = skewness;
    result["kurtosis"] = kurtosis;
    
    return result;
}

double rb_samplemean(Array x)
{
    auto a = to_real_1d_array(x);
    return alglib::samplemean(a, x.size(), alglib::xdefault);
}

// double samplevariance(const real_1d_array &x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_samplevariance(Array x)
{
    auto a = to_real_1d_array(x);
    return alglib::samplevariance(a, x.size(), alglib::xdefault);
}

// Helper function to generic statistical tests
template <typename Func, typename... Args>
Hash perform_test(Func test, Args... args)
{
    Hash result;
    double bothtails, lefttail, righttail;
    test(args..., bothtails, lefttail, righttail, alglib::xdefault);
    result["bothtails"] = bothtails;
    result["lefttail"] = lefttail;
    result["righttail"] = righttail;
    return result;
}

Hash rb_pearsoncorrelationsignificance(double r, int n)
{
    return perform_test(alglib::pearsoncorrelationsignificance, r, n);
}

Hash rb_spearmanrankcorrelationsignificance(double r, int n)
{
    return perform_test(alglib::spearmanrankcorrelationsignificance, r, n);
}

Hash rb_jarqueberatest(Array x)
{
    Hash result;
    auto a = to_real_1d_array(x);
    double p;
    alglib::jarqueberatest(a, x.size(), p);
    result["p"] = p;
    return result;
}

Hash rb_ftest(Array x, Array y)
{
    auto a = to_real_1d_array(x);
    auto b = to_real_1d_array(y);
    return perform_test(alglib::ftest, a, x.size(), b, y.size());
}

Hash rb_onesamplevariancetest(Array x, double variance)
{
    auto a = to_real_1d_array(x);
    return perform_test(alglib::onesamplevariancetest, a, x.size(), variance);
}

Hash rb_wilcoxonsignedranktest(Array x, double e)
{
    auto a = to_real_1d_array(x);
    return perform_test(alglib::wilcoxonsignedranktest, a, x.size(), e);
}

Hash rb_mannwhitneyutest(Array x, Array y)
{
    auto a = to_real_1d_array(x);
    auto b = to_real_1d_array(y);
    return perform_test(alglib::mannwhitneyutest, a, x.size(), b, y.size());
}

Hash rb_studentttest1(Array x, double mean)
{
    auto a = to_real_1d_array(x);
    return perform_test(alglib::studentttest1, a, x.size(), mean);
}

Hash rb_studentttest2(Array x, Array y)
{
    auto a = to_real_1d_array(x);
    auto b = to_real_1d_array(y);
    return perform_test(alglib::studentttest2, a, x.size(), b, y.size());
}

Hash rb_unequalvariancettest(Array x, Array y)
{
    auto a = to_real_1d_array(x);
    auto b = to_real_1d_array(y);
    return perform_test(alglib::unequalvariancettest, a, x.size(), b, y.size());
}

extern "C" void Init_alglib()
{
define_module("Alglib")
    .define_module_function("sample_moments", &rb_samplemoments)
    .define_module_function("sample_mean", &rb_samplemean)
    .define_module_function("sample_variance", &rb_samplevariance)
    .define_module_function("pearson_correlation_significance", &rb_pearsoncorrelationsignificance)
    .define_module_function("spearman_rank_correlation_significance", &rb_spearmanrankcorrelationsignificance)
    .define_module_function("jarque_bera_test", &rb_jarqueberatest)
    .define_module_function("f_test", &rb_ftest)
    .define_module_function("one_sample_variance_test", &rb_onesamplevariancetest)
    .define_module_function("wilcoxon_signed_rank_test", &rb_wilcoxonsignedranktest)
    .define_module_function("mann_whitney_u_test", &rb_mannwhitneyutest)
    .define_module_function("student_test_1", &rb_studentttest1)
    .define_module_function("student_test_2", &rb_studentttest2)
    .define_module_function("unequal_variance_t_test", &rb_unequalvariancettest);
}