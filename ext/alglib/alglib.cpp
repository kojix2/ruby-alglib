#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <algorithm>
// #include "numo.hpp"
#include "statistics.h"
#include "alg_array_converters.hpp"

using namespace Rice;

// Check if two arrays are the same size
void check_size(Array x, Array y)
{
    if (x.size() != y.size())
    {
        throw std::invalid_argument("x and y must be the same size");
    }
}

// void samplemoments(const real_1d_array &x, const ae_int_t n, double &mean, double &variance, double &skewness, double &kurtosis, const xparams _xparams = alglib::xdefault);
Hash rb_samplemoments(Array x)
{
    Hash result;
    auto a = ruby_array_to_real_1d_array(x);
    double mean, variance, skewness, kurtosis;

    alglib::samplemoments(a, x.size(), mean, variance, skewness, kurtosis, alglib::xdefault);

    result["mean"] = mean;
    result["variance"] = variance;
    result["skewness"] = skewness;
    result["kurtosis"] = kurtosis;

    return result;
}

// double samplemean(const real_1d_array &x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_samplemean(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplemean(a, x.size());
}

// double samplevariance(const real_1d_array &x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_samplevariance(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplevariance(a, x.size());
}

// double sampleskewness(const real_1d_array &x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_sampleskewness(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::sampleskewness(a, x.size());
}

// double samplekurtosis(const real_1d_array &x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_samplekurtosis(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplekurtosis(a, x.size());
}

// void sampleadev(const real_1d_array &x, const ae_int_t n, double &adev, const xparams _xparams = alglib::xdefault);
double rb_sampleadev(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    double adev;
    alglib::sampleadev(a, x.size(), adev);
    return adev;
}

// void samplemedian(const real_1d_array &x, const ae_int_t n, double &median, const xparams _xparams = alglib::xdefault);
double rb_samplemedian(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    double median;
    alglib::samplemedian(a, x.size(), median);
    return median;
}

// void samplepercentile(const real_1d_array &x, const ae_int_t n, const double p, double &v, const xparams _xparams = alglib::xdefault);
double rb_samplepercentile(Array x, double p)
{
    auto a = ruby_array_to_real_1d_array(x);
    double v;
    alglib::samplepercentile(a, x.size(), p, v);
    return v;
}

// double cov2(const real_1d_array &x, const real_1d_array &y, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_cov2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::cov2(a, b, x.size());
}

// double pearsoncorr2(const real_1d_array &x, const real_1d_array &y, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_pearsoncorr2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::pearsoncorr2(a, b, x.size());
}

// double spearmancorr2(const real_1d_array &x, const real_1d_array &y, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_spearmancorr2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::spearmancorr2(a, b, x.size());
}

// void covm(const real_2d_array &x, const ae_int_t n, const ae_int_t m, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void pearsoncorrm(const real_2d_array &x, const ae_int_t n, const ae_int_t m, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void spearmancorrm(const real_2d_array &x, const ae_int_t n, const ae_int_t m, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void covm2(const real_2d_array &x, const real_2d_array &y, const ae_int_t n, const ae_int_t m1, const ae_int_t m2, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void pearsoncorrm2(const real_2d_array &x, const real_2d_array &y, const ae_int_t n, const ae_int_t m1, const ae_int_t m2, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void spearmancorrm2(const real_2d_array &x, const real_2d_array &y, const ae_int_t n, const ae_int_t m1, const ae_int_t m2, real_2d_array &c, const xparams _xparams = alglib::xdefault);

// void rankdata(real_2d_array &xy, const ae_int_t npoints, const ae_int_t nfeatures, const xparams _xparams = alglib::xdefault);

// void rankdatacentered(real_2d_array &xy, const ae_int_t npoints, const ae_int_t nfeatures, const xparams _xparams = alglib::xdefault);

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

// void pearsoncorrelationsignificance(const double r, const ae_int_t n, double &bothtails, double &lefttail, double &righttail, const xparams _xparams = alglib::xdefault);
Hash rb_pearsoncorrelationsignificance(double r, alglib::ae_int_t n)
{
    return perform_test(alglib::pearsoncorrelationsignificance, r, n);
}

