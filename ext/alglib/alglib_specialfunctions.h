#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "specialfunctions.h"
#include "alglib_array_converters.h"
#include "alglib_utils.h"

using namespace Rice;

double rb_gammafunction(double x);
Array rb_lngamma(double x);
double rb_errorfunction(double x);
double rb_errorfunctionc(double x);
double rb_normalpdf(double x);
double rb_normalcdf(double x);
double rb_inverf(double e);
double rb_invnormalcdf(double y0);
double rb_bivariatenormalpdf(double x, double y, double rho);
double rb_bivariatenormalcdf(double x, double y, double rho);
double rb_incompletebeta(double a, double b, double x);
double rb_invincompletebeta(double a, double b, double y);
double rb_studenttdistribution(alglib::ae_int_t k, double t);
double rb_invstudenttdistribution(alglib::ae_int_t k, double p);
double rb_fdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double x);
double rb_fcdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double x);
double rb_invfdistribution(alglib::ae_int_t a, alglib::ae_int_t b, double y);
double rb_incompletegamma(double a, double x);
double rb_incompletegammac(double a, double x);
double rb_invincompletegammac(double a, double y0);
double rb_chisquaredistribution(double v, double x);
double rb_chisquarecdistribution(double v, double x);
double rb_invchisquaredistribution(double v, double y);
double rb_binomialdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double p);
double rb_binomialcdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double p);
double rb_invbinomialdistribution(alglib::ae_int_t k, alglib::ae_int_t n, double y);
double rb_exponentialintegralei(double x);
double rb_exponentialintegralen(double x, alglib::ae_int_t n);

double rb_poissondistribution(alglib::ae_int_t k, double m);
double rb_poissoncdistribution(alglib::ae_int_t k, double m);
double rb_invpoissondistribution(alglib::ae_int_t k, double y);
double rb_beta(double a, double b);