# ruby-alglib

[![test](https://github.com/kojix2/ruby-alglib/actions/workflows/ci.yml/badge.svg)](https://github.com/kojix2/ruby-alglib/actions/workflows/ci.yml)
[![Gem Version](https://badge.fury.io/rb/alglib4.svg)](https://badge.fury.io/rb/alglib4)

- [ALGLIB](https://www.alglib.net/) for Ruby.
- ALGLIB is a numerical analysis and data processing library. This repository provides bindings primarily for statistics.

## Installation

From source code:

```sh
git clone https://github.com/kojix2/ruby-alglib
cd ruby-alglib
bundle install
rake ext:alglib # Download ALGLIB Free Edition from https://www.alglib.net/ and extract to ext/alglib.
rake compile
rake install
```

- Note that the license of ALGLIB Free Edition is GPL or Personal/Academic license.
- If you want to use ALGLIB in a commercial application, you will need to purchase a commercial license.
  - [Can I use ALGLIB Free Edition in a commercial application which runs on server?](https://www.alglib.net/faq.php#6bca163136cda10b16de68704cbea625)
- You can also use the Commercial Edition of ALGLIB. In that case, you need to replace the files in `ext/alglib` with the files in the Commercial Edition.
- Windows is not supported.

## Usage

### Supported Statistical Functions

#### Special Functions (from alglib_specialfunctions.h)

- `gamma_function`
- `lngamma`
- `error_function`
- `error_functionc`
- `normal_pdf`
- `normal_cdf`
- `inv_erf`
- `inv_normal_cdf`
- `bivariate_normal_pdf`
- `bivariate_normal_cdf`
- `incomplete_beta`
- `inv_incomplete_beta`
- `student_t_distribution`
- `inv_student_t_distribution`
- `f_distribution`
- `fc_distribution`
- `inv_f_distribution`
- `incomplete_gamma`
- `incomplete_gamma_c`
- `inv_incomplete_gamma_c`
- `chi_square_distribution`
- `chi_square_c_distribution`
- `inv_chi_square_distribution`
- `binomial_distribution`
- `binomial_c_distribution`
- `inv_binomial_distribution`
- `exponential_integralei`
- `exponential_integralen`
- `poisson_distribution`
- `poisson_c_distribution`
- `inv_poisson_distribution`
- `beta`

#### Data Analysis Functions (from alglib_dataanalysis.h)

- `pca_build_basis`

#### Miscellaneous Functions (from alglib_alglibmisc.h)

- `hqrnd_normal`
- `hqrnd_normalv`

#### 1D Array Functions

- `sample_moments`
- `sample_mean`
- `sample_variance`
- `sample_skewness`
- `sample_kurtosis`
- `sample_adev`
- `sample_median`
- `sample_percentile`
- `cov2`
- `pearson_corr2`
- `spearman_corr2`

#### 2D Array / Matrix Functions

- `covm`, `covm_with_size`
- `pearsoncorrm`, `pearsoncorrm_with_size`
- `spearmancorrm`, `spearmancorrm_with_size`
- `covm2`, `covm2_with_size`
- `pearsoncorrm2`, `pearsoncorrm2_with_size`
- `spearmancorrm2`, `spearmancorrm2_with_size`
- `rankdata`, `rankdata_with_size`
- `rankdatacentered`, `rankdatacentered_with_size`

#### Statistical Tests

- `pearson_correlation_significance`
- `spearman_rank_correlation_significance`
- `jarque_bera_test`
- `f_test`
- `one_sample_variance_test`
- `wilcoxon_signed_rank_test`
- `mann_whitney_u_test`
- `student_test_1`
- `student_test_2`
- `unequal_variance_t_test`

### Example

```ruby
require 'alglib'

# 1D statistics
arr = [1.0, 2.0, 3.0, 4.0]
mean = Alglib.sample_mean(arr)
variance = Alglib.sample_variance(arr)
moments = Alglib.sample_moments(arr) # => { "mean" => ..., "variance" => ..., ... }

# 2D statistics
mat = [[1, 2], [3, 4], [5, 6]]
cov = Alglib.covm(mat)
corr = Alglib.pearsoncorrm(mat)
ranked = Alglib.rankdata(mat)
centered_ranked = Alglib.rankdatacentered(mat)

# with_size version
cov2 = Alglib.covm_with_size(mat, 3, 2)

# Statistical test
result = Alglib.pearson_correlation_significance(0.8, 10) # => { "bothtails" => ..., ... }
```

### Testing

- This project includes comprehensive tests for all statistical functions, special functions, data analysis, and miscellaneous utilities.
- All results are compared with R's standard statistical functions (e.g., `mean`, `var`, `cor`, `cov`, `rank`, etc.) for correctness.
- Both 1D and 2D array functions, all with_size variants, and special/data analysis/miscellaneous functions are covered by the test suite.
- Rank-related functions are compared as sets due to possible differences in tie-breaking order between ALGLIB and R.
- See `test/statistics_test.rb`, `test/dataanalysis_test.rb`, and other test files for details.

## Development

### Not-To-Do List

- Creating namespaces under Alglib. (e.g. Alglib::Statistics)
- Trying to implement all functions even if you do not plan to use them.
- Adding features that will require frequent maintenance.
- Enforcing the above policies on forked repos.

### Rice - C++ binding

We use [Rice](https://github.com/ruby-rice/rice) to create Ruby's C++ binding.

### Ruby Gem Release

1. Update the version number in `lib/alglib/version.rb`.
2. Clean up the extension files:

```sh
rake ext:clean_alglib
```

3. Download the ALGLIB Free Edition:

```sh
rake ext:alglib
```

4. Publish the `alglib4` gem:

```sh
rake release
```

### Call for committers and owners

This project is looking for a committer and an owner. The original developer, kojix2, is not familiar with the C++ programming language or mathematical calculations. If there is a suitable owner, kojix2 will gladly transfer this project (provided that kojix2 can maintain commit rights).

## License

- ruby-alglib itself (the code in this repository) is distributed under the **MIT** license.
- However, [ALGLIB for C++ Free Edition](https://www.alglib.net/download.php) is under the **GPL 2+** license.
- [The algblib4 gem](https://rubygems.org/gems/alglib4) distributed with the RubyGem server is **GPL 2+** licensed because it contains ALGLIB for C++ Free Edition code.
- Please read [FAQ](https://www.alglib.net/faq.php) carefully before you use ALGLIB to understand what is allowed in the free version.
  - [Can I use ALGLIB Free Edition in a commercial application which runs on server?](https://www.alglib.net/faq.php#6bca163136cda10b16de68704cbea625)
    > You can, but there is at least one reason to buy commercial license. Everything is OK while it is just running on your server. But any action connected with distribution - selling, sublicensing, transferring to someone under nondisclosure agreement - will trigger copyleft clause. So it is safer and more convenient to buy commercial license.
- Theoretically, ruby-alglib should work with the commercial version. That is why it is MIT. But we have not verified this.
