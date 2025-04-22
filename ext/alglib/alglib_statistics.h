#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include "statistics.h"
#include "alglib_converters.h"
#include "alglib_utils.h"

using namespace Rice;

Hash rb_samplemoments(Array x);
double rb_samplemean(Array x);
double rb_samplevariance(Array x);
double rb_sampleskewness(Array x);
double rb_samplekurtosis(Array x);
double rb_sampleadev(Array x);
double rb_samplemedian(Array x);
double rb_samplepercentile(Array x, double p);
double rb_cov2(Array x, Array y);
double rb_pearsoncorr2(Array x, Array y);
double rb_spearmancorr2(Array x, Array y);

Hash rb_pearsoncorrelationsignificance(double r, alglib::ae_int_t n);
Hash rb_spearmanrankcorrelationsignificance(double r, alglib::ae_int_t n);
Hash rb_jarqueberatest(Array x);
Hash rb_ftest(Array x, Array y);
Hash rb_onesamplevariancetest(Array x, double variance);
Hash rb_wilcoxonsignedranktest(Array x, double e);
Hash rb_mannwhitneyutest(Array x, Array y);
Hash rb_studentttest1(Array x, double mean);
Hash rb_studentttest2(Array x, Array y);
Hash rb_unequalvariancettest(Array x, Array y);
