#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <algorithm>
// #include "numo.hpp"
#include "alglib.h"

using namespace Rice;

extern "C" void Init_alglib()
{
    Module rb_mAlglib = define_module("Alglib");

    // Data_Type<alglib::hqrndstate> rb_cHqRndState =
    //     define_class_under<alglib::hqrndstate>(rb_mAlglib, "HqRndState")
    //     .define_constructor(Constructor<alglib::hqrndstate>())
    //     .define_method("initialize_copy", &alglib::hqrndstate::operator=);

    Data_Type<alglib::real_1d_array> rb_cReal1DArray =
        define_class_under<alglib::real_1d_array>(rb_mAlglib, "Real1DArray")
            .define_constructor(Constructor<alglib::real_1d_array>())
            .define_method("getcontent", static_cast<double *(alglib::real_1d_array::*)()>(&alglib::real_1d_array::getcontent));

    Data_Type<alglib::integer_1d_array> rb_cInteger1DArray =
        define_class_under<alglib::integer_1d_array>(rb_mAlglib, "Integer1DArray")
            .define_constructor(Constructor<alglib::integer_1d_array>())
            .define_method("getcontent", static_cast<alglib::ae_int_t *(alglib::integer_1d_array::*)()>(&alglib::integer_1d_array::getcontent));

    Data_Type<alglib::real_2d_array> rb_cReal2DArray =
        define_class_under<alglib::real_2d_array>(rb_mAlglib, "Real2DArray")
            .define_constructor(Constructor<alglib::real_2d_array>())
            .define_method("getcontent", static_cast<double *(alglib::real_2d_array::*)(alglib::ae_int_t)>(&alglib::real_2d_array::operator[]));

    Data_Type<alglib::integer_2d_array> rb_cInteger2DArray =
        define_class_under<alglib::integer_2d_array>(rb_mAlglib, "Integer2DArray")
            .define_constructor(Constructor<alglib::integer_2d_array>())
            .define_method("getcontent", static_cast<alglib::ae_int_t *(alglib::integer_2d_array::*)(alglib::ae_int_t)>(&alglib::integer_2d_array::operator[]));

    rb_mAlglib
        .define_module_function("ruby_array_to_real_1d_array", &ruby_array_to_real_1d_array)
        .define_module_function("ruby_array_to_integer_1d_array", &ruby_array_to_integer_1d_array)
        .define_module_function("ruby_array_to_real_2d_array", &ruby_array_to_real_2d_array)
        .define_module_function("ruby_array_to_integer_2d_array", &ruby_array_to_integer_2d_array)
        .define_module_function("real_1d_array_to_ruby_array", &real_1d_array_to_ruby_array)
        .define_module_function("real_2d_array_to_ruby_array", &real_2d_array_to_ruby_array)
        .define_module_function("integer_2d_array_to_ruby_array", &integer_2d_array_to_ruby_array)
        .define_module_function("integer_1d_array_to_ruby_array", &integer_1d_array_to_ruby_array)
        .define_module_function("pca_build_basis", &rb_pcabuildbasis);

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
        // 2D array/matrix statistical functions
        .define_module_function("covm", &rb_covm)
        .define_module_function("covm_with_size", &rb_covm_with_size)
        .define_module_function("pearsoncorrm", &rb_pearsoncorrm)
        .define_module_function("pearsoncorrm_with_size", &rb_pearsoncorrm_with_size)
        .define_module_function("spearmancorrm", &rb_spearmancorrm)
        .define_module_function("spearmancorrm_with_size", &rb_spearmancorrm_with_size)
        .define_module_function("covm2", &rb_covm2)
        .define_module_function("covm2_with_size", &rb_covm2_with_size)
        .define_module_function("pearsoncorrm2", &rb_pearsoncorrm2)
        .define_module_function("pearsoncorrm2_with_size", &rb_pearsoncorrm2_with_size)
        .define_module_function("spearmancorrm2", &rb_spearmancorrm2)
        .define_module_function("spearmancorrm2_with_size", &rb_spearmancorrm2_with_size)
        .define_module_function("rankdata", &rb_rankdata)
        .define_module_function("rankdata_with_size", &rb_rankdata_with_size)
        .define_module_function("rankdatacentered", &rb_rankdatacentered)
        .define_module_function("rankdatacentered_with_size", &rb_rankdatacentered_with_size)
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
