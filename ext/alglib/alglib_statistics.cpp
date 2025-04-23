#include "alglib_statistics.h"

// 1D array statistical functions
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

double rb_samplemean(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplemean(a, x.size());
}

double rb_samplevariance(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplevariance(a, x.size());
}

double rb_sampleskewness(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::sampleskewness(a, x.size());
}

double rb_samplekurtosis(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    return alglib::samplekurtosis(a, x.size());
}

double rb_sampleadev(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    double adev;
    alglib::sampleadev(a, x.size(), adev);
    return adev;
}

double rb_samplemedian(Array x)
{
    auto a = ruby_array_to_real_1d_array(x);
    double median;
    alglib::samplemedian(a, x.size(), median);
    return median;
}

double rb_samplepercentile(Array x, double p)
{
    auto a = ruby_array_to_real_1d_array(x);
    double v;
    alglib::samplepercentile(a, x.size(), p, v);
    return v;
}

double rb_cov2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::cov2(a, b, x.size());
}

double rb_pearsoncorr2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::pearsoncorr2(a, b, x.size());
}

double rb_spearmancorr2(Array x, Array y)
{
    check_size(x, y);
    auto a = ruby_array_to_real_1d_array(x);
    auto b = ruby_array_to_real_1d_array(y);
    return alglib::spearmancorr2(a, b, x.size());
}

// 2D array/matrix statistical functions

// Covariance matrix
Array rb_covm(Array x)
{
    auto a = ruby_array_to_real_2d_array(x);
    int n = a.rows();
    int m = a.cols();
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::covm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_covm_with_size(Array x, int n, int m)
{
    auto a = ruby_array_to_real_2d_array(x);
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::covm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

// Pearson correlation matrix
Array rb_pearsoncorrm(Array x)
{
    auto a = ruby_array_to_real_2d_array(x);
    int n = a.rows();
    int m = a.cols();
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::pearsoncorrm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_pearsoncorrm_with_size(Array x, int n, int m)
{
    auto a = ruby_array_to_real_2d_array(x);
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::pearsoncorrm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

// Spearman correlation matrix
Array rb_spearmancorrm(Array x)
{
    auto a = ruby_array_to_real_2d_array(x);
    int n = a.rows();
    int m = a.cols();
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::spearmancorrm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_spearmancorrm_with_size(Array x, int n, int m)
{
    auto a = ruby_array_to_real_2d_array(x);
    alglib::real_2d_array c;
    c.setlength(m, m);
    alglib::spearmancorrm(a, n, m, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

// Cross-covariance matrix
Array rb_covm2(Array x, Array y)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    int n = a.rows();
    int m1 = a.cols();
    int m2 = b.cols();
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::covm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_covm2_with_size(Array x, Array y, int n, int m1, int m2)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::covm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

// Pearson cross-correlation matrix
Array rb_pearsoncorrm2(Array x, Array y)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    int n = a.rows();
    int m1 = a.cols();
    int m2 = b.cols();
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::pearsoncorrm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_pearsoncorrm2_with_size(Array x, Array y, int n, int m1, int m2)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::pearsoncorrm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

// Spearman cross-correlation matrix
Array rb_spearmancorrm2(Array x, Array y)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    int n = a.rows();
    int m1 = a.cols();
    int m2 = b.cols();
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::spearmancorrm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_spearmancorrm2_with_size(Array x, Array y, int n, int m1, int m2)
{
    auto a = ruby_array_to_real_2d_array(x);
    auto b = ruby_array_to_real_2d_array(y);
    alglib::real_2d_array c;
    c.setlength(m1, m2);
    alglib::spearmancorrm2(a, b, n, m1, m2, c, alglib::xdefault);
    return real_2d_array_to_ruby_array(c);
}

Array rb_rankdata(Array xy)
{
    auto a = ruby_array_to_real_2d_array(xy);
    int npoints = a.rows();
    int nfeatures = a.cols();
    alglib::rankdata(a, npoints, nfeatures, alglib::xdefault);
    return real_2d_array_to_ruby_array(a);
}

Array rb_rankdata_with_size(Array xy, int npoints, int nfeatures)
{
    auto a = ruby_array_to_real_2d_array(xy);
    alglib::rankdata(a, npoints, nfeatures, alglib::xdefault);
    return real_2d_array_to_ruby_array(a);
}

Array rb_rankdatacentered(Array xy)
{
    auto a = ruby_array_to_real_2d_array(xy);
    int npoints = a.rows();
    int nfeatures = a.cols();
    alglib::rankdatacentered(a, npoints, nfeatures, alglib::xdefault);
    return real_2d_array_to_ruby_array(a);
}

Array rb_rankdatacentered_with_size(Array xy, int npoints, int nfeatures)
{
    auto a = ruby_array_to_real_2d_array(xy);
    alglib::rankdatacentered(a, npoints, nfeatures, alglib::xdefault);
    return real_2d_array_to_ruby_array(a);
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

Hash rb_pearsoncorrelationsignificance(double r, alglib::ae_int_t n)
{
    return perform_test(alglib::pearsoncorrelationsignificance, r, n);
}

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
