#include "alglib_specialfunctions.h"

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
