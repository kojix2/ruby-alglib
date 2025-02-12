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

`sample_moments` `sample_mean` `sample_variance` `sample_skewness` `sample_kurtosis` `sample_adev` `sample_median` `sample_percentile` `cov2` `pearson_corr2` `spearman_corr2` `pearson_correlation_significance` `spearman_rank_correlation_significance` `jarque_bera_test` `f_test` `one_sample_variance_test` `wilcoxon_signed_rank_test` `mann_whitney_u_test` `student_test_1` `student_test_2` `unequal_variance_t_test`

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