// void spearmanrankcorrelationsignificance(const double r, const ae_int_t n, double &bothtails, double &lefttail, double &righttail, const xparams _xparams = alglib::xdefault);
Hash rb_spearmanrankcorrelationsignificance(double r, alglib::ae_int_t n)
{
    return perform_test(alglib::spearmanrankcorrelationsignificance, r, n);
}

Hash rb_jarqueberatest(Array x)
{
    Hash result;
    auto a = ruby_array_to_real_1d_array(x);
    double p;
    alglib::jarqueberatest(a, x.size(), p);
    result["p"] = p;
    return result;
}

Hash rb_ftest(Array x, Array y)
{
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return perform_test(alglib::ftest, a, x.size(), b, y.size());
}

Hash rb_onesamplevariancetest(Array x, double variance)
{
    auto a = ruby_array_to_real_1d_array(x);
    return perform_test(alglib::onesamplevariancetest, a, x.size(), variance);
}

Hash rb_wilcoxonsignedranktest(Array x, double e)
{
    auto a = ruby_array_to_real_1d_array(x);
    return perform_test(alglib::wilcoxonsignedranktest, a, x.size(), e);
}

Hash rb_mannwhitneyutest(Array x, Array y)
{
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return perform_test(alglib::mannwhitneyutest, a, x.size(), b, y.size());
}

Hash rb_studentttest1(Array x, double mean)
{
    auto a = ruby_array_to_real_1d_array(x);
    return perform_test(alglib::studentttest1, a, x.size(), mean);
}

Hash rb_studentttest2(Array x, Array y)
{
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return perform_test(alglib::studentttest2, a, x.size(), b, y.size());
}

Hash rb_unequalvariancettest(Array x, Array y)
{
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return perform_test(alglib::unequalvariancettest, a, x.size(), b, y.size());
}

// specialfunctions.h

// double gammafunction(const double x, const xparams _xparams = alglib::xdefault);
double rb_gammafunction(double x)
{
    return alglib::gammafunction(x);
}

// double lngamma(const double x, double &sgngam, const xparams _xparams = alglib::xdefault);
Array rb_lngamma(double x)
{
    Array result = Array(rb_ary_new2(2));
    double sgngam;
    result.push(alglib::lngamma(x, sgngam));
    result.push(sgngam);
    return result;
}

// double errorfunction(const double x, const xparams _xparams = alglib::xdefault);
double rb_errorfunction(double x)
{
    return alglib::errorfunction(x);
}

// double errorfunctionc(const double x, const xparams _xparams = alglib::xdefault);
double rb_errorfunctionc(double x)
{
    return alglib::errorfunctionc(x);
}

// double normalpdf(const double x, const xparams _xparams = alglib::xdefault);
double rb_normalpdf(double x)
{
    return alglib::normalpdf(x);
}

// double normalcdf(const double x, const xparams _xparams = alglib::xdefault);
double rb_normalcdf(double x)
{
    return alglib::normalcdf(x);
}

// double inverf(const double e, const xparams _xparams = alglib::xdefault);
double rb_inverf(double e)
{
    return alglib::inverf(e);
}

// double invnormalcdf(const double y0, const xparams _xparams = alglib::xdefault);
double rb_invnormalcdf(double y0)
{
    return alglib::invnormalcdf(y0);
}

// double bivariatenormalpdf(const double x, const double y, const double rho, const xparams _xparams = alglib::xdefault);
double rb_bivariatenormalpdf(double x, double y, double rho)
{
    return alglib::bivariatenormalpdf(x, y, rho);
}

// double bivariatenormalcdf(const double x, const double y, const double rho, const xparams _xparams = alglib::xdefault);
double rb_bivariatenormalcdf(double x, double y, double rho)
{
    return alglib::bivariatenormalcdf(x, y, rho);
}

// double incompletebeta(const double a, const double b, const double x, const xparams _xparams = alglib::xdefault);
double rb_incompletebeta(double a, double b, double x)
{
    return alglib::incompletebeta(a, b, x);
}

// double invincompletebeta(const double a, const double b, const double y, const xparams _xparams = alglib::xdefault);
double rb_invincompletebeta(double a, double b, double y)
{
    return alglib::invincompletebeta(a, b, y);
}

// double studenttdistribution(const ae_int_t k, const double t, const xparams _xparams = alglib::xdefault);
double rb_studenttdistribution(alglib::ae_int_t k, double t)
{
    return alglib::studenttdistribution(k, t);
}

