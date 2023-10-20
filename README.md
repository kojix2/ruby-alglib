# ruby-alglib

- `statistics.h` of [ALGLIB](https://www.alglib.net/) for Ruby.
- ALGLIB is a numerical analysis and data processing library. This repository provides bindings primarily for statistics.

## Installation

From source code:

```sh
git clone https://github.com/kojix2/ruby-alglib
cd ruby-alglib
bundle install
rake ext:alglib # Download ALGLIB from https://www.alglib.net/ and extract to ext/alglib.
rake compile
rake install
```

- Windows is not supported.

## Usage

`sample_moments` `sample_mean` `sample_variance` `sample_skewness` `sample_kurtosis` `sample_adev` `sample_median` `sample_percentile` `cov2` `pearson_corr2` `spearman_corr2` `pearson_correlation_significance` `spearman_rank_correlation_significance` `jarque_bera_test` `f_test` `one_sample_variance_test` `wilcoxon_signed_rank_test` `mann_whitney_u_test` `student_test_1` `student_test_2` `unequal_variance_t_test`

## Development

Not-To-Do List

- Creating namespaces under Alglib. (e.g. Alglib::Statistics)
- Trying to implement all functions even if you do not plan to use them.
- Adding features that will require frequent maintenance.
- Enforcing the above policies on forked repos.

## License

- ruby-alglib itself is distributed under the **MIT** license.
- However, [ALGLIB Free Edition](https://www.alglib.net/download.php) is under the **GPL** or Personal/Academic license.
- Please read [FAQ](https://www.alglib.net/faq.php) carefully before you use ALGLIB to understand what is allowed in the free version.
- Theoretically, ruby-alglib should work with the commercial version. That is why it is MIT. But we have not verified this.