// double invstudenttdistribution(const ae_int_t k, const double p, const xparams _xparams = alglib::xdefault);
double rb_invstudenttdistribution(alglib::ae_int_t k, double p)
{
    return alglib::invstudenttdistribution(k, p);
}

// double fdistribution(const ae_int_t a, const ae_int_t b, const double x, const xparams _xparams = alglib::xdefault);
double rb_fdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double x)
{
    return alglib::fdistribution(a, b, x);
}

// double fcdistribution(const ae_int_t a, const ae_int_t b, const double x, const xparams _xparams = alglib::xdefault);
double rb_fcdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double x)
{
    return alglib::fcdistribution(a, b, x);
}

// double invfdistribution(const ae_int_t a, const ae_int_t b, const double y, const xparams _xparams = alglib::xdefault);
double rb_invfdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double y)
{
    return alglib::invfdistribution(a, b, y);
}

// double incompletegamma(const double a, const double x, const xparams _xparams = alglib::xdefault);
double rb_incompletegamma(double a, double x)
{
    return alglib::incompletegamma(a, x);
}

// double incompletegammac(const double a, const double x, const xparams _xparams = alglib::xdefault);
double rb_incompletegammac(double a, double x)
{
    return alglib::incompletegammac(a, x);
}

// double invincompletegammac(const double a, const double y0, const xparams _xparams = alglib::xdefault);
double rb_invincompletegammac(double a, double y0)
{
    return alglib::invincompletegammac(a, y0);
}

// double chisquaredistribution(const double v, const double x, const xparams _xparams = alglib::xdefault);
double rb_chisquaredistribution(double v, double x)
{
    return alglib::chisquaredistribution(v, x);
}

// double chisquarecdistribution(const double v, const double x, const xparams _xparams = alglib::xdefault);
double rb_chisquarecdistribution(double v, double x)
{
    return alglib::chisquarecdistribution(v, x);
}

// double invchisquaredistribution(const double v, const double y, const xparams _xparams = alglib::xdefault);
double rb_invchisquaredistribution(double v, double y)
{
    return alglib::invchisquaredistribution(v, y);
}

// double binomialdistribution(const ae_int_t k, const ae_int_t n, const double p, const xparams _xparams = alglib::xdefault);
double rb_binomialdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double p)
{
    return alglib::binomialdistribution(k, n, p);
}

// double binomialcdistribution(const ae_int_t k, const ae_int_t n, const double p, const xparams _xparams = alglib::xdefault);
double rb_binomialcdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double p)
{
    return alglib::binomialcdistribution(k, n, p);
}

// double invbinomialdistribution(const ae_int_t k, const ae_int_t n, const double y, const xparams _xparams = alglib::xdefault);
double rb_invbinomialdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double y)
{
    return alglib::invbinomialdistribution(k, n, y);
}

// double exponentialintegralei(const double x, const xparams _xparams = alglib::xdefault);
double rb_exponentialintegralei(double x)
{
    return alglib::exponentialintegralei(x);
}

// double exponentialintegralen(const double x, const ae_int_t n, const xparams _xparams = alglib::xdefault);
double rb_exponentialintegralen(double x, alglib::ae_int_t n)
{
    return alglib::exponentialintegralen(x, n);
}

//

// double poissondistribution(const ae_int_t k, const double m, const xparams _xparams = alglib::xdefault);
double rb_poissondistribution(alglib::ae_int_t k, double m)
{
    return alglib::poissondistribution(k, m);
}

// double poissoncdistribution(const ae_int_t k, const double m, const xparams _xparams = alglib::xdefault);
double rb_poissoncdistribution(alglib::ae_int_t k, double m)
{
    return alglib::poissoncdistribution(k, m);
}

// double invpoissondistribution(const ae_int_t k, const double y, const xparams _xparams = alglib::xdefault);
double rb_invpoissondistribution(alglib::ae_int_t k, double y)
{
    return alglib::invpoissondistribution(k, y);
}

// double beta(const double a, const double b, const xparams _xparams = alglib::xdefault);
double rb_beta(double a, double b)
{
    return alglib::beta(a, b);
}

// alglibmisc.h

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

extern "C" void Init_alglib()
{
    Module rb_mAlglib = define_module("Alglib");

    // Data_Type<alglib::hqrndstate> rb_cHqRndState =
    //     define_class_under<alglib::hqrndstate>(rb_mAlglib, "HqRndState")
    //     .define_constructor(Constructor<alglib::hqrndstate>())
    //     .define_method("initialize_copy", &alglib::hqrndstate::operator=);

    rb_mAlglib
        .define_module_function("sample_moments", &rb_samplemoments)
        .define_module_function("sample_mean", &rb_samplemean)
        .define_module_function("sample_variance", &rb_samplevariance)
        .define_module_function("sample_skewness", &rb_sampleskewness)
        .define_module_function("sample_kurtosis", &rb_samplekurtosis)
        .define_module_function("sample_adev", &rb_sampleadev)
        .define_module_function("sample_median", &rb_samplemedian)
        .define_module_function("sample_percentile", &rb_samplepercentile)
        .define_module_function("cov2", &rb_cov2)
        .define_module_function("pearson_corr2", &rb_pearsoncorr2)
        .define_module_function("spearman_corr2", &rb_spearmancorr2)
        .define_module_function("pearson_correlation_significance", &rb_pearsoncorrelationsignificance)
        .define_module_function("spearman_rank_correlation_significance", &rb_spearmanrankcorrelationsignificance)
        .define_module_function("jarque_bera_test", &rb_jarqueberatest)
        .define_module_function("f_test", &rb_ftest)
        .define_module_function("one_sample_variance_test", &rb_onesamplevariancetest)
        .define_module_function("wilcoxon_signed_rank_test", &rb_wilcoxonsignedranktest)
        .define_module_function("mann_whitney_u_test", &rb_mannwhitneyutest)
        .define_module_function("student_test_1", &rb_studentttest1)
        .define_module_function("student_test_2", &rb_studentttest2)
        .define_module_function("unequal_variance_t_test", &rb_unequalvariancettest)
        .define_module_function("hqrnd_normal", &rb_hqrndnormal)
        .define_module_function("hqrnd_normalv", &rb_hqrndnormalv)
        .define_module_function("gamma_function", &rb_gammafunction)
        .define_module_function("lngamma", &rb_lngamma)
        .define_module_function("error_function", &rb_errorfunction)
        .define_module_function("error_functionc", &rb_errorfunctionc)
        .define_module_function("normal_pdf", &rb_normalpdf)
        .define_module_function("normal_cdf", &rb_normalcdf)
        .define_module_function("inv_erf", &rb_inverf)
        .define_module_function("inv_normal_cdf", &rb_invnormalcdf)
        .define_module_function("bivariate_normal_pdf", &rb_bivariatenormalpdf)
        .define_module_function("bivariate_normal_cdf", &rb_bivariatenormalcdf)
        .define_module_function("incomplete_beta", &rb_incompletebeta)
        .define_module_function("inv_incomplete_beta", &rb_invincompletebeta)
        .define_module_function("student_t_distribution", &rb_studenttdistribution)
        .define_module_function("inv_student_t_distribution", &rb_invstudenttdistribution)
        .define_module_function("f_distribution", &rb_fdistribution)
        .define_module_function("fc_distribution", &rb_fcdistribution)
        .define_module_function("inv_f_distribution", &rb_invfdistribution)
        .define_module_function("incomplete_gamma", &rb_incompletegamma)
        .define_module_function("incomplete_gamma_c", &rb_incompletegammac)
        .define_module_function("inv_incomplete_gamma_c", &rb_invincompletegammac)
        .define_module_function("chi_square_distribution", &rb_chisquaredistribution)
        .define_module_function("chi_square_c_distribution", &rb_chisquarecdistribution)
        .define_module_function("inv_chi_square_distribution", &rb_invchisquaredistribution)
        .define_module_function("binomial_distribution", &rb_binomialdistribution)
        .define_module_function("binomial_c_distribution", &rb_binomialcdistribution)
        .define_module_function("inv_binomial_distribution", &rb_invbinomialdistribution)
        .define_module_function("exponential_integralei", &rb_exponentialintegralei)
        .define_module_function("exponential_integralen", &rb_exponentialintegralen)
        .define_module_function("poisson_distribution", &rb_poissondistribution)
        .define_module_function("poisson_c_distribution", &rb_poissoncdistribution)
        .define_module_function("inv_poisson_distribution", &rb_invpoissondistribution)
        .define_module_function("beta", &rb_beta);
}